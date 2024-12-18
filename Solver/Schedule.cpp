#include "Schedule.h"
#include "Group.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

namespace minobr::kingard {

    std::chrono::minutes parseTimeToMinutes(const std::string& time) {
        std::istringstream timeStream(time);
        int hours, minutes;
        char delimiter;

        timeStream >> hours >> delimiter >> minutes;

        if (timeStream.fail() || delimiter != ':' || hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
            throw std::invalid_argument("Неверный формат времени. Ожидалось HH:MM");
        }

        return std::chrono::hours(hours) + std::chrono::minutes(minutes);
    }

    ScheduleEntry::ScheduleEntry(const std::string& day, const std::string& time)
        : day(day), time(parseTimeToMinutes(time)) {}

    std::unique_ptr<Schedule> Schedule::create() {
        return std::make_unique<Schedule>();
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
        group = shared_from_this();
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
        std::ostringstream oss;

        if (entries.empty()) {
            oss << "Расписание пусто.\n";
            return oss.str();
        }

        
        for (const auto& entry : entries) {
            if (entry) {
                
                oss << "День: " << entry->day << "\n";

                
                if (entry->group) {
                    oss << "Группа: " << entry->group->to_string() << "\n";
                }
                else {
                    oss << "Группа: не указана\n";
                }

                
                oss << "Занятие: " << entry->activity << "\n";

                
                auto duration = entry->time; 
                int hours = std::chrono::duration_cast<std::chrono::hours>(duration).count();
                int minutes = std::chrono::duration_cast<std::chrono::minutes>(duration % std::chrono::hours(1)).count();
                oss << "Время: " << std::setfill('0') << std::setw(2) << hours
                    << ":" << std::setfill('0') << std::setw(2) << minutes << "\n";
            }
        }

        return oss.str();
    }
}
