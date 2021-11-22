//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_PERSON_H
#define KURSACH_OOP_PERSON_H
#include "string"
#include "../Enums/WorkType.h"

class Person {
    protected:
        int age;
        std::string name;
        int salary;

    public:
        virtual void ShowInfo();
        virtual void SetInfo(int _age, std::string _name, int _salary);
        virtual std::string GetName();
        virtual int GetAge();
        virtual int GetSalary();
    };

#endif //KURSACH_OOP_PERSON_H
