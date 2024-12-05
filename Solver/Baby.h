#pragma once
#include <string>
#include "Human.h"
#include "Group.h"
#include <memory>

namespace minobr::kingard
{
	class Baby : public Human
	{
	private:

		int min_age = 2;
		int max_age = 7; 
		std::weak_ptr<Group> group;

	public:

		/**
		* @brief Конструктор
		*/
		Baby(std::string fio_inputed, std::string gender_inputed, int age_inputed);

		/**
		* @brief оператор вывода
		*/
		friend std::ostream& operator << (std::ostream& os, const Baby& baby);

		/**
		* @brief Прикрепляет ребенка к определенной группе
		*/
		void set_group(const std::shared_ptr<Group>& group)

	};
}
