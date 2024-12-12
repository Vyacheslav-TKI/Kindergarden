#pragma once
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include "Group.h"
#include <iomanip>

namespace minobr::kingard {

    struct ScheduleEntry {
        std::shared_ptr<Group> group;
        std::string day;
        std::string activity;

        std::chrono::system_clock::time_point time; 

        /**
        * @brief Конструктор
        * @param day день недели
        * @param time время
        */
        ScheduleEntry(const std::string& day, const std::chrono::system_clock::time_point& time);
    };

    class Schedule {
    private:
        std::vector<std::shared_ptr<ScheduleEntry>> entries;

    public:
        /**
         * @brief Создает расписание.
         * @param day день недели.
         * @param time время.
         * @return указатель на объект структуры ScheduleEntry.
         */
        std::shared_ptr<ScheduleEntry> createEntry(const std::string& day, const std::string& time);

        /**
         * @brief Добавляет группу в расписание
         * @param entry существующий объект расписания
         * @param group умный указатель на группу
         */
        void addGroupToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::shared_ptr<Group>& group);

        /**
         * @brief Добавляет занятия в расписание
         * @param entry существующий объект расписания
         * @param activity название занятия
         */
        void addActivityToEntry(const std::shared_ptr<ScheduleEntry>& entry, const std::string& activity);


        /**
         * @brief Ищет и возвращает список занятий на указанный день указанной группе
         * @param group умный указатель на группу
         * @param day день недели
         * @return массив занятий
         */
        std::vector<std::string> getActivitiesForGroup(const std::shared_ptr<Group>& group, const std::string& day) const;

        /**
         * @brief Удаляет занятия в расписании по группе, дню и времени
         * @param group умный указатель на группу
         * @param day день недели
         * @param time время
         */
        void removeEntry(const std::shared_ptr<Group>& group, const std::string& day, const std::chrono::system_clock::time_point& time);

        /**
         * @brief Сериализация в строку
         * @return непосредственно строка
         */
        std::string to_string() const;
    };
}