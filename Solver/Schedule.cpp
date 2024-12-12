#include "Schedule.h"
#include <iomanip>

namespace minobr::kingard
{
    ScheduleEntry::ScheduleEntry(const std::string& day, const std::chrono::system_clock::time_point& time) : day(day), time(time) {}

    std::shared_ptr<ScheduleEntry> Schedule::createEntry(const std::string& day, const std::string& time)
    {
        auto newEntry = std::make_shared<ScheduleEntry>(day, time);
        entries.push_back(newEntry);
        return newEntry;
    }

    void Schedule::addActivityToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::string& activity)
    {
        entry->activity = activity;
    }

    std::vector<std::string> Schedule::getActivitiesForGroup(const std::shared_ptr<Group>& group, const std::string& day) const
    {
        std::vector<std::string> activities;
        for (const auto& entry : entries) {
            if (entry && entry->group == group && entry->day == day) {
                activities.push_back(entry->activity);
            }
        }
        return activities;
    }

    void Schedule::removeEntry(const std::shared_ptr<Group>& group, const std::string& day, const std::chrono::system_clock::time_point& time)
    {
        entries.erase(std::remove_if(entries.begin(), entries.end(),
            [&](const std::shared_ptr<ScheduleEntry>& entry) {
                return entry && entry->group == group && entry->day == day && entry->time == time;
            }), entries.end());
    }

    std::string Schedule::to_string() const
    {
        std::stringstream ss;
        for (const auto& entry : entries) {
            if (entry) {
                ss << "Group: " << entry->group << ", Activity: " << entry->activity << ", Day: " << entry->day << ", Time: " << entry->time << "\n";
            }
        }
        return ss.str();
    }
}