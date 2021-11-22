//
// Created by bulba on 22.11.2021.
//

#ifndef KURSACH_OOP_FILEWRITER_H
#define KURSACH_OOP_FILEWRITER_H
#include "Singleton.h"
#include "../People/Worker.h"
#include "EmployerManager.h"
#include <vector>
#include <sstream>
#include <fstream>

class FileWriter: Singleton<FileWriter> {

public: void SaveWorker(Worker worker)
    {
        std::ofstream file;
        file.open("Workers.txt",std::ios::app);
        if(file.is_open())
        {
            file<<worker.GetName()<<" "<<worker.GetAge()<<" "<<worker.GetSalary()<<" "<<enum_str[(int)worker.GetWorkType()]<<std::endl;
        }
    }
    void LoadWorkers()
    {
        std::ifstream file;
        file.open("Workers.txt");
        std::string name;
        int age;
        int salary;
        int size;
        std::string type;
        WorkType type1;
        if(file.is_open())
        {
            while(file>>name>>age>>salary>>type)
            {
                Worker worker = Worker();
                for(int i=0;i<5;i++)
                {
                    if(type == enum_str[i])
                    {
                        type1=static_cast<WorkType>(i);
                        break;
                    }
                }
                worker.SetInfo(age, salary,name,type1);
                Singleton<EmployerManager>::getInstance().AddWorker(worker);
            }
        }
    }
};


#endif //KURSACH_OOP_FILEWRITER_H
