//
// Created by bulba on 19.11.2021.
//

#ifndef KURSACH_OOP_LABOR_H
#define KURSACH_OOP_LABOR_H
#include "Singleton.h"
#include "../People/Worker.h"
#include "../People/AvaliableWorker.h"

class Labor: Singleton<Labor> {
private: std::vector<AvaliableWorker> avaliableWorkers;
public:std::vector<AvaliableWorker> GetAvaliableWorkers();
        void AddAvaliableWorker(Worker worker);
        void Hire(AvaliableWorker avaliableWorker);

    void AddAvaliableWorker(AvaliableWorker avWorker);
};


#endif //KURSACH_OOP_LABOR_H
