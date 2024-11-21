#include "Group.h"
#include <sstream>

namespace minobr::kingard
{
	Group::Group(std::string& name, Teacher* educator)
		: name_group(name), teacher(educator) {
	}

	void Group::add_child(std::unique_ptr<Baby> child) {
		babies.push_back(std::move(child));
	}
	
	const std::vector<std::unique_ptr<Baby>>& Group::get_children() const {
		return babies;
	}

	Teacher* Group::get_teacher() const {
		return teacher;
	}

	double Group::male_female_ratio() const {
		if (babies.empty()) {
			return 0.0;
		}

		int male_count = 0;
		for (const auto& baby : babies) {
			if (baby->gender == 'М') {
				male_count++;
			}
		}

		int female_count = babies.size() - male_count;
		if (female_count == 0)
		{
			return INFINITY;
		}
		return (male_count / female_count) * 100;
	}

	const std::vector<std::unique_ptr<Baby>>& Group::get_children_by_age(int inputed_age) {
		static std::vector<std::unique_ptr<Baby>> filtered_children;
		filtered_children.clear();

		for (const auto& baby : babies) {
			if (baby->age == inputed_age) { 
				filtered_children.push_back(std::make_unique<Baby>(*baby));
			}
		}

		return filtered_children;
	}

	std::string Group::to_string() const {
		std::ostringstream oss;

		oss << "Имя группы: " << name_group << "\n";

		oss << "Воспитатель: " << (get_teacher()->fio) << "\n";

		oss << "Соотношение мальчиков и девочек(в %): " << male_female_ratio() << "\n";
	}
}
