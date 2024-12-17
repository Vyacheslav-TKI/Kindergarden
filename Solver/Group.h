#pragma once
#include <vector>
#include <memory>
#include <optional>
#include <string>
#include <cmath>
#include "Baby.h"
#include "Teacher.h"

namespace minobr::kingard
{
    class Baby;
    class Teacher;

    class Group final: public std::enable_shared_from_this<Group>
    {
    private:
        std::string name_group;                         
        std::vector<std::shared_ptr<Baby>> babies;       
        std::shared_ptr<Teacher> teacher;               

        /**
         * @brief Приватный конструктор
         */
        Group(const std::string& name, Teacher* educator);

    public:
        /**
         * @brief Статический метод для создания объекта Group
         */
        static std::shared_ptr<Group> create(const std::string& name, Teacher* educator);

        /**
         * @brief Добавление ребенка в группу
         */
        void add_child(const std::shared_ptr<Baby>& child);

        /**
        * @brief Удаляет ребенка из группы
        * @param child Указатель на ребенка, которого нужно удалить
         */
        void remove_child(const std::shared_ptr<Baby>& child);

        /**
         * @brief Возвращает ребенка по индексу
         */
        std::optional<std::shared_ptr<Baby>> get_baby_at(size_t index) const;

        /**
         * @brief Получение списка всех детей в группе
         */
        const std::vector<std::shared_ptr<Baby>>& get_children() const;

        /**
         * @brief Получение воспитателя группы
         */
        std::shared_ptr<Teacher> get_teacher() const;

        /**
         * @brief Расчет соотношения мальчиков и девочек
         */
        double male_female_ratio() const;

        /**
         * @brief Фильтрация детей по возрасту
         */
        std::vector<std::shared_ptr<Baby>> get_children_by_age(int inputed_age) const;

        /**
         * @brief Сериализация данных группы в строку
         */
        std::string to_string() const;
    };
}
