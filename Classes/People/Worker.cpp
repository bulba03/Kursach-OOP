//
// Created by bulba on 15.11.2021.
//

#include "Worker.h"
#include "../Managers/Singleton.h"
#include "../Managers/EmployerManager.h"

Task *Worker::GetActiveTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks.at(i).state == TaskState::Active) {
                return &tasks.at(i);
            }
        }
        return nullptr;
    }

    void Worker::ShowInfo() {
        Person::ShowInfo();
        auto b = GetActiveTasks();
        if (b != nullptr) {
            cout << "Active Task: " << b->taskTitle << endl;
            cout << "Task discription:" << b->taskDiscription << endl;
        } else {
            cout << name << " Net activnix zadach" << endl;
        }
    }

    int Worker::GetAge() {
        return Person::GetAge();
    }

    int Worker::GetSalary() {
        return Person::GetSalary();
    }

    string Worker::GetName() {
        return Person::GetName();
    }

Worker::Worker() {
        age = 10;
        name = "ASAS";
        salary = 10;
        auto task = Task();
        tasks.push_back(task);
        Singleton<EmployerManager>::getInstance().AddWorker(*this);

}

vector<Task> Worker::GetAllTasks() {
    return tasks;
}
