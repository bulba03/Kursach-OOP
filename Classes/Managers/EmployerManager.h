//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_EMPLOYERMANAGER_H
#define KURSACH_OOP_EMPLOYERMANAGER_H

#include <vector>
#include "Singleton.h"
#include "../People/Worker.h"
class EmployerManager: public Singleton<EmployerManager>{
public: std::vector<Worker> workers;
     std::vector<Worker> GetWorkersList();
     void AddWorker(Worker worker);
     std::vector<Worker> FindByParameter();

private:
    std::vector<Worker> FindByName(std::string _name);
    bool isValueInRange(int val, int min, int max);
    std::vector<Worker> FindBySalary(int min, int max);
    std::vector<Worker> FindByWorkType(WorkType type);

    std::vector<Worker> FindByAge(int min, int max);
};


#endif //KURSACH_OOP_EMPLOYERMANAGER_H
