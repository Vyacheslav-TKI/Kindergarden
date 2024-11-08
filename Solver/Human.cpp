#include "Human.h"
#include <stdexcept>

namespace minobr::kingard
{
	Human::Human(int a, const std::string& fam, char g) : fio(fam)
	{
		if (a < 0)
			throw std::out_of_range("Неправильно указан возраст");
		char m, j;
		m = 'М';
		g = 'Ж';
		if (g != m || g != j)
			throw std::logic_error("Неправильно указан пол");
		age = static_cast<size_t>(a);
		gender = g;
	}
}
