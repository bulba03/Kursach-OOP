//
// Created by bulba on 15.11.2021.
//

#include <iostream>
#include "Person.h"
#include "string"
#include "../Enums/WorkType.h"

using namespace std;
    void Person::SetInfo(int _age, std::string _name, int _salary) {
        age = _age;
        name = _name;
        salary = _salary;
    }

    std::string Person::GetName() {
        return name;
    }

    int Person::GetAge() {
        return age;
    }

    int Person::GetSalary() {
        return salary;
    }

    void Person::ShowInfo() {
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
        cout << "Name: " << name << endl;
    }

std::string Person::GetSecondName() {
    return secondName;
}

std::string Person::GetSurname() {
    return surname;
}
