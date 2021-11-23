//
// Created by bulba on 23.11.2021.
//

#include <iostream>
#include "AdminMenu.h"
#include "../Managers/EmployerManager.h"
#include "../Managers/FileWriter.h"

using namespace std;
void AdminMenu::ShowMenu() {
    Singleton<FileWriter>::getInstance().LoadLabor();
    Singleton<FileWriter>::getInstance().LoadWorkers();
    char choise;
    while (choise != '0') {
        cout << "1) ������� ������ �������" << endl;
        cout << "2) �������� ��������" << endl;
        cout << "3) ������� ��������" << endl;
        cout << "4) �������� ��������� �� �����" << endl;
        cout << "5) ������� ��������� � �����"<<endl;
        cout << "6) �������� ������ ����������"<<endl;
        cout << "7) �������� �����"<<endl;
        cout << "0) �����"<<endl;
        cin>>choise;
        switch (choise) {
            case '1': {
                Singleton<FileWriter>::getInstance().LoadWorkers();
                Menu::ShowWorkers(Singleton<EmployerManager>::getInstance().GetWorkersList());
            }break;
            case '2': {
                Worker worker = Worker();
            std::string fio;
            int age,salary,type;
            cout<<"������� ��� ���������: ";
            cin>>fio;
            cout<<"������� ������� ���������: ";
            cin>>age;
            cout<<"������� �������� ���������: ";
            cin>>salary;
            cout<<"�������� ������������� ���������: "<<endl;
            cout<<"1) ��������"<<endl;
            cout<<"2) �����������"<<endl;
            cout<<"3) ��"<<endl;
            cout<<"4) ����. ��������"<<endl;
            cout<<"5) ������ ��������"<<endl;
            cin>>type;
            WorkType wType = (WorkType)(type-1);
            worker.SetInfo(age,salary,fio,wType);
            Singleton<EmployerManager>::getInstance().AddWorker(worker);
            Singleton<FileWriter>::getInstance().SaveWorker(Singleton<EmployerManager>::getInstance().GetWorkersList());
            cout<<"�������� ��������!"<<endl;}
            break;


            case '3':
            {
                Singleton<FileWriter>::getInstance().LoadWorkers();
                auto workers = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workers);
                int id;
                cout<<"������� ����� ��������� �������� ������ �������: ";
                cin>>id;
                workers.erase(workers.begin()+id-1);
                Singleton<FileWriter>::getInstance().SaveWorker(workers);
                cout<<"�������� ������!"<<endl;
            }break;
            case '4':
            {
                string fio;
                int age,salary,type,yearsOfWork;
                cout<<"������� ��� ���������: ";
                cin>>fio;
                cout<<"������� ������� ���������: ";
                cin>>age;
                cout<<"������� �������� ���������: ";
                cin>>salary;
                cout<<"�������� ������������� ���������: "<<endl;
                cout<<"1) ��������"<<endl;
                cout<<"2) �����������"<<endl;
                cout<<"3) ��"<<endl;
                cout<<"4) ����. ��������"<<endl;
                cout<<"5) ������ ��������"<<endl;
                cin>>type;
                WorkType wType = (WorkType)(type-1);
                cout<<"������� ���� ������: ";
                cin>>yearsOfWork;
                AvaliableWorker av = AvaliableWorker();
                av.SetInfo(age,fio,salary,yearsOfWork,wType);
                auto laborMembers = Singleton<Labor>::getInstance().GetAvaliableWorkers();
                laborMembers.push_back(av);
                Singleton<FileWriter>::getInstance().SaveLabor(laborMembers);
            }break;
            case '5':
            {
                Singleton<FileWriter>::getInstance().LoadLabor();
                auto labor = Singleton<Labor>::getInstance().GetAvaliableWorkers();
                Menu::ShowLabor(labor);
                int choise;
                cout<<"������� ����� �������� �������� ������ �������: ";
                cin>>choise;
                if(choise<1||choise> labor.size())
                {
                    return;
                }
                labor.erase(labor.begin()+choise-1);
                Singleton<FileWriter>::getInstance().SaveLabor(labor);
                cout<<"������� ������!"<<endl;
            }break;
            case '6': Singleton<FileWriter>::getInstance().ClearWorkers();break;
            case '7': Singleton<FileWriter>::getInstance().ClearLabor();break;
            case'0':return;break;
            default:cout<<"��� ������ ��������!"<<endl;
        }
        }
    }
