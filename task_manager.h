#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include "user.h"
#include "task.h"
#include <string>
#include <vector>

class TaskManager {
    private:
        std::vector<User*> m_users;
        std::vector<Task*> m_all_tasks;
        public:
        TaskManager();
        TaskManager(const TaskManager &other);
        TaskManager(TaskManager &&other);
        ~TaskManager();
    
        void display_tasks_for_user(void) const;
        void add_task_for_user(int uid, Task *task);
        void register_user(const std::string &name, const std::string &passwd);
        void register_user(User *user);
        Task add_task(const std::string &title,
            const std::string &description,
            const std::string &deadline,
            const std::string &category,
            PRIO prio);
        void edit_task_for_user(int task_id,
            const std::string &title,
            const std::string &description,
            const std::string &deadline,
            const std::string &category,
            PRIO prio);
        void delete_task_for_user(int uid, int task_id);
        void list_all_users(void) const;
};

#endif