#pragma once
#include <string>
#include <memory>
#include "Human.h"
#include "Group.h"

namespace minobr::kingard
{
	class Teacher : public Human
	{
	public:
		/**
		* @brief Конструктор
		*/
		Teacher(std::string fio_inputed, std::string& gender_inputed, int age_inputed, int id_inputed);

	private:
		size_t id;
		std::weak_ptr<Group> assigned_group;
	};
}