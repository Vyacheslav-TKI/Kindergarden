#include "Schedule.h"
#include "Group.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace minobr::kingard {

    ScheduleEntry::ScheduleEntry(const std::string& day, const std::chrono::system_clock::time_point& time)
        : day(day), time(time) {
    }

    std::shared_ptr<ScheduleEntry> Schedule::createEntry(const std::string& day, const std::string& time) {
        
        int hours, minutes;
        char delimiter;
        std::istringstream ss(time);
        ss >> hours >> delimiter >> minutes;

        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm tm;
        localtime_s(&tm, &t);

        tm.tm_hour = hours;
        tm.tm_min = minutes;

        auto time_point = std::chrono::system_clock::from_time_t(std::mktime(&tm));

        auto newEntry = std::make_shared<ScheduleEntry>(day, time_point);
        entries.push_back(newEntry);
        return newEntry;
    }

    void Schedule::addGroupToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::shared_ptr<Group>& group) {
        entry->group = group;
    }

    void Schedule::addActivityToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::string& activity) {
        entry->activity = activity;
    }

    std::vector<std::string> Schedule::getActivitiesForGroup(const std::shared_ptr<Group>& group, const std::string& day) const {
        std::vector<std::string> activities;
        for (const auto& entry : entries) {
            if (entry && entry->group == group && entry->day == day) {
                activities.push_back(entry->activity);
            }
        }
        return activities;
    }

    void Schedule::removeEntry(const std::shared_ptr<Group>& group, const std::string& day, const std::chrono::system_clock::time_point& time) {
        entries.erase(std::remove_if(entries.begin(), entries.end(),
            [&](const std::shared_ptr<ScheduleEntry>& entry) {
                return entry && entry->group == group && entry->day == day && entry->time == time;
            }),
            entries.end());
    }

    std::string Schedule::to_string() const {
        std::ostringstream ss;
        for (const auto& entry : entries) {
            if (entry) {
                auto t = std::chrono::system_clock::to_time_t(entry->time);
                std::tm tm;
                localtime_s(&tm, &t);

                ss << "Group: " << (entry->group ? entry->group->to_string() : "None")
                    << ", Activity: " << entry->activity
                    << ", Day: " << entry->day
                    << ", Time: " << std::put_time(&tm, "%H:%M") << "\n";
            }
        }
        return ss.str();
    }
}
