//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_WORKER_H
#define KURSACH_OOP_WORKER_H

#include <vector>
#include "../Speciefic/Task.h"
#include "Person.h"

class Worker : public Person {
    public:
        vector<Task> tasks;
        Worker();

        void ShowInfo() override;

        int GetAge() override;

        int GetSalary() override;

        string GetName() override;

        Task *GetActiveTasks();
        vector<Task> GetAllTasks();
};
#endif //KURSACH_OOP_WORKER_H
