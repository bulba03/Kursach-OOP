//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_WORKER_H
#define KURSACH_OOP_WORKER_H


#include "Person.h"
#include <vector>
#include "../Speciefic/Task.h"
#include "../Managers/EmployerManager.h"

class Worker: public Person {
public: vector<Task> tasks;
    Worker()
    {
        age=10;
        name= "ASAS";
        salary=10;
        auto task = Task();
        tasks.push_back(task);
        EmployerManager::getInstance().AddWorker(*this);
    };
    void ShowInfo() override;
    Task* GetActiveTasks();
};


#endif //KURSACH_OOP_WORKER_H
