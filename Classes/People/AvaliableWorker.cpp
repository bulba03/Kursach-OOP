//
// Created by bulba on 22.11.2021.
//

#include "AvaliableWorker.h"

void AvaliableWorker::SetInfo(int _age, std::string _name, int _salary, int _yearsOfWork, WorkType _type) {
    age=_age;
    name=_name;
    salary = _salary;
    yearsOfWork = _yearsOfWork;
    type=_type;
}

AvaliableWorker::AvaliableWorker(Worker worker) {
    age = worker.GetAge();
    salary = worker.GetSalary();
    name = worker.GetName();
    type = worker.GetWorkType();
    yearsOfWork = rand()%3;
}

WorkType AvaliableWorker::GetType() {
    return type;
}

AvaliableWorker::AvaliableWorker() {
    age=0;
    salary=0;
    name = "null";
    yearsOfWork=0;
    type = WorkType::Designer;
}

int AvaliableWorker::GetYearsOfWork() {
    return yearsOfWork;
}
