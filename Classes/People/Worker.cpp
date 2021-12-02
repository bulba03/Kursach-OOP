//
// Created by bulba on 15.11.2021.
//

#include "Worker.h"
#include "../Managers/Singleton.h"
#include "../Managers/EmployerManager.h"
#include "ctime"
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

Worker::Worker(int _age, int _salary, std::string _surname,std::string _name,std::string _secondName,WorkType type) {
        time_t now = time(0);   // get time now
        tm *ltm = localtime(&now);
        empDate.year=ltm->tm_year+1900;
        empDate.month = ltm->tm_mon+1;
        empDate.day = ltm->tm_mday;
        age = _age;
        surname = _surname;
        name = _name;
        secondName=_secondName;
        salary = _salary;
        workType = type;
        Singleton<EmployerManager>::getInstance().AddWorker(*this);

}

WorkType Worker::GetWorkType() {
    return workType;
}
 void Worker::SetWorkType(WorkType type) {
    workType=type;
}

Worker::Worker() {
    age=0;
    name="null";
    salary=0;
}

void Worker::SetInfo(int _age, int _salary,std::string _surname, std::string _name, std::string _secondName,WorkType _type,int year, int month, int day) {
    age= _age;
    salary=_salary;
    surname = _surname;
    name = _name;
    secondName = _secondName;
    workType =_type;
    empDate.year=year;
    empDate.month=month;
    empDate.day=day;

}

const Worker::EmployementDate Worker::getEmpDate(){
    return empDate;
}

void Worker::SetInfo(int _age, int _salary, std::string _name, WorkType _type) {
    age = _age;
    salary =_salary;
    name = _name;
    workType = _type;
}
std::string Worker::GetSurname() {
    return Person::GetSurname();
}

std::string Worker::GetSecondName() {
    return Person::GetSecondName();
}
/*
Worker::Worker(AvaliableWorker avaliableWorker) {
    age = avaliableWorker.GetAge();
    salary = avaliableWorker.GetSalary();
    name = avaliableWorker.GetName();
    workType = avaliableWorker.GetType();
    */



