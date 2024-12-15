#pragma once
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include "Group.h"

namespace minobr::kingard {

    struct ScheduleEntry {
        std::shared_ptr<Group> group; 
        std::string day;              
        std::string activity;         
        std::chrono::system_clock::time_point time; 

        /**
         * @brief Конструктор
         * @param day День недели
         * @param time Время занятия
         */
        ScheduleEntry(const std::string& day, const std::chrono::system_clock::time_point& time);
    };

    class Schedule {
    private:
        std::vector<std::shared_ptr<ScheduleEntry>> entries; 

    public:
        /**
         * @brief Создает запись в расписании
         * @param day День недели
         * @param time Время занятия в формате HH:MM
         * @return Умный указатель на созданную запись
         */
        std::shared_ptr<ScheduleEntry> createEntry(const std::string& day, const std::string& time);

        /**
         * @brief Добавляет группу к записи расписания
         * @param entry Существующая запись
         * @param group Указатель на группу
         */
        void addGroupToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::shared_ptr<Group>& group);

        /**
         * @brief Добавляет занятие к записи расписания
         * @param entry Существующая запись
         * @param activity Название занятия
         */
        void addActivityToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::string& activity);

        /**
         * @brief Возвращает список занятий для указанной группы и дня
         * @param group Указатель на группу
         * @param day День недели
         * @return Список занятий
         */
        std::vector<std::string> getActivitiesForGroup(const std::shared_ptr<Group>& group, const std::string& day) const;

        /**
         * @brief Удаляет запись в расписании
         * @param group Указатель на группу
         * @param day День недели
         * @param time Время занятия
         */
        void removeEntry(const std::shared_ptr<Group>& group, const std::string& day, const std::chrono::system_clock::time_point& time);

        /**
         * @brief Сериализует расписание в строку
         * @return Строковое представление расписания
         */
        std::string to_string() const;

        ~Schedule();
    };
}
