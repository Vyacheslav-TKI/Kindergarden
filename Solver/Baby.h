#pragma once
#include <string>
#include <memory>
#include "Human.h"
#include "Group.h"

namespace minobr::kingard {
    class Group;

    class Baby : public Human, public std::enable_shared_from_this<Baby> {
    private:
        int min_age = 2;
        int max_age = 7;
        Group* group;

        
        Baby(const std::string& fio_inputed, char gender_inputed, int age_inputed);

    public:
        
        friend std::shared_ptr<Baby> create(const std::string& fio_inputed, char gender_inputed, int age_inputed);

        /**
         * @brief Создает экземпляр Baby
         */
        static std::shared_ptr<Baby> create(const std::string& fio_inputed, char gender_inputed, int age_inputed);

        /**
         * @brief Возвращает строковое представление объекта Baby
         */
        std::string to_string() const;

        void set_group(Group* group);
    };
}
