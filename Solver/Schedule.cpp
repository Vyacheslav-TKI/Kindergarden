#include "Schedule.h"

namespace minobr::kingard
{
	void Schedule::set_schedule(const std::string& day, const std::shared_ptr<Group>& group, const std::vector<std::string>& activities) {
		if (!group) {
			throw std::invalid_argument("Не найдено такой группы");
		}

		
		const std::string& group_name = group->to_string(); 
		group_schedule[day + "_" + group_name] = activities;
	}

	const std::vector<std::string>& Schedule::get_group_schedule(const std::string& day, const std::shared_ptr<Group>& group) const {
		if (!group) {
			throw std::invalid_argument("Не найдено такой группы");
		}

		const std::string& group_name = group->to_string(); 
		const auto& key = day + "_" + group_name;

		auto it = group_schedule.find(key);
		if (it != group_schedule.end()) {
			return it->second;
		}

		static const std::vector<std::string> empty_schedule;
		return empty_schedule;
	}

	std::string Schedule::to_string() const {
		std::ostringstream oss;

		for (const auto& [key, activities] : group_schedule) {
			oss << "День и группа " << key << "\n";
			oss << "Занятия:\n";
			for (const auto& activity : activities) {
				oss << "  - " << activity << "\n";
			}
		}

		return oss.str();
	}
}