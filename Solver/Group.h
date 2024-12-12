#pragma once
#include <vector>
#include <memory>
#include <cmath>
#include <optional>
#include "Baby.h"
#include "Teacher.h"

namespace minobr::kingard {
	class Group : public std::enable_shared_from_this<Group>
	{
	private:

		std::string name_group;
		std::vector<Baby*> babies; 
		std::shared_ptr<Teacher> teacher;

	public:

		/**
		* @brief Конструктор
		* @param name имя группы
		* @param educator указатель на элемент класса учитель
		*/
		Group(const std::string& name, const std::shared_ptr<Teacher>& educator);

		/**
		* @brief Проверка на заполненость массива std::vector<std::shared_ptr<Baby>> babies
		*/
		std::optional<std::shared_ptr<Baby>> get_baby_at() const;

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