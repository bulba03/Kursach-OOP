//
// Created by bulba on 19.11.2021.
//

#include <iostream>
#include "Labor.h"

std::vector<AvaliableWorker> Labor::GetAvaliableWorkers() {
    return avaliableWorkers;
}

void Labor::Hire(AvaliableWorker avaliableWorker) {

}

void Labor::AddAvaliableWorker(AvaliableWorker avWorker) {
    std::cout<<"avWorker!!"<< avWorker.GetName()<<std::endl;
    avaliableWorkers.push_back(avWorker);
    std::cout<<avaliableWorkers.size()<<std::endl;
}

