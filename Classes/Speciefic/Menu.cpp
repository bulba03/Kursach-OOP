//
// Created by bulba on 23.11.2021.
//

#include "Menu.h"
#include "../Managers/FileWriter.h"
#include "ManagerMenu.h"
#include "AdminMenu.h"

bool Menu::ManagerLogin() {
    string log,pass;
    cout<<"������� �����: ";
    cin>>log;
    cout<<"������� ������: ";
    cin>>pass;
    LoginData loginData = LoginData(log,pass);
    if(Singleton<FileWriter>::getInstance().LoadManagerLogPass(loginData))
    {
        return true;
    }
    return false;
}

bool Menu::AdminLogin() {
    string log,pass;
    cout<<"������� �����: ";
    cin>>log;
    cout<<"������� ������: ";
    cin>>pass;
    LoginData loginData = LoginData(log,pass);
    if(Singleton<FileWriter>::getInstance().LoadAdminLogPass(loginData))
    {
        return true;
    }
    return false;
}

void Menu::Register() {
    string log,pass,code,codetrue = "QWERTY123";
    cout<<"������� �����: ";
    cin>>log;
    cout<<"������� ������: ";
    cin>>pass;
    cout<<"������� ��������������� ���(QWERTY123): ";
    cin>>code;
    if(code==codetrue)
    {
        LoginData logData = LoginData(log,pass);
        Singleton<FileWriter>::getInstance().SaveAdminLogPass(logData);
        cout<<"�� ������� ������������������ ��� �������������!"<<endl;
    }
    else{
        cout<<"������������ ��������������� ���!"<<endl;
    }
}

void Menu::ShowMenu() {
    char ch;
    while(ch!='0')
    {
        cout<<"1)����� ��� �������������\n2)����� ��� HR-��������\n3)����������� ��� �������������\n4)����������� ��� ��������"<<endl;
        cin>>ch;
        switch (ch) {
            case '1': if(AdminLogin())
                {
                    cout<<"�� ����� ��� �������������!"<<endl;
                    Singleton<AdminMenu>::getInstance().ShowMenu();
                };
                break;
            case '2': if(ManagerLogin())
                {
                    cout<<"�� ����� ��� ��������!"<<endl;
                    Singleton<ManagerMenu>::getInstance().OpenMenu();
                };break;
            case '3': Register();break;
            case '4': RegisterManager();break;
            default: cout<<"��� ������ ������!"<<endl;break;
        }
    }
}

void Menu::ShowWorkers(std::vector<Worker> workers) {
    cout<<right<<setw(20)<<"�����|"<<setw(20)<<"���|"<< setw(20)<<"�������|"<<setw(20)<<"��������|"<<setw(20)<<"�������������"<<setw(20)<<endl;
    for(int i=0;i<workers.size();i++)
    {
        cout<<right<<i+1<<setw(20)<<workers[i].GetName()<<setw(20)<<workers[i].GetAge()<<setw(20)<<workers[i].GetSalary()<<setw(20)<<enum_str[(int)workers[i].GetWorkType()]<<endl;
    }
}

void Menu::RegisterManager() {
    string log,pass;
    cout<<"������� �����: ";
    cin>>log;
    cout<<endl;
    cout<<"������� ������: ";
    cin>>pass;
    LoginData logData = LoginData(log,pass);
    Singleton<FileWriter>::getInstance().SaveManagerLogPass(logData);
    cout<<"�� ������� ������������������ ��� ��������!"<<endl;
}

void Menu::ShowLabor(vector<AvaliableWorker> avaliableWorkers) {
    cout<<right<<"�����|"<<setw(20)<<"���|"<< setw(20)<<"�������|"<<setw(20)<<"��������|"<<setw(20)<<"�������������"<<setw(20)<<"���� ������"<<setw(20)<<endl;
    cout<<avaliableWorkers.size()<<endl;
    for(int i=0;i<avaliableWorkers.size();i++)
    {
        cout<<i+1<<setw(20)<<avaliableWorkers[i].GetName()<<setw(20)<<avaliableWorkers[i].GetAge()<<setw(20)
        <<avaliableWorkers[i].GetSalary()<<setw(20)<<enum_str[(int)avaliableWorkers[i].GetType()]<<setw(20)<<avaliableWorkers[i].GetYearsOfWork()<<endl;
    }
}
