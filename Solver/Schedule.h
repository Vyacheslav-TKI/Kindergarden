#pragma once
#include "Group.h"
#include <vector>
#include <string>
#include <sstream>

namespace minobr::kingard
{
	struct Schedule_entry {
		std::string group;
		std::string day; 
		std::string activity;
	};

	class Schedule
	{
	private:
		std::vector<Schedule_entry> entries;
	public:
		/**
		* @brief показывает занятость группы на данный день
		* @param day введенный день
		* @param group заданная группа
		*/
		std::vector<std::string> get_activities_for_group(const std::string& group, const std::string& day) const;

		/**
		* @brief создает новый объект структуры Schedule_entry
		*/
		void add_entry(const std::string& group, const std::string& day, const std::string& activity);

		/**
		* @brief удаляет объект структуры Schedule_entry
		*/
		void remove_entry(const std::string& group, const std::string& day);

		/**
		* @brief сериализация в строку
		*/
		std::string to_string() const;
	};
}
