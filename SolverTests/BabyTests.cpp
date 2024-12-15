#include "CppUnitTest.h"
#include "../Solver/Baby.h"

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
            char gender = 'Ж';
            int age = 1; 

            
            Assert::ExpectException<std::logic_error>([&]() {
                Baby::create(fio, gender, age);
                });
        }
    };
}
