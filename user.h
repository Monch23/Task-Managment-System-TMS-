#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "task.h"
#include "encrypt.h"
class Task;

class User {
    private:
        size_t m_uid;
        static int m_unique_user_id;
        std::string m_name;
        std::string m_passwd;
        std::vector<Task*> m_tasks;
        bool m_is_logged{false};
    public:
        User(const std::string &name, const std::string &passwd);
        User(const User&) = delete;
        User(User &&other);
        ~User();
        
        friend std::ostream &operator<<(std::ostream &ostr, const User &output);
        friend class TaskManager;
        
        void add_task(Task *task);
        void delete_task(int task_id);
        void user_task_editor(int task_id,
            const std::string &new_title,
            const std::string &new_description,
            const std::string &new_deadline,
            const std::string &new_category,
            PRIO new_priority);
        void list_tasks(void) const;
        Task *search_task(int task_id);
        void login(void);
        void logout(void);
        operator bool();
        bool operator!();
        void show_passwd(void);
        friend void decode(const std::string &);
        friend void encode(std::string &);
};

#endif