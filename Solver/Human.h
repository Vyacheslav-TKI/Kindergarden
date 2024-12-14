#pragma once
#include <string>

namespace minobr::kingard
{
	class Human
	{
	private:

		static constexpr char male = 'M';
		static constexpr char female = 'F';

	protected:
		std::string fio;
		int age;
		char gender;

	public:
		/**
		* @brief Конструктор
		*/
		Human(int age, const std::string& name, char is_gender);

		int get_age() const { return age; }
		const std::string& get_fio() const { return fio; }
		char get_gender() const { return gender; }

	};

}