#include "Human.h"
#include <stdexcept>

namespace minobr::kingard
{
	Human::Human(int age_old, const std::string& name, char is_gender) : fio(name)
	{
		if (age_old < 0)
			throw std::out_of_range("Неправильно указан возраст");

		if (is_gender != male || is_gender != female)
			throw std::logic_error("Неправильно указан пол");
		age = static_cast<size_t>(age_old);
		gender = is_gender;
	}
}
