//
// Created by bulba on 22.11.2021.
//

#include "AvaliableWorker.h"

void AvaliableWorker::SetInfo(int _age, std::string _surname,std::string _name,std::string _secondName, int _salary, int _yearsOfWork, WorkType _type) {
    age=_age;
    surname=_surname;
    secondName= _secondName;
    name=_name;
    salary = _salary;
    yearsOfWork = _yearsOfWork;
    type=_type;
}

AvaliableWorker::AvaliableWorker(Worker worker) {
    age = worker.GetAge();
    salary = worker.GetSalary();
    surname = worker.GetSurname();
    name = worker.GetName();
    secondName = worker.GetSecondName();
    type = worker.GetWorkType();
    yearsOfWork = rand()%3;
}

WorkType AvaliableWorker::GetType() {
    return type;
}

AvaliableWorker::AvaliableWorker() {
    age=0;
    salary=0;
    surname="null";
    name = "null";
    secondName = "null";
    yearsOfWork=0;
    type = WorkType::Designer;
}

int AvaliableWorker::GetYearsOfWork() {
    return yearsOfWork;
}


