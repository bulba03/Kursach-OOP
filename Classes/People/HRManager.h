//
// Created by bulba on 29.09.2021.
//

#ifndef KURSACH_OOP_HRMANAGER_H
#define KURSACH_OOP_HRMANAGER_H


#include "Person.h"
namespace People {
    class HRManager {
    public:
        void ApplyForAJob(Person person);

    public:
        void RetirePerson(Person person);

    public:
        void ShowPersonInfo(Person person);

    public:
        void GetAllWorkers();

    public:
        void WriteInFile();
    };

}
#endif //KURSACH_OOP_HRMANAGER_H
