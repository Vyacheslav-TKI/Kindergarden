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
            
            auto teacher = std::make_shared<Teacher>("������ ���� ����������", "�", 30, 1);

            
            auto group = std::make_shared<Group>("������ 1", teacher);

            
            auto baby1 = std::make_shared<Baby>("��������� ������ ���������", "�", 5);
            auto baby2 = std::make_shared<Baby>("�������� ����� ��������", "�", 6);
            group->add_child(baby1);
            group->add_child(baby2);

            
            Schedule schedule;

            
            std::vector<std::string> activities = { "���", "�����", "����������" };
            schedule.set_schedule("�����������", group, activities);

            
            const auto& retrieved_activities = schedule.get_group_schedule("�����������", group);

            
            Assert::AreEqual(size_t(3), retrieved_activities.size(), L"���������� ������� ������ ���� 3.");
            Assert::AreEqual(std::string("���"), retrieved_activities[0], L"������ ������� ������ ���� ���.");
            Assert::AreEqual(std::string("�����"), retrieved_activities[1], L"������ ������� ������ ���� �����.");
            Assert::AreEqual(std::string("����������"), retrieved_activities[2], L"������ ������� ������ ���� ����������.");
        }

        TEST_METHOD(TestEmptySchedule)
        {
            
            auto teacher = std::make_shared<Teacher>("��������� ����� ������������", "�", 30, 1);

            
            auto group = std::make_shared<Group>("������ 2", teacher);

            
            Schedule schedule;

            
            const auto& retrieved_activities = schedule.get_group_schedule("�������", group);

            
            Assert::IsTrue(retrieved_activities.empty(), L"���������� ��� �������� ������ ���� ������.");
        }

        TEST_METHOD(TestInvalidGroupPointer)
        {
            
            Schedule schedule;

           
            try
            {
                std::vector<std::string> activities = { "���", "�����", "����������" };
                schedule.set_schedule("�����", nullptr, activities);
                Assert::Fail(L"������ ���� ��������� ���������� ��� nullptr ������.");
            }
            catch (const std::invalid_argument& e)
            {
                Assert::AreEqual("������ ��������� ������", std::string(e.what()), L"���������� ������ �������� � null ���������.");
            }
            catch (...)
            {
                Assert::Fail(L"���������� ������ ���� ���� std::invalid_argument.");
            }
        }
    };
}
