#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include "..\Solver\Baby.h"
#include "..\Solver\Group.h"
#include "..\Solver\Teacher.h"
#include "..\Solver\Schedule.h"

using namespace minobr::kingard;

int main() {
    try {
        
        auto teacher = Teacher::create("Иван Петров", 'M', 35, 101);

        
        auto group = Group::create("Младшая группа", teacher.get());

        
        auto baby1 = Baby::create("Анна Иванова", 'F', 5);
        auto baby2 = Baby::create("Павел Сидоров", 'M', 4);

        
        group->add_child(baby1);
        group->add_child(baby2);

       
        std::cout << "Список детей в группе:\n";
        for (const auto& child : group->get_children()) {
            std::cout << " - " << child->to_string() << "\n";
        }

        
        Schedule schedule;

        
        auto entry = schedule.createEntry("Понедельник", "10:00");
        schedule.addGroupToEntry(entry, group);
        schedule.addActivityToEntry(entry, "Рисование");

        
        std::cout << "\nРасписание:\n" << schedule.to_string() << "\n";

        
        auto activities = schedule.getActivitiesForGroup(group, "Понедельник");
        std::cout << "\nЗанятия группы в понедельник:\n";
        for (const auto& activity : activities) {
            std::cout << " - " << activity << "\n";
        }

        
        schedule.removeEntry(group, "Понедельник", entry->time);

        
        std::cout << "\nРасписание после удаления записи:\n" << schedule.to_string() << "\n";

    }
    catch (const std::exception& ex) {
        std::cerr << "Ошибка: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
