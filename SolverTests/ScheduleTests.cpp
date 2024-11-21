#include "CppUnitTest.h"
#include "../Solver/Schedule.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace minobr::kingard;

namespace Tests
{
    TEST_CLASS(ScheduleTests)
    {
    public:

        TEST_METHOD(TestSetScheduleAndRetrieve)
        {
            Schedule schedule;

            
            std::vector<std::string> activities = { "Music", "Drawing" };
            schedule.set_schedule("Monday", "Sunshine", activities);

            
            auto retrieved_schedule = schedule.get_group_schedule("Monday", "Sunshine");

            Assert::AreEqual(size_t(2), retrieved_schedule.size());
            Assert::AreEqual(std::string("Music"), retrieved_schedule[0]);
            Assert::AreEqual(std::string("Drawing"), retrieved_schedule[1]);
        }

        TEST_METHOD(TestToString)
        {
            Schedule schedule;

            
            std::vector<std::string> activities = { "Music", "Physical Education" };
            schedule.set_schedule("Tuesday", "Rainbow", activities);

            
            std::string schedule_string = schedule.to_string();

            
            
            Assert::IsTrue(schedule_string.find("Tuesday") != std::string::npos);
            Assert::IsTrue(schedule_string.find("Rainbow") != std::string::npos);
            Assert::IsTrue(schedule_string.find("Music") != std::string::npos);
            Assert::IsTrue(schedule_string.find("Physical Education") != std::string::npos);
        }
    };