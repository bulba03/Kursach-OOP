//
// Created by bulba on 19.11.2021.
//

#ifndef KURSACH_OOP_LABOR_H
#define KURSACH_OOP_LABOR_H
#include "Singleton.h"
#include "../People/Worker.h"

class Labor: Singleton<Labor> {
private: std::vector<Worker> avaliableWorkers;
public:std::vector<Worker> GetAvaliableWorkers();
};


#endif //KURSACH_OOP_LABOR_H
