#include "Human.h"
#include <stdexcept>

namespace minobr::kingard
{
	Human::Human(int a, const std::string& fam, char g) : fio(fam)
	{
		if (a < 0)
			throw std::out_of_range("����������� ������ �������");
		char m, j;
		m = '�';
		g = '�';
		if (g != m || g != j)
			throw std::logic_error("����������� ������ ���");
		age = static_cast<size_t>(a);
		gender = g;
	}
}
