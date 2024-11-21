#include "../Solver/Group.h"
#include "../Solver/Schedule.h"
#include <memory>
#include <iostream> 

/**
* @brief Точка входа в программу
* @return 0 программа успешно завершена
*/
int main()
{       
        std::string teacher1 = "А.И.Беляков";
        
        minobr::kingard::Teacher teacher(teacher1, 'М', 36, 100138);

        std::string name1 = "Группа Крови";

        minobr::kingard::Group group_blood(name1, &teacher);

        group_blood.add_child(std::make_unique<minobr::kingard::Baby>("Шилейковский Владислав Андреевич", 'М', 5));
        group_blood.add_child(std::make_unique<minobr::kingard::Baby>("Василенко Данил Вячеславович", 'М', 2));
        group_blood.add_child(std::make_unique<minobr::kingard::Baby>("Перминова Ульяна Николаевна", 'Ж', 6));

        minobr::kingard::Schedule schedule;
        schedule.set_schedule("Понедельник", name1, { "Музыка", "Ядерная физика" });
        schedule.set_schedule("Вторник", name1, { "Art", "Music" });

        std::cout << group_blood.to_string() << "\n";
        std::cout << group_blood.get_children() << "\n";
        std::cout << group_blood.get_children_by_age(2) << "\n";

        std::cout << schedule.to_string() << "\n";

        return 0;
}