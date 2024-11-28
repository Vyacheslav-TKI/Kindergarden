#include "CppUnitTest.h"
#include "../Solver/Schedule.h"
#include "../Solver/Group.h"
#include "../Solver/Teacher.h"
#include "../Solver/Baby.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace ScheduleTests
{
    TEST_CLASS(ScheduleTests)
    {
    public:
        TEST_METHOD(TestSetAndGetSchedule)
        {
            
            auto teacher = std::make_shared<Teacher>("Иванов Иван Васильевич", "М", 30, 1);

            
            auto group = std::make_shared<Group>("Группа 1", teacher);

            
            auto baby1 = std::make_shared<Baby>("Широканов Сергей Андреевич", "М", 5);
            auto baby2 = std::make_shared<Baby>("Сидорова Мария Олеговна", "Ж", 6);
            group->add_child(baby1);
            group->add_child(baby2);

            
            Schedule schedule;

            
            std::vector<std::string> activities = { "ИЗО", "Пение", "Технология" };
            schedule.set_schedule("Понедельник", group, activities);

            
            const auto& retrieved_activities = schedule.get_group_schedule("Понедельник", group);

            
            Assert::AreEqual(size_t(3), retrieved_activities.size(), L"Количество занятий должно быть 3.");
            Assert::AreEqual(std::string("ИЗО"), retrieved_activities[0], L"Первое занятие должно быть ИЗО.");
            Assert::AreEqual(std::string("Пение"), retrieved_activities[1], L"Второе занятие должно быть Пение.");
            Assert::AreEqual(std::string("Технология"), retrieved_activities[2], L"Третье занятие должно быть Технология.");
        }

        TEST_METHOD(TestEmptySchedule)
        {
            
            auto teacher = std::make_shared<Teacher>("Василенко Данил Вячеславович", "М", 30, 1);

            
            auto group = std::make_shared<Group>("Группа 2", teacher);

            
            Schedule schedule;

            
            const auto& retrieved_activities = schedule.get_group_schedule("Вторник", group);

            
            Assert::IsTrue(retrieved_activities.empty(), L"Расписание для вторника должно быть пустым.");
        }

        TEST_METHOD(TestInvalidGroupPointer)
        {
            
            Schedule schedule;

           
            try
            {
                std::vector<std::string> activities = { "ИЗО", "Пение", "Технология" };
                schedule.set_schedule("Среда", nullptr, activities);
                Assert::Fail(L"Должно быть выброшено исключение для nullptr группы.");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::AreEqual("Пустой указатель группы", std::string(e.what()), L"Исключение должно сообщать о null указателе.");
            }
            catch (...)
            {
                Assert::Fail(L"Исключение должно быть типа std::invalid_argument.");
            }
        }
    };
}
