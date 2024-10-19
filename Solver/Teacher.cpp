#include "Teacher.h"
#include <string>
#include <stdexcept>

namespace minobr::kingard
{
	Teacher::Teacher(std::string fio_inputed, std::string gender_inputed, int age_inputed, int id_inputed)
	{
		if (gender_inputed != "�" || gender_inputed != "�")
		{
			throw std::logic_error("��� �� ���������������");
		}

		if (id_inputed < 0)
		{
			throw std::underflow_error("ID ������ �������");
		}

		fio = fio_inputed;
		gender = gender_inputed;
		age = static_cast<size_t>(age_inputed);
		id = static_cast<size_t>(id_inputed);

	}
}