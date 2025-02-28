// #include "task.h"
// #include "user.h"
// #include "task_manager.h"
// #include <iostream>

// int main() {
//     TaskManager manager;
//     User user{"Armen", "1010botas"};
    
//     // Регистрация пользователей
//     manager.register_user(&user);
//     manager.register_user("Alice", "password123");
//     manager.register_user("Bob", "securepass");
//     manager.register_user("Johnny", "xaryxury");
//     manager.register_user("Bfasdgfob", "hendo123");
//     manager.register_user("Bobwfew", "xcho2004");
//     manager.register_user("Bowgfewb", "123_garnik456");
//     manager.register_user("Bobewggew", "123-0012");

//     // Создание задач
//     Task task1 = manager.add_task("Fix Bug", "Fix the login issue", "2025-03-01", "Work", PRIO::HIGH);
//     Task task2 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);
//     Task task3 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::URG);
//     Task task4 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);
//     Task task5 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);
//     Task task6 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::LOW);
//     Task task7 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);
//     Task task8 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::HIGH);
//     Task task9 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::LOW);
//     Task task10 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);
//     Task task11 = manager.add_task("Buy Groceries", "Milk, eggs, bread", "2025-03-05", "Personal", PRIO::MID);

//     manager.list_all_users();
//     // manager.display_tasks_for_user();
    
//     return 0;
// }
// #include <iostream>
// #include "task.h"
// #include "user.h"
// #include "task_manager.h"
// #include "encrypt.h"
// #include "print_colors.h"

// void debug_print(const std::string& message) {
//     std::cout << YELLOW << "[DEBUG] " << message << RESET << std::endl;
// }

// int main() {
//     debug_print("Starting TaskManager application...");

//     TaskManager taskManager;

//     debug_print("Registering users...");
//     taskManager.register_user("Alice", "password123");
//     taskManager.register_user("Bob", "securepass");

//     debug_print("Adding tasks...");
//     Task task1 = taskManager.add_task("Write Unit Tests", "Create unit tests for the project", "2024-01-31", "Development", PRIO::MID);
//     Task task2 = taskManager.add_task("Design Database Schema", "Design the database schema for the new project", "2024-02-15", "Design", PRIO::HIGH);

//     debug_print("Assigning tasks to users...");
//     taskManager.add_task_for_user(1, &task1);
//     taskManager.add_task_for_user(2, &task2);

//     debug_print("Displaying tasks for all users...");
//     taskManager.display_tasks_for_user();

//     debug_print("Editing task 1 for user 1...");
//     taskManager.edit_task_for_user(1, "Write Integration Tests", "Update task description", "2024-03-01", "QA", PRIO::URG);

//     debug_print("Displaying tasks after edit...");
//     taskManager.display_tasks_for_user();

//     debug_print("Deleting task 2 for user 2...");
//     taskManager.delete_task_for_user(2, 2);

//     debug_print("Displaying tasks after deletion...");
//     taskManager.display_tasks_for_user();

//     debug_print("Listing all users...");
//     taskManager.list_all_users();

//     debug_print("All tasks executed successfully.");
//     return 0;
// }

// #include <iostream>
// #include "task.h"
// #include "user.h"
// #include "task_manager.h"
// #include "encrypt.h"
// #include "print_colors.h"

// void debug_print(const std::string& message) {
//     std::cout << YELLOW << "[DEBUG] " << message << RESET << std::endl;
// }

// int main() {
//     debug_print("Starting TaskManager application...");

//     TaskManager taskManager;

//     debug_print("Registering users...");
//     taskManager.register_user("Alice", "password123");
//     taskManager.register_user("Bob", "securepass");

//     debug_print("Adding tasks...");
//     Task task1 = taskManager.add_task("Write Unit Tests", "Create unit tests for the project", "2024-01-31", "Development", PRIO::MID);
//     Task task2 = taskManager.add_task("Design Database Schema", "Design the database schema for the new project", "2024-02-15", "Design", PRIO::HIGH);

//     debug_print("Assigning tasks to users...");
//     taskManager.add_task_for_user(1, &task1);
//     taskManager.add_task_for_user(2, &task2);

//     debug_print("Displaying tasks for all users...");
//     taskManager.display_tasks_for_user();

//     debug_print("Editing task 1 for user 1...");
//     taskManager.edit_task_for_user(1, "Write Integration Tests", "Update task description", "2024-03-01", "QA", PRIO::URG);

//     debug_print("Displaying tasks after edit...");
//     taskManager.display_tasks_for_user();

//     debug_print("Testing increment and decrement operators...");
//     ++task1;
//     task1++;
//     --task1;
//     task1--;

//     debug_print("Displaying tasks after increment and decrement...");
//     taskManager.display_tasks_for_user();

//     debug_print("Testing comparison operators...");
//     if (task1 == task2) {
//         std::cout << "Tasks have the same priority." << std::endl;
//     } else if (task1 > task2) {
//         std::cout << "Task1 has higher priority than Task2." << std::endl;
//     } else {
//         std::cout << "Task1 has lower priority than Task2." << std::endl;
//     }

//     debug_print("Displaying tasks after comparison...");
//     taskManager.display_tasks_for_user();

//     debug_print("Deleting task 2 for user 2...");
//     taskManager.delete_task_for_user(2, 2);

//     debug_print("Displaying tasks after deletion...");
//     taskManager.display_tasks_for_user();

//     debug_print("Listing all users...");
//     taskManager.list_all_users();

//     debug_print("Testing move constructor and assignment operator...");
//     Task task3(std::move(task1));
//     task1 = task2;

//     debug_print("Displaying tasks after move and assignment...");
//     taskManager.display_tasks_for_user();

//     debug_print("All tasks executed successfully.");
//     return 0;
// }

#include <iostream>
#include <utility>  // для std::move
#include "task.h"
#include "user.h"
#include "task_manager.h"
#include "encrypt.h"
#include "print_colors.h"

void debug_print(const std::string& message) {
    std::cout << YELLOW << "[DEBUG] " << message << RESET << std::endl;
}

void print_task_priority(const Task& task) {
    std::cout << GREEN << "Task Priority: " << RESET;
    switch(task.get_priority(task)) {
        case INVALID_PRIO: std::cout << "INVALID_PRIO" << std::endl; break;
        case LOW: std::cout << "LOW" << std::endl; break;
        case MID: std::cout << "MID" << std::endl; break;
        case HIGH: std::cout << "HIGH" << std::endl; break;
        case URG: std::cout << "URG" << std::endl; break;
    }
}

void test_task_operations(Task& task1, Task& task2) {
    debug_print("Testing increment and decrement operators on task1...");
    print_task_priority(task1);
    ++task1;
    print_task_priority(task1);
    task1++;
    print_task_priority(task1);
    --task1;
    print_task_priority(task1);
    task1--;
    print_task_priority(task1);

    debug_print("Testing comparison operators between task1 and task2...");
    if (task1 == task2) {
        std::cout << "Tasks have the same priority." << std::endl;
    } else if (task1 > task2) {
        std::cout << "Task1 has higher priority than Task2." << std::endl;
    } else {
        std::cout << "Task1 has lower priority than Task2." << std::endl;
    }
}

int main() {
    debug_print("Starting TaskManager application...");

    TaskManager taskManager;

    debug_print("Registering users...");
    taskManager.register_user("Alice", "password123");
    taskManager.register_user("Bob", "securepass");

    debug_print("Adding tasks...");
    Task task1 = taskManager.add_task("Write Unit Tests", "Create unit tests for the project", "2024-01-31", "Development", PRIO::LOW);
    Task task2 = taskManager.add_task("Design Database Schema", "Design the database schema for the new project", "2024-02-15", "Design", PRIO::MID);

    debug_print("Assigning tasks to users...");
    taskManager.add_task_for_user(1, &task1);
    taskManager.add_task_for_user(2, &task2);

    debug_print("Displaying tasks for all users...");
    taskManager.display_tasks_for_user();

    debug_print("Testing editing task 1 for user 1...");
    task1.task_edit("Updated Unit Tests", "Update unit tests for the project", "2024-03-01", "Testing", PRIO::HIGH);
    taskManager.display_tasks_for_user();

    test_task_operations(task1, task2);

    debug_print("Testing move constructor and assignment operator...");
    Task task3(std::move(task1));
    print_task_priority(task3);
    print_task_priority(task1);  // Task1 should be in an undefined state now
    task1 = task2;
    print_task_priority(task1);

    debug_print("Displaying tasks after move and assignment...");
    taskManager.display_tasks_for_user();

    debug_print("Deleting task 2 for user 2...");
    taskManager.delete_task_for_user(2, 2);
    taskManager.display_tasks_for_user();

    debug_print("Listing all users...");
    taskManager.list_all_users();

    debug_print("All tasks executed successfully.");
    return 0;
}
