#include "Schedule.h"

namespace minobr::kingard
{
	void Schedule::set_schedule(const std::string& day, const std::string& inputed_group_name, const std::vector<std::string>& activities) {
		group_schedule[day + "_" + inputed_group_name] = activities;
	}

	const std::vector<std::string>& Schedule::get_group_schedule(const std::string& day, const std::string& inputed_group_name) const {
		static const std::vector<std::string> empty;
		auto it = group_schedule.find(day + "_" + inputed_group_name);
		return it != group_schedule.end() ? it->second : empty;
	}

	std::string Schedule::to_string() const {
		std::ostringstream oss;
		for (const auto& [key, activities] : group_schedule) {
			oss << "Key: " << key << "\nActivities:\n";
			for (const auto& activity : activities) {
				oss << "  - " << activity << "\n";
			}
		}
		return oss.str();
	}
}