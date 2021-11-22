//
// Created by bulba on 15.11.2021.
//

#include "EmployerManager.h"

std::vector<Worker> EmployerManager::GetWorkersList() {
    return workers;
}
void EmployerManager::AddWorker(Worker worker) {
    workers.push_back(worker);
}
