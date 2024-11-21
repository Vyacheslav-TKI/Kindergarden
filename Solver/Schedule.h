#pragma once
#include <map>
#include <vector>
#include <string>
#include <sstream>

namespace minobr::kingard
{
	class Schedule
	{
	private:
		std::map<std::string, std::vector<std::string>> group_schedule;
	public:
		/**
		* @brief устанавливает занятия на заданный день в заданной группе
		* @param day заданный день
		* @param inputed_group_name заданная группа
		* @param activities занятия
		*/
		void set_schedule(const std::string& day, const std::string& inputed_group_name, const std::vector<std::string>& activities);

		/**
		* @brief показывает занятость группы на данный день
		* @param day введенный день
		* @param inputed_group_name заданная группа
		*/
		const std::vector<std::string>& get_group_schedule(const std::string& day, const std::string& inputed_group_name) const;

		/**
		* @brief сериализация в строку
		*/
		std::string to_string() const;
	};
}
