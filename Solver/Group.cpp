#include "Group.h"
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace minobr::kingard
{
    Group::Group(const std::string& name) : name_group(name){}

    std::shared_ptr<Group> Group::create(const std::string& name)
    {
        return std::shared_ptr<Group>(new Group(name));
    }

    void Group::add_teacher(const std::weak_ptr<Teacher>& educator) {
        
        if (auto sharedEducator = educator.lock()) {
            teacher = sharedEducator; 
        }
        else {
            throw std::invalid_argument("Указанный учитель недействителен или не существует");
        }
    }

    void Group::add_child(const std::shared_ptr<Baby>& child)
    {
        babies.push_back(child);
        child->set_group(this);
    }

    std::optional<std::shared_ptr<Baby>> Group::get_baby_at(size_t index) const
    {
        if (index < babies.size()) {
            return babies[index];
        }
        return std::nullopt;
    }

    const std::vector<std::shared_ptr<Baby>>& Group::get_children() const
    {
        return babies;
    }

    std::shared_ptr<Teacher> Group::get_teacher() const
    {
        return teacher;
    }

    void Group::remove_child(const std::shared_ptr<Baby>& child) {
        if (!child) {
            throw std::invalid_argument("Передан пустой указатель на ребенка");
        }

        auto it = std::find(babies.begin(), babies.end(), child);
        if (it != babies.end()) {
            babies.erase(it);
            child->set_group(nullptr);
        }
    }

    double Group::male_female_ratio() const
    {
        if (babies.empty()) {
            return 0.0;
        }

        size_t male_count = std::count_if(babies.begin(), babies.end(),
            [](const std::shared_ptr<Baby>& baby) { return baby->get_gender() == 'М'; });

        size_t female_count = babies.size() - male_count;
        if (female_count == 0) {
            return INFINITY;
        }

        return static_cast<double>(male_count) / female_count * 100.0;
    }

    std::vector<std::shared_ptr<Baby>> Group::get_children_by_age(int inputed_age) const
    {
        std::vector<std::shared_ptr<Baby>> filtered_children;
        for (const auto& baby : babies) {
            if (baby->get_age() == inputed_age) {
                filtered_children.push_back(baby);
            }
        }
        return filtered_children;
    }

    std::string Group::to_string() const {
        std::ostringstream oss;
        oss << "Group name: " << name_group << ", Teacher: "
            << (teacher ? teacher->get_fio() : "None");
        return oss.str();
    }
}
