//
// Created by bulba on 23.11.2021.
//

#ifndef KURSACH_OOP_MENU_H
#define KURSACH_OOP_MENU_H

#include <iostream>
#include "../Managers/Singleton.h"
#include "LoginData.h"
#include "../Managers/FileWriter.h"

using namespace std;
class Menu: Singleton<Menu> {
public:
private: bool AdminLogin() {
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
    bool ManagerLogin()
    {
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

    void Register() {
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

    void RegisterManager() {
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

public:void ShowMenu()
    {
        char ch;
        while(ch!='0')
        {


        cout<<"1)����� ��� �������������\n2)����� ��� HR-��������\n3)����������� ��� �������������\n4)����������� ��� ��������"<<endl;
        cin>>ch;
        switch (ch) {
            case '1': if(AdminLogin())
                {
                    cout<<"�� ����� ��� �������������!"<<endl;
                };
            break;
            case '2': if(ManagerLogin())
                {
                    cout<<"�� ����� ��� ��������!"<<endl;
                }
            case '3': Register();break;
            case '4': RegisterManager();break;
            default: cout<<"��� ������ ������!"<<endl;break;
        }
        }
    }
};


#endif //KURSACH_OOP_MENU_H
