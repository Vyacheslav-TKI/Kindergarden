#pragma once
#include <string>

namespace minobr::kingard
{
	class Human
	{
	protected:
		int age;
		std::string fio;
		char gender;

	public:
		/**
		* @brief �����������
		*/
		Human(int a, const std::string& fam, char g);

	};

}