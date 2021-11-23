//
// Created by bulba on 15.11.2021.
//

#include <iostream>
#include "EmployerManager.h"

std::vector<Worker> EmployerManager::GetWorkersList() {
    return workers;
}
void EmployerManager::AddWorker(Worker worker) {
    workers.push_back(worker);
}

std::vector<Worker> EmployerManager::FindByParameter() {
    char c;
    std::cout<<"�������� �������� ��� ������:\n1)���\n2)��������\n3)�������������\n4)�������"<<std::endl;
    std::cin>>c;
    while(c!='5')
    {
    switch (c) {
        case '1': {
            std::string _name;
            std::cout << "������� ��� ��� ������: ";
            std::cin >> _name;
            auto found = FindByName(_name);
            if (!found.empty()) {
                std::cout << "������� �������!" << std::endl;
                return found;
            }
            std::cout<<"������� � ����� ������ ���!"<<std::endl;
            break;
        }
        case '2': {
            int min, max;
            std::cout << "������� ����������� �������� ��� ������:";
            std::cin >> min;
            std::cout<<"������� ������������ �������� ��� ������:";
            std::cin>>max;
            auto found = FindBySalary(min,max);
            if(!found.empty())
            {
                std::cout<<"������� ������!"<<std::endl;
                return found;
            }
            std::cout<<"��� �� ������ �������� ������� �� ������������� ��������� ������!"<<std::endl;
            break;
        }
        case '3': {
            int choise;
            std::cout<<"�������� ������������� ��� ������:\n1)��������\n2)�����������\n3)����. ��������\n4)��\n5)������ ��������"<<std::endl;
            std::cin>>choise;
            auto found =FindByWorkType((WorkType)choise);
            if(!found.empty())
            {
                std::cout<<"������� �������!"<<std::endl;
                return found;
            }
            std::cout<<"��� �� ������ �������� ������� �� ������������� ��������� ������!"<<std::endl;
            break;
        }
        case '4': {
            int ageMin,ageMax;
            std::cout<<"������� ����������� ������� ��� ������: ";
            std::cin>>ageMin;
            std::cout<<"������� ������������ ������� ��� ������: ";
            std::cin>>ageMax;
            auto found = FindByAge(ageMin,ageMax);
            if(!found.empty()) {
                std::cout << "������� �������!" << std::endl;
                return found;
            }

            std::cout<<"��� �� ������ �������� ������� �� ������������� ��������� ������!"<<std::endl;
            break;
        }

    }
    }
}

std::vector<Worker> EmployerManager::FindByName(std::string _name) {
    std::vector<Worker> matchWorkers;
    for(int i=0;i<workers.size();i++)
    {
        if(workers[i].GetName() == _name)
        {
            matchWorkers.push_back(workers[i]);
        }
    }
    return matchWorkers;
}
std::vector<Worker> EmployerManager::FindBySalary(int min, int max)
{
    std::vector<Worker> matchWorkers;
    for (int i = 0; i < workers.size(); i++) {
        if(isValueInRange(workers[i].GetSalary(),min,max))
        {
            matchWorkers.push_back(workers[i]);
        }
    }
    return matchWorkers;
}

bool EmployerManager::isValueInRange(int val, int min, int max) {
    if(val>=min&&val<=max)
    {
        return true;
    }
    return false;
}

std::vector<Worker>EmployerManager::FindByWorkType(WorkType type) {
    std::vector<Worker> matchWorkers;
    for(int i=0;i<workers.size();i++)
    {
        if(type==workers[i].GetWorkType())
        {
            matchWorkers.push_back(workers[i]);
        }
    }
    return matchWorkers;
}

std::vector<Worker>EmployerManager::FindByAge(int min, int max) {
    std::vector<Worker> matchWorkers;
    for(int i=0;i<workers.size();i++)
    {
        if(isValueInRange(workers[i].GetAge(),min,max))
        {
            matchWorkers.push_back(workers[i]);
        }
    }
    return matchWorkers;
}
