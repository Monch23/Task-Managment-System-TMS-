#ifndef TASK_H
#define TASK_H
#include <string>
class User;

enum PRIO {
    INVALID_PRIO,
    LOW,
    MID,
    HIGH,
    URG
};

enum STATUS {
    INVALID_STATUS,
    NOT_STARTED,
    IN_PROGRESS,
    COMPLETED
};

class Task {
    private:
    int m_task_id;
    std::string m_title;
    std::string m_description;
    std::string m_deadline;
    std::string m_category;
    int m_uid;
    STATUS m_status;
    PRIO m_priority;
    static int m_task_unique_id;
    Task(const Task &other);
    public:
        Task();
        Task(const std::string &title,
            const std::string &description, 
            const std::string &deadline, 
            const std::string &category, 
            PRIO priority);
        Task(Task &&other) noexcept;
        Task &operator=(const Task &rhs);
        Task &operator=(Task &&rhs) noexcept;
        Task &operator++();
        Task operator++(int);
        Task &operator--();
        Task operator--(int);
        bool operator==(const Task &other);
        bool operator!=(const Task &other);
        bool operator>(const Task &other);
        bool operator<(const Task &other);
        friend std::ostream &operator<<(std::ostream &ostr, const Task &output);
        friend std::istream &operator>>(const std::istream &ostr, Task &output);
        ~Task();

        friend class User;
        friend class TaskManager;

        void task_edit(const std::string &new_title,
            const std::string &new_description,
            const std::string &new_deadline,
            const std::string &new_category,
            PRIO new_priority);
        void set_status(STATUS status);
        void set_priority(PRIO prio);
        int get_task_id(void) const;
        int get_priority(const Task &task) const;
        void display_info(void) const;
};

#endif