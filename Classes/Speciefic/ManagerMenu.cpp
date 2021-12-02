//
// Created by bulba on 19.11.2021.
//

#include "ManagerMenu.h"
#include "../Managers/FileWriter.h"

void ManagerMenu::OpenMenu() {
    char choise;
    while (choise != '0') {
        Singleton<FileWriter>::getInstance().LoadLabor();
        Singleton<FileWriter>::getInstance().LoadWorkers();

        cout << "1) Вывести список рабочих" << endl;
        cout << "2) Нанять рабочего" << endl;
        cout << "3) Уволить рабочего" << endl;
        cout << "4) Поиск работника" << endl;
        cout << "0) Выход в основное меню"<<endl;

        cin >> choise;
        switch (choise) {
            case '1': {
                auto workersList = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workersList);
            }break;
            case '2': {
                auto avWorkersList = Singleton<Labor>::getInstance().GetAvaliableWorkers();
                Menu::ShowLabor(avWorkersList);
                cout<<"Введите номер работника которого хотите нанять: ";
                int num;
                cin>>num;
                if(!isValueInRange(num,1,avWorkersList.size()))
                {
                    cout<<"Неверное значени"<<endl;
                    break;
                }

                auto temp = avWorkersList.at(num-1);
                Worker newWorker(temp.GetAge(),temp.GetSalary(),temp.GetName(),temp.GetType());
                avWorkersList.erase(avWorkersList.begin()+num-1);
                Singleton<FileWriter>::getInstance().SaveLabor(avWorkersList);
                Singleton<EmployerManager>::getInstance().AddWorker(newWorker);
                Singleton<FileWriter>::getInstance().SaveWorker(Singleton<EmployerManager>::getInstance().GetWorkersList());
                cout<<newWorker.GetName()<<" Успешно нанят!"<<endl;
            }break;
            case '3': {
                auto workersList = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workersList);
                int num;
                cin>>num;
                if(!isValueInRange(num,0,(int)workersList.size()))
                {
                    cout<<"Неверное значени"<<endl;
                    break;
                }
                AvaliableWorker av = AvaliableWorker(workersList.at(num));
                workersList.erase(workersList.begin()+num);
                Singleton<Labor>::getInstance().AddAvaliableWorker(av);
                cout<<av.GetName()<<" уволен:("<<endl;
            }break;
            case '4':{
                auto foundedWorkers = Singleton<EmployerManager>::getInstance().FindByParameter();
                Menu::ShowWorkers(foundedWorkers);
            }break;
            case '0':return;break;
            default:cout<<"Неверное значение!"<<endl;break;
        }
    }
}

bool ManagerMenu::isValueInRange(int val, int min, int max) {
    if(val>=min&&val<=max)
    {
        return true;
    }
    return false;
}

