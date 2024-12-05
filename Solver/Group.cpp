#include "Group.h"
#include <sstream>

namespace minobr::kingard
{
	Group::Group(const std::string& name, const std::shared_ptr<Teacher>& educator)
		: name_group(name), teacher(educator) {
	}

	void Group::add_child(const std::shared_ptr<Baby>& child) {
		babies.push_back(child);
		child->set_group(shared_from_this());
	}
	
	std::optional<std::shared_ptr<Baby>> Group::get_baby_at() const
	{
		if (!babies.empty()) {
			return babies[0];
		}
		else {
			return std::nullopt; 
		}
	}

	const std::vector<std::shared_ptr<Baby>>& Group::get_children() const {
		return babies;
	}

	std::shared_ptr<Teacher> Group::get_teacher() const {
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

	std::vector<std::shared_ptr<Baby>> Group::get_children_by_age(int inputed_age) const {
		std::vector<std::shared_ptr<Baby>> filtered_children;

		auto it = babies.begin();
		while ((it = std::find_if(it, babies.end(), [inputed_age](const std::shared_ptr<Baby>& baby) 
			{
				return baby->age() == inputed_age;
			})) != babies.end()) 
		{
			filtered_children.push_back(*it); 
			++it;
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
