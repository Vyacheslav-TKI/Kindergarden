#include "Human.h"
#include <stdexcept>

namespace minobr::kingard
{
    Human::Human(int age_old, const std::string& name, char is_gender)
        : age(age_old), fio(name), gender(is_gender)
    {
        if (age_old < 0)
            throw std::out_of_range("Возраст не может быть отрицательным");

        if (name.empty())
            throw std::invalid_argument("Имя не может быть пустым");

        if (is_gender != male && is_gender != female)
            throw std::logic_error("Пол должен быть 'М' или 'Ж'");
    }
}
