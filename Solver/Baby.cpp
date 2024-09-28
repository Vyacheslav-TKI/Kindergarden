#include "Baby.h"
#include <stdexcept>
namespace minobr::kingard
{
	Baby::Baby(std::string fio_inputed, std::string gender_inputed, int age_inputed)
	{
		if (gender_inputed != "М" || gender_inputed != "Ж") 
		{
			throw std::logic_error("Пол не идентифицирован");
		}

		if (age_inputed < 2 || age_inputed > 7)
		{
			throw std::logic_error("Возраст указан неверно");
		}

		fio = fio_inputed;
		gender = gender_inputed;
		age = static_cast<size_t>(age_inputed);
	}

	std::ostream& operator << (std::ostream& os, const Baby& baby)
	{
		os << baby.fio << "/n" << baby.gender << "/n" << baby.age;
		return os;
	}
}
