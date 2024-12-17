#include "CppUnitTest.h"
#include "../Solver/Baby.h"
#include "../Solver/Group.h"
#include "../Solver/Teacher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace KindergardenTests
{
    TEST_CLASS(BabyTests)
    {
    public:

        TEST_METHOD(CreateBaby_ValidData_Success)
        {
            std::string fio = "Анна Иванова";
            char gender = 'F';
            int age = 5;

            auto baby = Baby::create(fio, gender, age);

            Assert::AreEqual(fio, baby->get_fio());
            Assert::AreEqual(gender, baby->get_gender());
            Assert::AreEqual(age, baby->get_age());
        }

        TEST_METHOD(CreateBaby_InvalidAge_ThrowsException)
        {
            std::string fio = "Анна Иванова";
            char gender = 'F';
            int age = 1;

            Assert::ExpectException<std::logic_error>([&]() {
                Baby::create(fio, gender, age);
                });
        }

        TEST_METHOD(AddBabyToGroup_Success)
        {
            
            auto teacher = Teacher::create("Иван Петров", 'M', 35, 101);
            auto group = Group::create("Младшая группа", teacher.get());
            auto baby = Baby::create("Анна Иванова", 'F', 5);

           
            group->add_child(baby);

            
            Assert::AreEqual(static_cast<size_t>(1), group->get_children().size());
            Assert::AreEqual(baby->get_fio(), group->get_children()[0]->get_fio());
        }

        TEST_METHOD(RemoveBabyFromGroup_Success)
        {
            
            auto teacher = Teacher::create("Иван Петров", 'M', 35, 101);
            auto group = Group::create("Младшая группа", teacher.get());
            auto baby = Baby::create("Анна Иванова", 'F', 5);

            group->add_child(baby);

            
            group->remove_child(baby); 

            
            Assert::AreEqual(static_cast<size_t>(0), group->get_children().size());
        }
    };
}
