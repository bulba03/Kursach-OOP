//
// Created by bulba on 29.09.2021.
//
#include "Person.h"
#include "iostream"
#include "../Speciefic/Work.h"

using namespace std;
namespace People{
template<typename T>
Person<T>::Person(string _name, string _surname, int _age, int _salary,T work) {
    name =  _name;
    surname =  _surname;
    age = _age;
    salary = _salary;
}
template<typename T>
T Person<T>::GetWork() {
    return work;
}
template<typename T>
void Person<T>::GetPersonInfo() {

}}
