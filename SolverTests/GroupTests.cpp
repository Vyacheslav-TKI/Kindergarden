#include "CppUnitTest.h"
#include "../Solver/Group.h"
#include "../Solver/Teacher.h"
#include "../Solver/Baby.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace GroupTests
{
    TEST_CLASS(GroupTests)
    {
    public:

        TEST_METHOD(TestAddChild)
        {
            
            auto teacher = std::make_shared<Teacher>("Черенцов Александр Глебович", "М", 30, 1);

            
            Group group("Группа Крови", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("Романов Петр Петрович", "М", 5);
            auto baby2 = std::make_shared<Baby>("Сидорова Мария Олеговна", "Ж", 6);
            group.add_child(baby1);
            group.add_child(baby2);

            
            const auto& children = group.get_children();
            Assert::AreEqual(size_t(2), children.size(), L"Количество детей в группе должно быть 2.");
        }

        TEST_METHOD(TestMaleFemaleRatio)
        {
            
            auto teacher = std::make_shared<Teacher>("Уланов Сергей Алексеевич", "М", 30, 1);

            
            Group group("Группа 2", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("Попов Владислав Андреевич", "М", 5);
            auto baby2 = std::make_shared<Baby>("Зайцев Михаил Владимирович", "М", 4);
            auto baby3 = std::make_shared<Baby>("Филлипова Валерия Николаевна", "Ж", 6);
            group.add_child(baby1);
            group.add_child(baby2);
            group.add_child(baby3);

            
            double ratio = group.male_female_ratio();
            Assert::AreEqual(2.0, ratio, L"Соотношение мальчиков к девочкам должно быть 2:1.");
        }

        TEST_METHOD(TestGetChildrenByAge)
        {
           
            auto teacher = std::make_shared<Teacher>("Петрова Анна Владимировна", "Ж", 35, 2);

            
            Group group("Группа 3", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("Попов Владислав Андреевич", "М", 5);
            auto baby2 = std::make_shared<Baby>("Зайцев Михаил Владимирович", "М", 4);
            auto baby3 = std::make_shared<Baby>("Сидорова Мария Олеговна", "Ж", 5);
            group.add_child(baby1);
            group.add_child(baby2);
            group.add_child(baby3);

            
            auto children_age_5 = group.get_children_by_age(5);

            
            Assert::AreEqual(size_t(2), children_age_5.size(), L"Должно быть 2 ребёнка возраста 5 лет.");
            Assert::AreEqual(std::string("Попов Владислав Андреевич"), children_age_5[0]->fio, L"Первый ребёнок должен быть Попов Владислав Андреевич.");
            Assert::AreEqual(std::string("Сидорова Мария Олеговна"), children_age_5[1]->fio, L"Второй ребёнок должен быть Сидорова Мария Олеговна.");
        }

        TEST_METHOD(TestGetTeacher)
        {
            
            auto teacher = std::make_shared<Teacher>("Бедарев Андрей Валерьевич", "М", 30, 1);

            
            Group group("Группа 4", teacher.get());

            
            auto assigned_teacher = group.get_teacher();
            Assert::IsNotNull(assigned_teacher, L"Учитель должен быть прикреплён к группе.");
            Assert::AreEqual(std::string("Бедарев Андрей Валерьевич"), assigned_teacher->fio, L"Имя учителя должно быть Бедарев Андрей Валерьевич.");
        }

        TEST_METHOD(TestEmptyGroup)
        {
            
            auto teacher = std::make_shared<Teacher>("Зеленова Ольга Алексеевна", "Ж", 35, 2);

            
            Group group("Группа 5", teacher.get());

            
            const auto& children = group.get_children();
            Assert::AreEqual(size_t(0), children.size(), L"Группа должна быть пустой.");
        }
    };
}
