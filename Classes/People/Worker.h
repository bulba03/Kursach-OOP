//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_WORKER_H
#define KURSACH_OOP_WORKER_H

#include <vector>
#include "Person.h"
#include "../Enums/WorkType.h"
using namespace std;
class Worker : public Person {
private:
    WorkType workType;
    struct EmployementDate{
      int year;
      int month;
      int day;
    } empDate;
    public:
        Worker(int _age, int _salary,std::string _surname, std::string _name,std::string _secondName,WorkType type);

    const EmployementDate getEmpDate();

    void ShowInfo() override;
    int GetAge() override;
    int GetSalary() override;
    std::string GetSurname() override;
    std::string GetSecondName() override;
    void SetInfo(int _age, int _salary,std::string _surname, std::string _name,std::string _secondName, WorkType _type,int year, int month, int day);
    void SetInfo(int _age, int _salary, std::string _name, WorkType _type);
    std::string GetName() override;
    WorkType GetWorkType();
    void SetWorkType(WorkType type);

    Worker();
};
#endif //KURSACH_OOP_WORKER_H
