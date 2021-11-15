//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_EMPLOYERMANAGER_H
#define KURSACH_OOP_EMPLOYERMANAGER_H


#include "../People/Person.h"
#include "Singleton.h"
#include <vector>
class EmployerManager: public Singleton<EmployerManager>{
public: static std::vector<Person> workers;
public: std::vector<Person> GetWorkersList()
    {
        return EmployerManager::workers;
    }
    static void AddWorker(Person worker)
    {
        workers.push_back(worker);
    }
};


#endif //KURSACH_OOP_EMPLOYERMANAGER_H
