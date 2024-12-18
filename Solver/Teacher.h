#pragma once
#include <string>
#include <memory>
#include "Human.h"
#include "Group.h"

namespace minobr::kingard
{
    class Group;

    class Teacher : public Human, public std::enable_shared_from_this<Teacher>
    {
    private:
        size_t id;                        
        std::weak_ptr<Group> assigned_group; 

        /**
         * @brief Приватный конструктор
         */
        Teacher(const std::string& fio_inputed, char gender_inputed, int age_inputed, size_t id_inputed);

    public:
        /**
         * @brief Статический метод создания объекта Teacher
         * @param fio_inputed ФИО преподавателя
         * @param gender_inputed Пол преподавателя ('М' или 'Ж')
         * @param age_inputed Возраст преподавателя
         * @param id_inputed Уникальный ID преподавателя
         * @return Умный указатель на объект Teacher
         */
        static std::shared_ptr<Teacher> create(const std::string& fio_inputed, char gender_inputed, int age_inputed, size_t id_inputed);

        /**
         * @brief Назначает группу преподавателю
         * @param group Умный указатель на группу
         */
        void assign_group(const std::shared_ptr<Group>& group);

        /**
         * @brief Получает текущую назначенную группу
         * @return Слабая ссылка на группу
         */
        std::weak_ptr<Group> get_group() const;
    };
}
