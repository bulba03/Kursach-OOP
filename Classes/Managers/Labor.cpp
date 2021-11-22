//
// Created by bulba on 19.11.2021.
//

#include "Labor.h"

std::vector<AvaliableWorker> Labor::GetAvaliableWorkers() {
    return avaliableWorkers;
}

void Labor::Hire(AvaliableWorker avaliableWorker) {

}

void Labor::AddAvaliableWorker(AvaliableWorker avWorker) {
    avaliableWorkers.push_back(avWorker);
}
