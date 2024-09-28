#pragma once
#include <string>
namespace minobr::kingard
{
	class Teacher
	{
	public:
		/**
		* @brief Конструктор
		*/
		Teacher(std::string fio_inputed, std::string gender_inputed, int age_inputed, int id_inputed);

	private:

		std::string fio;

		std::string gender;

		size_t age;

		size_t id;
	};
}