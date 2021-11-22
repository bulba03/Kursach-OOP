//
// Created by bulba on 15.11.2021.
//
#ifndef KURSACH_OOP_SINGLETON_H
#define KURSACH_OOP_SINGLETON_H
#include <string>
template <typename T>
class Singleton
{
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }
protected:
    Singleton() {}
    ~Singleton() {}
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
};
#endif //KURSACH_OOP_SINGLETON_H
