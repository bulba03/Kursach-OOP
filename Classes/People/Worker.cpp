//
// Created by bulba on 15.11.2021.
//

#include "Worker.h"
#include "../Managers/Singleton.h"
#include "../Managers/EmployerManager.h"
#include "AvaliableWorker.h"

void Worker::ShowInfo() {
        Person::ShowInfo();
    }

    int Worker::GetAge() {
        return Person::GetAge();
    }

    int Worker::GetSalary() {
        return Person::GetSalary();
    }

    std::string Worker::GetName() {
        return Person::GetName();
    }

Worker::Worker(int _age, int _salary, std::string _name,WorkType type) {
        age = _age;
        name = _name;
        salary = _salary;
        workType = type;
        Singleton<EmployerManager>::getInstance().AddWorker(*this);

}

WorkType Worker::GetWorkType() {
    return workType;
}

WorkType Worker::SetWorkType(WorkType type) {
    workType=type;
}

Worker::Worker() {
    age=0;
    name="null";
    salary=0;
}

void Worker::SetInfo(int _age, int _salary, std::string _name, WorkType _type) {
    age= _age;
    salary=_salary;
    name = _name;
    workType =_type;

}
/*
Worker::Worker(AvaliableWorker avaliableWorker) {
    age = avaliableWorker.GetAge();
    salary = avaliableWorker.GetSalary();
    name = avaliableWorker.GetName();
    workType = avaliableWorker.GetType();
    */



