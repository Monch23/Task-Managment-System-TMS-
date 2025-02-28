#include "user.h"
#include "task.h"
#include "print_colors.h"
#include "encrypt.h"
#include <iostream>

int User::m_unique_user_id = 0;

// parametric ctor
User::User(const std::string &name, const std::string &passwd) : m_name{name}, m_passwd{passwd} {
    encode(m_passwd);
    m_uid = ++m_unique_user_id;
}

// move ctor
User::User(User &&other) :
    m_uid{other.m_uid},
    m_name{std::move(other.m_name)},
    m_passwd{std::move(other.m_passwd)},
    m_tasks{std::move(other.m_tasks)}
{
    other.m_uid = -1;
}

// dtor
User::~User() {}

std::ostream &operator<<(std::ostream &ostr, const User &output) {
    ostr << GREEN << "ID: " << RESET << output.m_uid << std::endl;
    ostr << GREEN << "Name: " << RESET << output.m_name << std::endl;
    
    if (output.m_is_logged == true) {
        ostr << GREEN << "Online" RESET << std::endl;
    } else {
        ostr << RED << "Offline" << RESET << std::endl;
    }

    ostr << YELLOW << "Hashed Password: " << RESET << output.m_passwd << std::endl;

    return ostr;
}

void User::add_task(Task *task) {
    m_tasks.push_back(task);
}

void User::delete_task(int task_id) {
    int tasks_count = m_tasks.size();
    for (int i = 0; i < tasks_count; ++i) {
        if (m_tasks[i]->m_task_id == task_id) {
            m_tasks.erase(m_tasks.begin() + i);
            return;
        }
    }

    std::cout << RED << "Task doesn't exist" << RESET << std::endl;
}

void User::user_task_editor(int task_id,
    const std::string &new_title,
    const std::string &new_description,
    const std::string &new_deadline,
    const std::string &new_category,
    PRIO new_priority)
{
    size_t tasks_count = m_tasks.size();

    if (tasks_count < task_id || tasks_count > task_id) {
        std::cout << RED << "Task ID doesn't exist" << RESET << std::endl;
        return;
    }

    if (new_priority < PRIO::LOW || new_priority > PRIO::URG) {
        std::cout << RED << "Priority doesn't exist" << RESET << std::endl;
        return;
    }

    for (int i = 0; i < tasks_count; ++i) {
        if (m_tasks[i]->m_task_id == task_id) {
            m_tasks[i]->m_title = new_title;
            m_tasks[i]->m_description = new_description;
            m_tasks[i]->m_deadline = new_deadline;
            m_tasks[i]->m_category = new_category;
            m_tasks[i]->m_priority = new_priority;
            return;
        }
    }

    std::cout << "Task ID doesn't exist" << std::endl;
}

void User::list_tasks(void) const {
    size_t tasks_count = m_tasks.size();

    std::cout << YELLOW << "User (" << m_uid << ")'s " << "tasks" << RESET << std::endl; 
    if (tasks_count == 0) {
        std::cout << RED << "No tasks yet" RESET << std::endl;
        return;
    }

    for (int i = 0; i < tasks_count; ++i) {
        std::cout << GREEN << "Title: " << RESET << m_tasks[i]->m_title << std::endl;
        std::cout << GREEN << "Description: " << RESET << m_tasks[i]->m_description << std::endl;
        std::cout << GREEN << "Deadline: " << RESET << m_tasks[i]->m_deadline << std::endl;
        std::cout << GREEN << "Category: " << RESET << m_tasks[i]->m_category << std::endl;
        std::cout << GREEN << "Priority: " << RESET;

        if (m_tasks[i]->m_priority == PRIO::LOW) {
            std::cout << "low" << std::endl;
        } else if (m_tasks[i]->m_priority == PRIO::MID) {
            std::cout << "middle" << std::endl;
        } else if (m_tasks[i]->m_priority == PRIO::HIGH) {
            std::cout << "high" << std::endl;
        } else if (m_tasks[i]->m_priority == PRIO::URG) {
            std::cout << "urgant" << std::endl;
        }
    }
}

Task *User::search_task(int task_id) {
    size_t tasks_count = m_tasks.size();

    for (int i = 0; i < tasks_count; ++i) {
        if (m_tasks[i]->m_task_id == task_id) {
            return m_tasks[i];
        }
    }

    return nullptr;
}

void User::login(void) {
    if (m_is_logged == true) {
        std::cout << GREEN << (m_name + "(ID: ") << m_uid << ") " << "is logged in" << RESET << std::endl;
        return;
    }

    m_is_logged = true;
}

void User::logout(void) {
    if (m_is_logged == false) {
        std::cout << RED << (m_name + "(ID: ") << m_uid << ") " << "is logged out" << RESET << std::endl;
        return;
    }
    
    m_is_logged = false;
}

User::operator bool() {
    return (m_is_logged) ? true : false;
}

bool User::operator!() {
    return (!m_is_logged) ? true : false;
}

void User::show_passwd(void) {
    decode(m_passwd);
}