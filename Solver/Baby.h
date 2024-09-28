#pragma once
# include <string>
namespace minobr::kingard
{
	class Baby
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

	private:

		std::string fio;

		std::string gender;

		size_t age;

	};
}
