#pragma once
#include <string>
#include "Human.h"
namespace minobr::kingard
{
	class Baby : public Human
	{
	public:

		/**
		* @brief Конструктор
		*/
		Baby(std::string fio_inputed, std::string gender_inputed, int age_inputed);

		/**
		* @brief оператор вывода
		*/
		friend std::ostream& operator << (std::ostream& os, const Baby& baby);

	};
}
