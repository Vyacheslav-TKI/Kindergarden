#include "CppUnitTest.h"
#include "../Solver/Group.h"
#include "../Solver/Teacher.h"
#include "../Solver/Baby.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace Tests
{
    TEST_CLASS(GroupTests)
    {
    public:

        TEST_METHOD(TestAddChild)
        {
            
            std::string teacher_name = "Mr. Smith";
            std::string teacher_gender = "Ì";
            Teacher teacher(teacher_name, teacher_gender, 35, 1);

            
            std::string group_name = "Sunshine";
            Group group(group_name, &teacher);

            
            group.add_child(std::make_unique<Baby>("Alice", "Æ", 5));

            
            Assert::AreEqual(size_t(1), group.get_children().size());
        }

        TEST_METHOD(TestGetChildrenByAge)
        {
            
            std::string teacher_name = "Ms. Johnson";
            std::string teacher_gender = "Æ";
            Teacher teacher(teacher_name, teacher_gender, 40, 2);

            
            std::string group_name = "Stars";
            Group group(group_name, &teacher);

            
            group.add_child(std::make_unique<Baby>("Bob", "Ì", 4));
            group.add_child(std::make_unique<Baby>("Charlie", "Ì", 5));
            group.add_child(std::make_unique<Baby>("Daisy", "Æ", 4));

            
            auto children_age_4 = group.get_children_by_age(4);

            
            Assert::AreEqual(size_t(2), children_age_4.size());
        }

        TEST_METHOD(TestMaleFemaleRatio)
        {
            
            std::string teacher_name = "Ms. Lee";
            std::string teacher_gender = "Æ";
            Teacher teacher(teacher_name, teacher_gender, 30, 3);

            
            std::string group_name = "Rainbow";
            Group group(group_name, &teacher);

            
            group.add_child(std::make_unique<Baby>("Eve", "Æ", 5));
            group.add_child(std::make_unique<Baby>("Frank", "Ì", 6));

            
            Assert::AreEqual(1.0, group.male_female_ratio());
        }

        TEST_METHOD(TestToString)
        {
            
            std::string teacher_name = "Ms. Johnson";
            std::string teacher_gender = "Æ";
            Teacher teacher(teacher_name, teacher_gender, 40, 2);

            
            std::string group_name = "Stars";
            Group group(group_name, &teacher);

            
            group.add_child(std::make_unique<Baby>("Bob", "Ì", 4));
            group.add_child(std::make_unique<Baby>("Charlie", "Ì", 5));

            
            std::string group_string = group.to_string();

            
            Assert::IsTrue(group_string.find("Group Name: Stars") != std::string::npos);
            Assert::IsTrue(group_string.find("Bob") != std::string::npos);
            Assert::IsTrue(group_string.find("Charlie") != std::string::npos);
        }
    };
}