#include "CppUnitTest.h"
#include "../Solver/Teacher.h" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace KindergardenTests
{
    class Teacher;
    TEST_CLASS(TeacherTests)
    {
    public:

        TEST_METHOD(CreateTeacher_ValidData_Success)
        {
            
            std::string fio = "Иван Петров";
            char gender = 'M';
            int age = 30;
            size_t id = 101;

            
            auto teacher = minobr::kingard::Teacher::create(fio, gender, age, id);

            
            Assert::AreEqual(fio, teacher->get_fio());
            Assert::AreEqual(gender, teacher->get_gender());
            Assert::AreEqual(age, teacher->get_age());
        }

        TEST_METHOD(CreateTeacher_InvalidAge_ThrowsException)
        {
            
            std::string fio = "Иван Петров";
            char gender = 'M';
            int age = 15; 
            size_t id = 101;

            
            Assert::ExpectException<std::invalid_argument>([&]() {
                minobr::kingard::Teacher::create(fio, gender, age, id);
                });
        }
    };
}
