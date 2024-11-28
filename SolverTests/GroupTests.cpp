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
            
            auto teacher = std::make_shared<Teacher>("�������� ��������� ��������", "�", 30, 1);

            
            Group group("������ �����", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("������� ���� ��������", "�", 5);
            auto baby2 = std::make_shared<Baby>("�������� ����� ��������", "�", 6);
            group.add_child(baby1);
            group.add_child(baby2);

            
            const auto& children = group.get_children();
            Assert::AreEqual(size_t(2), children.size(), L"���������� ����� � ������ ������ ���� 2.");
        }

        TEST_METHOD(TestMaleFemaleRatio)
        {
            
            auto teacher = std::make_shared<Teacher>("������ ������ ����������", "�", 30, 1);

            
            Group group("������ 2", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("����� ��������� ���������", "�", 5);
            auto baby2 = std::make_shared<Baby>("������ ������ ������������", "�", 4);
            auto baby3 = std::make_shared<Baby>("��������� ������� ����������", "�", 6);
            group.add_child(baby1);
            group.add_child(baby2);
            group.add_child(baby3);

            
            double ratio = group.male_female_ratio();
            Assert::AreEqual(2.0, ratio, L"����������� ��������� � �������� ������ ���� 2:1.");
        }

        TEST_METHOD(TestGetChildrenByAge)
        {
           
            auto teacher = std::make_shared<Teacher>("������� ���� ������������", "�", 35, 2);

            
            Group group("������ 3", teacher.get());

            
            auto baby1 = std::make_shared<Baby>("����� ��������� ���������", "�", 5);
            auto baby2 = std::make_shared<Baby>("������ ������ ������������", "�", 4);
            auto baby3 = std::make_shared<Baby>("�������� ����� ��������", "�", 5);
            group.add_child(baby1);
            group.add_child(baby2);
            group.add_child(baby3);

            
            auto children_age_5 = group.get_children_by_age(5);

            
            Assert::AreEqual(size_t(2), children_age_5.size(), L"������ ���� 2 ������ �������� 5 ���.");
            Assert::AreEqual(std::string("����� ��������� ���������"), children_age_5[0]->fio, L"������ ������ ������ ���� ����� ��������� ���������.");
            Assert::AreEqual(std::string("�������� ����� ��������"), children_age_5[1]->fio, L"������ ������ ������ ���� �������� ����� ��������.");
        }

        TEST_METHOD(TestGetTeacher)
        {
            
            auto teacher = std::make_shared<Teacher>("������� ������ ����������", "�", 30, 1);

            
            Group group("������ 4", teacher.get());

            
            auto assigned_teacher = group.get_teacher();
            Assert::IsNotNull(assigned_teacher, L"������� ������ ���� ��������� � ������.");
            Assert::AreEqual(std::string("������� ������ ����������"), assigned_teacher->fio, L"��� ������� ������ ���� ������� ������ ����������.");
        }

        TEST_METHOD(TestEmptyGroup)
        {
            
            auto teacher = std::make_shared<Teacher>("�������� ����� ����������", "�", 35, 2);

            
            Group group("������ 5", teacher.get());

            
            const auto& children = group.get_children();
            Assert::AreEqual(size_t(0), children.size(), L"������ ������ ���� ������.");
        }
    };
}
