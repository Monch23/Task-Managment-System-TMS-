#include "user.h"
#include "task.h"
#include "task_manager.h"
#include "print_colors.h"
#include "encrypt.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>
TaskManager::TaskManager() {}

TaskManager::TaskManager(const TaskManager &other) :
    m_users{other.m_users},
    m_all_tasks{other.m_all_tasks}
{}

TaskManager::TaskManager(TaskManager &&other) :
    m_users{std::move(other.m_users)},
    m_all_tasks{std::move(other.m_all_tasks)}
{}

TaskManager::~TaskManager() {
    size_t all_tasks = m_all_tasks.size();
    for (int i = 0; i < all_tasks; ++i) {
        delete m_all_tasks[i];
    }
}

void TaskManager::display_tasks_for_user(void) const {
    size_t users_count = m_users.size();
    
    for (int i = 0; i < users_count; ++i) {
        m_users[i]->list_tasks();
        std::cout << "---------------" << std::endl << std::endl;
    }
}

void TaskManager::add_task_for_user(int uid, Task *task) {
    size_t users_count = m_users.size();

    for (int i = 0; i < users_count; ++i) {
        if (m_users[i]->m_uid == uid) {
            task->m_uid = m_users[i]->m_uid;
            m_users[i]->m_tasks.push_back(task);
            return;
        }
    }

    std::cout << "User ID doesn't exist" << std::endl;
}

void TaskManager::register_user(const std::string &name, const std::string &passwd) {
    User *tmp_usr = new User(name,passwd);
    m_users.push_back(tmp_usr);
}

void TaskManager::register_user(User *user) {
    m_users.push_back(user);
}

Task TaskManager::add_task(const std::string &title,
    const std::string &description,
    const std::string &deadline,
    const std::string &category,
    PRIO prio)
{
    Task *tmp_task = new Task{title, description, deadline, category, prio};
    m_all_tasks.push_back(tmp_task);

    return *tmp_task;
}

void TaskManager::edit_task_for_user(int task_id, 
    const std::string &title,
    const std::string &description,
    const std::string &deadline,
    const std::string &category,
    PRIO prio)
{
    size_t tasks_count = m_all_tasks.size();

    for (int i = 0; i < tasks_count; ++i) {
        if (m_all_tasks[i]->m_task_id == task_id) {
            m_all_tasks[i]->task_edit(title, description, deadline, category, prio);
            return;
        }
    }

    std::cout << "Task ID doesn't exist" << std::endl;
}

void TaskManager::delete_task_for_user(int uid, int task_id) {
    size_t users_count = m_users.size();
    size_t tasks_count = m_all_tasks.size();

    for (int i = 0; i < users_count; ++i) {
        if (m_users[i]->m_uid == uid) {
            if (m_users[i]->search_task(task_id) != nullptr) {
                m_users[i]->delete_task(task_id);
                break;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < tasks_count; ++i) {
        if (m_all_tasks[i]->m_task_id == task_id) {
            m_all_tasks.erase(m_all_tasks.begin() + i);
            return;
        }
    }

    std::cout << "Task ID or User ID doesn't exist" << std::endl;
}

void TaskManager::list_all_users(void) const {
    size_t users_count = m_users.size();

    if (!users_count) {
        std::cout << RED << "No users yet !" << RESET << std::endl;
        return;
    }

    for (int i = 0; i < users_count; ++i) {
        std::cout << *m_users[i];
        std::cout << "---------------" << std::endl;
    }
}