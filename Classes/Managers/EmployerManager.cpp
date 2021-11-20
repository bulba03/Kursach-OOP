//
// Created by bulba on 15.11.2021.
//

#include "EmployerManager.h"

vector<Worker> EmployerManager::GetWorkersList() {
    return workers;
}

void EmployerManager::AddWorker(Worker worker) {
    workers.push_back(worker);

}

std::vector<Worker> EmployerManager::GetFreeWorkers() {
    vector<Worker> freeWorkers;
    for(auto worker : workers)
    {
        if(worker.tasks.empty())
        {
            freeWorkers.push_back(worker);
        }
    }
    return freeWorkers;
}
