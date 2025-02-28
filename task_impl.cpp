#include "task.h"
#include "user.h"
#include <iostream>
#include "print_colors.h"
int Task::m_task_unique_id = 0;

// default ctor 
Task::Task() :
    m_task_id{STATUS::INVALID_STATUS},
    m_title{"undefined"},
    m_description{"undefined"},
    m_deadline{"undefined"},
    m_category{"undefined"},
    m_uid{STATUS::INVALID_STATUS},
    m_status{STATUS::INVALID_STATUS},
    m_priority{PRIO::INVALID_PRIO}
{}

// parametric ctor
Task::Task(const std::string &title,
    const std::string &description, 
    const std::string &deadline, 
    const std::string &category, 
    PRIO priority) :
        m_title{title},
        m_description{description},
        m_deadline{deadline},
        m_category{category},
        m_status{STATUS::NOT_STARTED},
        m_priority{priority}
{
    m_task_id = ++m_task_unique_id;
}

// copy ctor
Task::Task(const Task &other) :
    m_task_id{other.m_task_id},
    m_title{other.m_title},
    m_description{other.m_description},
    m_deadline{other.m_deadline},
    m_category{other.m_category},
    m_uid{other.m_uid},
    m_status{STATUS::NOT_STARTED},
    m_priority{other.m_priority}
{}

// move ctor
Task::Task(Task &&other) noexcept :
    m_task_id{other.m_task_id},
    m_title{std::move(other.m_title)},
    m_description{std::move(other.m_description)},
    m_deadline{std::move(other.m_deadline)},
    m_category{std::move(other.m_category)},
    m_uid{other.m_uid},
    m_status{STATUS::NOT_STARTED},
    m_priority{other.m_priority}
{
    other.m_task_id = STATUS::INVALID_STATUS;
    other.m_uid = STATUS::INVALID_STATUS;
    other.m_priority = PRIO::INVALID_PRIO;
}

// dtor
Task::~Task() {}


// copy assignment
Task &Task::operator=(const Task &rhs) {
    if (this == &rhs) {
        return *this;
    }
    
    m_task_id = rhs.m_task_id;
    m_title = rhs.m_title;
    m_description = rhs.m_title;
    m_deadline = rhs.m_deadline;
    m_category = rhs.m_category;
    m_uid = rhs.m_uid;
    m_status = rhs.m_status;
    m_priority = rhs.m_priority;
    
    return *this;
}

Task &Task::operator=(Task &&rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }
    
    m_task_id = rhs.m_task_id;
    m_title = std::move(rhs.m_title);
    m_description = std::move(rhs.m_description);
    m_deadline = std::move(rhs.m_deadline);
    m_category = std::move(rhs.m_category);
    m_uid = rhs.m_uid;
    m_status = rhs.m_status;
    m_priority = rhs.m_priority;
    
    return *this;
}

Task &Task::operator++() {
    switch (m_priority) {
        case (INVALID_PRIO) :
            m_priority = LOW;
            break;
        case (LOW) :
            m_priority = MID;
            break;
        case (MID) :
            m_priority = HIGH;
            break;
        case (HIGH) :
            m_priority = URG;
            break;
        case (URG) :
            std::cout << RED << "Task have a maximum priority" << RESET << std::endl;
            break;
    }

    return *this;
}

Task Task::operator++(int) {
    Task temp(*this);
    
    switch (m_priority) {
        case (INVALID_PRIO) :
            m_priority = LOW;
            break;
        case (LOW) :
            m_priority = MID;
            break;
        case (MID) :
            m_priority = HIGH;
            break;
        case (HIGH) :
            m_priority = URG;
            break;
        case (URG) :
            std::cout << RED << "Task have a maximum priority" << RESET << std::endl;
            break;
    }

    return std::move(temp);
}

Task &Task::operator--() {
    switch (m_priority) {
        case (INVALID_PRIO) :
            std::cout << RED << "Task have a invalid priority" << RESET << std::endl;
            break;
        case (LOW) :
            m_priority = INVALID_PRIO;
            break;
        case (MID) :
            m_priority = LOW;
            break;
        case (HIGH) :
            m_priority = MID;
            break;
        case (URG) :
            m_priority = HIGH;
            break;
    }

    return *this;
}

Task Task::operator--(int) {
    Task temp(*this);
    
    switch (m_priority) {
        case (INVALID_PRIO) :
            std::cout << RED << "Task have a invalid priority" << RESET << std::endl;
            break;
        case (LOW) :
            m_priority = INVALID_PRIO;
            break;
        case (MID) :
            m_priority = LOW;
            break;
        case (HIGH) :
            m_priority = MID;
            break;
        case (URG) :
            m_priority = HIGH;
            break;
    }

    return std::move(temp);
}

bool Task::operator==(const Task &other) {
    return (m_priority == other.m_priority) ? true : false;
}

bool Task::operator!=(const Task &other) {
    return (m_priority != other.m_priority) ? true : false;
}

bool Task::operator>(const Task &other) {
    return (m_priority > other.m_priority) ? true : false;
}

bool Task::operator<(const Task &other) {
    return (m_priority < other.m_priority) ? true : false;
}

std::ostream &operator<<(std::ostream &ostr, const Task &output) {
    ostr << "Task ID: " << output.m_task_id << std::endl;
    ostr << "Title: " << output.m_title << std::endl;
    ostr << "Description: " << output.m_description << std::endl;
    ostr << "Deadline: " << output.m_deadline << std::endl;
    ostr << "Category: " << output.m_category << std::endl;
    ostr << "User ID: " << output.m_uid << std::endl;

    ostr << "Status: ";
    switch (output.m_status) {
        case (STATUS::INVALID_STATUS) :
            ostr << "invalid" << std::endl;
            break;
        case (STATUS::NOT_STARTED) :
            ostr << "not started" << std::endl;
            break;
        case (STATUS::IN_PROGRESS) :
            ostr << "in progress" << std::endl;
            break;
        case (STATUS::COMPLETED) :
            ostr << "completed" << std::endl;
            break;
    }

    ostr << "Priority: ";
    switch (output.m_priority) {
        case (PRIO::INVALID_PRIO) :
            ostr << "invalid" << std::endl;
            break;
        case (PRIO::LOW) :
            ostr << "low" << std::endl;
            break;
        case (PRIO::MID) :
            ostr << "mid" << std::endl;
            break;
        case (PRIO::HIGH) :
            ostr << "high" << std::endl;
            break;
        case (PRIO::URG) :
            ostr << "urgent" << std::endl;
            break;
    }

    return ostr;
}


void Task::task_edit(const std::string &new_title,
    const std::string &new_description,
    const std::string &new_deadline,
    const std::string &new_category,
    PRIO new_priority)
{
    if (new_priority < PRIO::INVALID_PRIO || new_priority > PRIO::URG) {
        std::cout << "Invalid priority" << std::endl;
        return;
    }

    m_title = new_title;
    m_description = new_description;
    m_deadline = new_deadline;
    m_category = new_category;
    m_priority = new_priority;
}

void Task::set_status(STATUS status) {
    if (status < STATUS::INVALID_STATUS || status > STATUS::COMPLETED) {
        std::cout << "Invalid status" << std::endl;
        return;
    }

    m_status = status;
}

void Task::set_priority(PRIO prio) {
    if (prio < PRIO::INVALID_PRIO || prio > PRIO::URG) {
        std::cout << "Invalid priority" << std::endl;
        return;
    }

    m_priority = prio;
}

int Task::get_task_id(void) const {
    return m_task_id;
}

int Task::get_priority(const Task &task) const {
    return m_priority;
}


void Task::display_info(void) const {
    if (m_task_unique_id == 0) {
        return;
    }

    std::cout << this;
}