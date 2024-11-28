#pragma once
#include <vector>
#include <memory>
#include <cmath>
#include "Baby.h"
#include "Teacher.h"

namespace minobr::kingard {
	class Group
	{
	private:

		std::string name_group;
		std::vector<std::shared_ptr<Baby>> babies; 
		std::shared_ptr<Teacher> teacher;

	public:

		/**
		* @brief Конструктор
		* @param name имя группы
		* @param educator указатель на элемент класса учитель
		*/
		Group(const std::string& name, const std::shared_ptr<Teacher>& educator);

		/**
		* @brief функция добавления детей в группу
		* @param child умный указатель на элемент класса Baby
		*/
		void add_child(const std::shared_ptr<Baby>& child);

		/**
		* @brief выводит список детей данной группы
		*/
		const std::vector<std::shared_ptr<Baby>>& get_children() const;

		/**
		* @brief выводит прикрепленного учителя
		*/
		std::shared_ptr<Teacher> get_teacher() const;

		/**
		* @brief вычисляет соотношение мальчиков и девочек в группе
		*/
		double male_female_ratio() const;

		/**
		* @brief вывод списка детей по возрасту
		*/
		std::vector<std::shared_ptr<Baby>> get_children_by_age(int inputed_age) const;

		/**
		* @brief объединеный метод сериализации в строку
		*/
		std::string to_string() const;
	};
}