//
// Created by bulba on 22.11.2021.
//

#ifndef KURSACH_OOP_FILEWRITER_H
#define KURSACH_OOP_FILEWRITER_H
#include "Singleton.h"
#include "../People/Worker.h"
#include "EmployerManager.h"
#include "../Speciefic/LoginData.h"
#include "../People/AvaliableWorker.h"
#include "Labor.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

#define ENG 26
#define RUS 32
#define COUNT 10
class FileWriter: Singleton<FileWriter> {

public: void SaveWorker(std::vector<Worker> worker)
    {
        std::ofstream file;
        file.open("Workers.txt");
        if(file.is_open())
        {
            for(int i=0;i<worker.size();i++)
            {
            file<<worker[i].GetName()<<" "<<worker[i].GetAge()<<" "<<worker[i].GetSalary()<<" "<<enum_str[(int)worker[i].GetWorkType()]<<std::endl;
            }
        }
        file.close();
    }
    void ClearLabor()
    {
        std::ofstream file;
        file.open("Labor.txt");
        file.close();
    }
    void ClearWorkers()
    {
        std::ofstream file;
        file.open("Workers.txt");
        file.close();
    }
    void LoadWorkers()
    {
        Singleton<EmployerManager>::getInstance().workers.clear();
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
                for(int i=0;i<4;i++)
                {
                    if(type == enum_str[i])
                    {
                        type1=(WorkType)i;
                        break;
                    }
                }
                worker.SetInfo(age, salary,name,type1);
                Singleton<EmployerManager>::getInstance().AddWorker(worker);
            }
        }
        file.close();
    }
    bool LoadAdminLogPass(LoginData logData)
    {
        std::ifstream file;
        file.open("AdminLogsPass.txt");
        if(file.is_open())
        {
            std::string log,pass;
            while(file>>log>>pass)
            {
                if(encryption(log) == logData.login && encryption(pass) == logData.pass)
                {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
    void SaveAdminLogPass(LoginData logData)
    {
        auto log = decryption(logData.login);
        auto pass = decryption(logData.pass);
        std::ofstream file;
        file.open("AdminLogsPass.txt",std::ios::app);
        if(file.is_open())
        {
            file<<log<<" "<< pass<<std::endl;
        }
        file.close();
    }
    void SaveManagerLogPass(LoginData logData)
    {
        auto log = decryption(logData.login);
        auto pass = decryption(logData.pass);
        std::ofstream file;
        file.open("ManagerLogsPass.txt",std::ios::app);
        if(file.is_open())
        {
            file<<log<<" "<< pass<<std::endl;
        }
        file.close();
    }
    bool LoadManagerLogPass(LoginData logData)
    {
        std::ifstream file;
        file.open("ManagerLogsPass.txt");
        if(file.is_open())
        {
            std::string log,pass;
            while(file>>log>>pass)
            {
                if(encryption(log)==logData.login && encryption(pass)==logData.pass)
                {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
        return false;
    }
    void SaveLabor(std::vector<AvaliableWorker> avaliableWorkers)
    {
        std::ofstream file;
        file.open("Labor.txt");
        if(file.is_open())
        {
            for(int i =0; i < avaliableWorkers.size(); i++)
            {
            file << avaliableWorkers[i].GetName() << " " << avaliableWorkers[i].GetAge() << " " <<
                 avaliableWorkers[i].GetSalary() << " " << enum_str[(int)avaliableWorkers[i].GetType()] << " " << avaliableWorkers[i].GetYearsOfWork() << std::endl;
            }
        }
        file.close();
    }
    void LoadLabor()
    {
        Singleton<Labor>::getInstance().avaliableWorkers.clear();
        std:: ifstream file;
        file.open("Labor.txt");
        if(file.is_open())
        {
            int age,salary,yearsOfWork;
            WorkType type1;;
            std::string fio,type;
            while(file>>fio>>age>>salary>>type>>yearsOfWork)
            {
                AvaliableWorker avW = AvaliableWorker();
                for(int i=0;i<4;i++)
                {
                    if(type == enum_str[i])
                    {
                        type1=(WorkType)i;
                        break;
                    }
                }
                avW.SetInfo(age,fio,salary,yearsOfWork,type1);
                Singleton<Labor>::getInstance().avaliableWorkers.push_back(avW);
            }
        }
        file.close();
    }
    std::string encryption(std::string str)
    {
        int key = 4;
        int ln = str.length();
        for (int i = 0; i < ln; i++)
        {
            if (str[i] >= 'À' && str[i] <= 'ß')
            {
                str[i] =str[i] + (key % RUS);
                if (str[i] > 'ß')
                    str[i] = 'À' + (str[i] - 'ß'-1);
            }
            if (str[i] >= 'à' && str[i] <= 'ÿ')
            {
                str[i] = str[i] + (key % RUS);
                if (str[i] > 'ÿ')
                    str[i] = 'à' + (str[i] - 'ÿ'-1);
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + (key % ENG);
                if (str[i] > 'Z')
                    str[i] = 'A' + (str[i] - 'Z'-1);
            }
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] + (key % ENG);
                if (str[i] > 'z')
                    str[i] = 'a' + (str[i] - 'z'-1);
            }
            if (str[i] >= '0' && str[i] <= '9')
            {
                str[i] = str[i] + (key % COUNT);
                if (str[i] > '9')
                    str[i] = '0' + (str[i] - '9'-1);
            }
        }
        return str;
    }
    std::string decryption(std::string str)
    {
        int key = 4;
        int ln = str.length();
        for (int i = 0; i < ln; i++)
        {
            if (str[i] >= 'À' && str[i] <= 'ß')
            {
                str[i] = str[i] - (key % RUS);
                if (str[i] < 'À')
                    str[i] = 'ß' - ('À' - str[i]) + 1;
            }
            if (str[i] >= 'à' && str[i] <= 'ÿ')
            {
                str[i] = str[i] - (key % RUS);
                if (str[i] < 'à')
                    str[i] = 'ÿ' - ('à' - str[i]) + 1;
            }
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] - (key % ENG);
                if (str[i] < 'A')
                    str[i] = 'Z' - ('A' - str[i]) + 1;
            }
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - (key % ENG);
                if (str[i] < 'a')
                    str[i] = 'z' - ('a' - str[i]) + 1;
            }
            if (str[i] >= '0' && str[i] <= '9')
            {
                str[i] = str[i] - (key % COUNT);
                if (str[i] < '0')
                    str[i] = '9' - ('0' - str[i]) + 1;
            }
        }
        return str;
    }
};


#endif //KURSACH_OOP_FILEWRITER_H
