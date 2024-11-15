#include "Teacher.h"
#include <string>
#include <stdexcept>

namespace minobr::kingard
{
	Teacher::Teacher(std::string fio_inputed, std::string gender_inputed, int age_inputed, int id_inputed) : Human(age_inputed, fio_inputed, gender_inputed)
	{
		if (id_inputed < 0)
		{
			throw std::out_of_range("ID указан неверно");
		}

		id = static_cast<size_t>(id_inputed);

	}
}