//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_PERSON_H
#define KURSACH_OOP_PERSON_H

#include "string"
class Person {
protected:
    int age;
    std::string name;
    int salary;

public:virtual void ShowInfo();
public: void SetInfo(int _age, char* _name, int _salary);
    std::string GetName();
    int GetAge();
    int GetSalary();
};


#endif //KURSACH_OOP_PERSON_H
