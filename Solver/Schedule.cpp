#include "Schedule.h"
#include <iomanip>

namespace minobr::kingard
{
	void Schedule::add_entry(const std::string& group, const std::string& day, const std::string& activity) {
		entries.push_back({ group, day, activity });
	}

	void Schedule::remove_entry(const std::string& group, const std::string& day) {
		entries.erase(std::remove_if(entries.begin(), entries.end(),
			[&](const Schedule_entry& entry) 
			{
				return entry.group == group && entry.day == day;
			}), entries.end());
	}

	std::vector<std::string> Schedule::get_activities_for_group(const std::string& group, const std::string& day) const {
		std::vector<std::string> activities;
		for (const auto& entry : entries) {
			if (entry.group == group && entry.day == day) {
				activities.push_back(entry.activity);
			}
		}
		return activities;
	}

    std::string Schedule::to_string() const {
        std::stringstream ss;
        if (entries.empty()) {
            return "Расписание пустое"; 
        }

        
        size_t max_group_width = 0;
        size_t max_day_width = 0;
        size_t max_activity_width = 0;

        for (const auto& entry : entries) {
            max_group_width = std::max(max_group_width, entry.group.length());
            max_day_width = std::max(max_day_width, entry.day.length());
            max_activity_width = std::max(max_activity_width, entry.activity.length());
        }

        
        ss << std::left << std::setw(max_group_width) << "Group" << " | "
            << std::setw(max_day_width) << "Day" << " | "
            << "Activity" << "\n";
        ss << std::string(max_group_width + max_day_width + max_activity_width + 7, '-') << "\n"; 

        
        for (const auto& entry : entries) {
            ss << std::left << std::setw(max_group_width) << entry.group << " | "
                << std::setw(max_day_width) << entry.day << " | "
                << entry.activity << "\n";
        }

        return ss.str();
    }

}