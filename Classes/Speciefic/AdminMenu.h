//
// Created by bulba on 19.11.2021.
//

#ifndef KURSACH_OOP_ADMINMENU_H
#define KURSACH_OOP_ADMINMENU_H
#include "../Managers/EmployerManager.h"
#include "../Managers/Labor.h"

using namespace std;
#include <iostream>
#include <iomanip>

class AdminMenu: Singleton<AdminMenu> {
public:
    void OpenMenu() {
        int choise = 99;
        while (choise != 0) {
            cout << "1) Вывести список рабочих" << endl;
            cout << "2) Нанять рабочего" << endl;
            cout << "3) Уволить рабочего" << endl;
            cout << "4) Поиск работника" << endl;

            cin >> choise;
            switch (choise) {
                case 1:
                    ShowWorkers();
                    break;
                case 2:
                    auto list =Singleton<Labor>::getInstance().GetAvaliableWorkers();
            }
        }

    }
    void ShowWorkers()
    {
        auto workers = Singleton<EmployerManager>::getInstance().GetWorkersList();
        cout<<right<<"Номер|"<<setw(5)<<"Имя|"<< setw(20)<<"Возраст|"<<"Зарплата"<<setw(5)<<endl;
        for(int i=0;i<workers.size();i++)
        {
            cout<<right<<i<<setw(5)<<workers[i].GetName()<<setw(20)<<workers[i].GetAge()<<setw(5)<<workers[i].GetSalary()<<endl;
        }
    }
    void ShowLabor(vector<AvaliableWorker> avaliableWorkers)
    {

    }
};


#endif //KURSACH_OOP_ADMINMENU_H
