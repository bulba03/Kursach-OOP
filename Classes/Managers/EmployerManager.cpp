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
    std::cout<<"Выберите параметр для поиска:\n1)Имя\n2)Зарплата\n3)Специализация\n4)Возраст"<<std::endl;
    std::cin>>c;
    while(c!='5')
    {
    switch (c) {
        case '1': {
            std::string _name;
            std::cout << "Введите имя для поиска: ";
            std::cin >> _name;
            auto found = FindByName(_name);
            if (!found.empty()) {
                std::cout << "Рабочие найдены!" << std::endl;
                return found;
            }
            std::cout<<"Рабочих с таким именем нет!"<<std::endl;
            break;
        }
        case '2': {
            int min, max;
            std::cout << "Введите минимальное значение для поиска:";
            std::cin >> min;
            std::cout<<"Введите максимальное значение для поиска:";
            std::cin>>max;
            auto found = FindBySalary(min,max);
            if(!found.empty())
            {
                std::cout<<"Рабочие найдеы!"<<std::endl;
                return found;
            }
            std::cout<<"Нет ни одного рабочего который бы соответстовал введенным данным!"<<std::endl;
            break;
        }
        case '3': {
            int choise;
            std::cout<<"Выберите специальность для поиска:\n1)Дизайнер\n2)Программист\n3)Техн. художник\n4)ПМ\n5)Бизнес аналитик"<<std::endl;
            std::cin>>choise;
            auto found =FindByWorkType((WorkType)(choise-1));
            if(!found.empty())
            {
                std::cout<<"Рабочие найдены!"<<std::endl;
                return found;
            }
            std::cout<<"Нет ни одного рабочего который бы соответстовал введенным данным!"<<std::endl;
            break;
        }
        case '4': {
            int ageMin,ageMax;
            std::cout<<"Введите минимальный возраст для поиска: ";
            std::cin>>ageMin;
            std::cout<<"Введите максимальный возраст для поиска: ";
            std::cin>>ageMax;
            auto found = FindByAge(ageMin,ageMax);
            if(!found.empty()) {
                std::cout << "Рабочие найдены!" << std::endl;
                return found;
            }

            std::cout<<"Нет ни одного рабочего который бы соответстовал введенным данным!"<<std::endl;
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

std::vector<Worker> EmployerManager::Sort() {
    std::cout<<"Выберите параметр для сортировки:\n1)Возраст\n2)Зарплата\n3)Дата принятия на работу"<<std::endl;
    char ch;
    switch (ch) {
        case '1':
        {
            SortByAge();
        }break;
        case '2':
        {
            SortBySalary();
        }break;
        case '3':
        {
            SortByEmpDate();
        }break;
        default:cout<<"Нет такого варианта!"<<endl;
    }
    return workers;
}

void EmployerManager::SortByAge() {
    sort(workers.begin(),workers.end(),[](Worker& w1,Worker& w2)
    {
        return w1.GetAge()>w2.GetAge();
    });
}

void EmployerManager::SortBySalary() {
    sort(workers.begin(),workers.end(),[](Worker& w1,Worker& w2)
    {
        return w1.GetSalary()>w2.GetSalary();
    });

}

void EmployerManager::SortByEmpDate() {
    sort(workers.begin(),workers.end(),[](Worker& w1,Worker& w2)
    {
        if(w1.getEmpDate().year>w2.getEmpDate().year)
        {
            if(w1.getEmpDate().month>w2.getEmpDate().month)
            {
                if(w1.getEmpDate().day>w2.getEmpDate().day)
                {
                    return true;
                }
            }
        }
        return false;
    });

}
