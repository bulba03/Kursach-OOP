//
// Created by bulba on 22.11.2021.
//

#ifndef KURSACH_OOP_AVALIABLEWORKER_H
#define KURSACH_OOP_AVALIABLEWORKER_H


#include "Worker.h"

class AvaliableWorker: public Person {
private:

    int yearsOfWork;
        WorkType type;
public:AvaliableWorker();
        AvaliableWorker(Worker worker);
    void SetInfo(int _age, std::string _name, int _salary, int _yearsOfWork, WorkType _type);
    WorkType GetType();
    int GetYearsOfWork();
};


#endif //KURSACH_OOP_AVALIABLEWORKER_H
