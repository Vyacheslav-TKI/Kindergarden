#include "Teacher.h"
#include "Group.h"
#include <stdexcept>

namespace minobr::kingard
{
    Teacher::Teacher(const std::string& fio_inputed, char gender_inputed, int age_inputed, size_t id_inputed)
        : Human(age_inputed, fio_inputed, gender_inputed), id(id_inputed) {}

    std::shared_ptr<Teacher> Teacher::create(const std::string& fio_inputed, char gender_inputed, int age_inputed, size_t id_inputed)
    {
        return std::shared_ptr<Teacher>(new Teacher(fio_inputed, gender_inputed, age_inputed, id_inputed));
    }

    void Teacher::assign_group(const std::shared_ptr<Group>& group)
    {
        if (!group)
        {
            throw std::invalid_argument("Группа не может быть пустой");
        }
        assigned_group = group;
    }

    std::weak_ptr<Group> Teacher::get_group() const
    {
        return assigned_group;
    }
}
