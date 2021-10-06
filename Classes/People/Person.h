//
// Created by bulba on 29.09.2021.
//

#ifndef KURSACH_OOP_PERSON_H
#define KURSACH_OOP_PERSON_H
#include "iostream"
using namespace std;
namespace People {
    template<typename T>
    class Person {
    private:
        string name;
        string surname;
        int age;
        int salary;
        T work;

    public:
        Person(string _name, string _surname, int _age, int _salary, T _work);

    public:
        void ShowInfo();

    public:
        T GetWork();

    public:
        void GetPersonInfo();

    };

}
#endif //KURSACH_OOP_PERSON_H
