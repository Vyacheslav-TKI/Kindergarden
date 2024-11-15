#pragma once
#include <string>

namespace minobr::kingard
{
	class Human
	{
	private:

		char male = 'М';
		char female = 'Ж';

	protected:
		int age;
		std::string fio;
		char gender;

	public:
		/**
		* @brief Конструктор
		*/
		Human(int age, const std::string& name, char is_gender);

	};

}