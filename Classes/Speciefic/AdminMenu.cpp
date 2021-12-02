//
// Created by bulba on 23.11.2021.
//

#include <iostream>
#include "AdminMenu.h"
#include "../Managers/EmployerManager.h"
#include "../Managers/FileWriter.h"

using namespace std;
void AdminMenu::ShowMenu() {
    char choise;
    while (choise != '0') {
        Singleton<FileWriter>::getInstance().LoadLabor();
        Singleton<FileWriter>::getInstance().LoadWorkers();

        cout << "1) Вывести список рабочих" << endl;
        cout << "2) Добавить Рабочего" << endl;
        cout << "3) Удалить рабочего" << endl;
        cout << "4) Добавить работника на биржу" << endl;
        cout << "5) Удалить работника с биржи"<<endl;
        cout << "6) Очистить Список работников"<<endl;
        cout << "7) Очистить биржу"<<endl;
        cout << "0) Выход"<<endl;
        cin>>choise;
        switch (choise) {
            case '1': {
                Singleton<FileWriter>::getInstance().LoadWorkers();
                Menu::ShowWorkers(Singleton<EmployerManager>::getInstance().GetWorkersList());
            }break;
            case '2': {

            std::string surname, name, secondName;
            int age,salary,type;
            cout<<"Введите фамилию работника: ";
            cin>>surname;
            cout<<"Введите имя работника";
            cin>>name;
            cout<<"Введите отчество работника";
            cin>>secondName;
            cout<<"Введите возраст работника: ";
            cin>>age;
            cout<<"Введите зарплату работника: ";
            cin>>salary;
            cout<<"Выберите специальность работника: "<<endl;
            cout<<"1) Дизайнер"<<endl;
            cout<<"2) Программист"<<endl;
            cout<<"3) ПМ"<<endl;
            cout<<"4) Техн. художник"<<endl;
            cout<<"5) Бизнес аналитик"<<endl;
            cin>>type;
            WorkType wType = (WorkType)(type-1);
            Worker worker = Worker(age,salary,surname,name,secondName,wType);
            Singleton<EmployerManager>::getInstance().AddWorker(worker);
            Singleton<FileWriter>::getInstance().SaveWorker(Singleton<EmployerManager>::getInstance().workers);
            cout<<"Работник добавлен!"<<endl;}
            break;
            case '3':
            {
                Singleton<FileWriter>::getInstance().LoadWorkers();
                auto workers = Singleton<EmployerManager>::getInstance().GetWorkersList();
                Menu::ShowWorkers(workers);
                int id;
                cout<<"Введите номер работника которого хотите удалить: ";
                cin>>id;
                workers.erase(workers.begin()+id-1);
                Singleton<FileWriter>::getInstance().SaveWorker(workers);
                cout<<"Работник удален!"<<endl;
            }break;
            case '4':
            {
                string fio;
                int age,salary,type,yearsOfWork;
                cout<<"Введите ФИО работника: ";
                cin>>fio;
                cout<<"Введите возраст работника: ";
                cin>>age;
                cout<<"Введите зарплату работника: ";
                cin>>salary;
                cout<<"Выберите специальность работника: "<<endl;
                cout<<"1) Дизайнер"<<endl;
                cout<<"2) Программист"<<endl;
                cout<<"3) ПМ"<<endl;
                cout<<"4) Техн. художник"<<endl;
                cout<<"5) Бизнес аналитик"<<endl;
                cin>>type;
                WorkType wType = (WorkType)(type-1);
                cout<<"Введите стаж работы: ";
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
                cout<<"Введите номер рабочего которого хотите удалить: ";
                cin>>choise;
                if(choise<1||choise> labor.size())
                {
                    return;
                }
                labor.erase(labor.begin()+choise-1);
                Singleton<FileWriter>::getInstance().SaveLabor(labor);
                cout<<"Рабочий удален!"<<endl;
            }break;
            case '6': Singleton<FileWriter>::getInstance().ClearWorkers();break;
            case '7': Singleton<FileWriter>::getInstance().ClearLabor();break;
            case'0':return;break;
            default:cout<<"Нет такого варианта!"<<endl;
        }
        }
    }
