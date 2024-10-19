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

		const std::string fio;

		const std::string gender;

		const size_t age;

		const size_t id;
	};
}