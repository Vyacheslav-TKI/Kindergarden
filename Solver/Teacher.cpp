#include "Teacher.h"
#include <string>
#include <stdexcept>

namespace minobr::kingard
{
	Teacher::Teacher(std::string fio_inputed, std::string gender_inputed, int age_inputed, int id_inputed)
	{
		if (gender_inputed != "М" || gender_inputed != "Ж")
		{
			throw std::logic_error("Пол не идентифицирован");
		}

		if (id_inputed < 0)
		{
			throw std::underflow_error("ID указан неверно");
		}

		fio = fio_inputed;
		gender = gender_inputed;
		age = static_cast<size_t>(age_inputed);
		id = static_cast<size_t>(id_inputed);

	}
}