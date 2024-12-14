#include "Baby.h"
#include <sstream>
#include <stdexcept>

namespace minobr::kingard {
    
    Baby::Baby(const std::string& fio_inputed, char gender_inputed, int age_inputed)
        : Human(age_inputed, fio_inputed, gender_inputed), group(nullptr) {
        if (age_inputed < min_age || age_inputed > max_age) {
            throw std::out_of_range("Возраст ребёнка выходит за пределы допустимого диапазона [2-7]");
        }
    }

    
    std::shared_ptr<Baby> Baby::create(const std::string& fio_inputed, char gender_inputed, int age_inputed) {
        return std::shared_ptr<Baby>(new Baby(fio_inputed, gender_inputed, age_inputed));
    }

    std::string Baby::to_string() const {
        std::ostringstream oss;
        oss << "ФИО: " << fio << ", Пол: " << (gender == 'М' ? "Мужской" : "Женский") << ", Возраст: " << age;
        return oss.str();
    }

    
    void Baby::set_group(Group* group) {
        this->group = group;
    }
}
