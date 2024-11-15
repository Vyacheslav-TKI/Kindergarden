#include "Baby.h"
#include <stdexcept>
namespace minobr::kingard
{
	Baby::Baby(std::string fio_inputed, std::string gender_inputed, int age_inputed) : Human(age_inputed, fio_inputed, gender_inputed)
	{
		if (age_inputed < min_age || age_inputed > max_age)
		{
			throw std::logic_error("Возраст указан неверно");
		}
	}

	std::ostream& operator << (std::ostream& os, const Baby& baby)
	{
		os << baby.fio << "/n" << baby.gender << "/n" << baby.age;
		return os;
	}
}
