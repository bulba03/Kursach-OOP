//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_WORKER_H
#define KURSACH_OOP_WORKER_H

#include <vector>
#include "Person.h"
#include "../Enums/WorkType.h"

class Worker : public Person {
private:
    WorkType workType;
    public:
        Worker(int _age, int _salary, std::string _name,WorkType type);
        void ShowInfo() override;
        int GetAge() override;
        int GetSalary() override;
        void SetInfo(int _age, int _salary, std::string _name, WorkType _type);
        std::string GetName() override;
        WorkType GetWorkType();
        WorkType SetWorkType(WorkType type);

    Worker();
};
#endif //KURSACH_OOP_WORKER_H
