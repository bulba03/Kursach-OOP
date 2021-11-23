//
// Created by bulba on 19.11.2021.
//

#include "ManagerMenu.h"
#include "../Managers/FileWriter.h"

void ManagerMenu::OpenMenu() {
    char choise;
    while (choise != '0') {
        cout << "1) ������� ������ �������" << endl;
        cout << "2) ������ ��������" << endl;
        cout << "3) ������� ��������" << endl;
        cout << "4) ����� ���������" << endl;
        cout << "0) ����� � �������� ����"<<endl;

        cin >> choise;
        switch (choise) {
            case '1': {
                Singleton<FileWriter>::getInstance().LoadWorkers();
                auto workersList = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workersList);
            }break;
            case '2': {
                Singleton<FileWriter>::getInstance().LoadLabor();
                auto avWorkersList = Singleton<Labor>::getInstance().GetAvaliableWorkers();
                Menu::ShowLabor(avWorkersList);
                cout<<"������� ����� ��������� �������� ������ ������: ";
                int num;
                cin>>num;
                if(num<1||num>avWorkersList.size())
                {
                    cout<<"�������� �������"<<endl;
                    break;
                }
                Worker newWorker = Worker();
                auto temp = avWorkersList.at(num-1);
                newWorker.SetInfo(temp.GetAge(),temp.GetSalary(),temp.GetName(),temp.GetType());
                avWorkersList.erase(avWorkersList.begin()+num-1);
                Singleton<FileWriter>::getInstance().SaveLabor(avWorkersList);
                Singleton<EmployerManager>::getInstance().AddWorker(newWorker);
                Singleton<FileWriter>::getInstance().SaveWorker(Singleton<EmployerManager>::getInstance().GetWorkersList());
                cout<<newWorker.GetName()<<" ������� �����!"<<endl;
            }break;
            case '3': {
                auto workersList = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workersList);
                int num;
                cin>>num;
                if(isValueInRange(num,0,(int)workersList.size()))
                {
                    cout<<"�������� �������"<<endl;
                    break;
                }
                AvaliableWorker av = AvaliableWorker(workersList.at(num));
                workersList.erase(workersList.begin()+num-1);
                Singleton<Labor>::getInstance().AddAvaliableWorker(av);
                cout<<av.GetName()<<" ������:("<<endl;
            }break;
            case '4':{
                auto foundedWorkers = Singleton<EmployerManager>::getInstance().FindByParameter();
                Menu::ShowWorkers(foundedWorkers);
            }break;
            case '0':return;
            default:cout<<"�������� ��������!"<<endl;
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

