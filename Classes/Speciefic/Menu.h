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
        cout<<"Введите логин: ";
        cin>>log;
        cout<<"Введите пароль: ";
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
        cout<<"Введите логин: ";
        cin>>log;
        cout<<"Введите пароль: ";
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
        cout<<"Введите логин: ";
        cin>>log;
        cout<<"Введите пароль: ";
        cin>>pass;
        cout<<"Введите пригласительный код(QWERTY123): ";
        cin>>code;
        if(code==codetrue)
        {
            LoginData logData = LoginData(log,pass);
            Singleton<FileWriter>::getInstance().SaveAdminLogPass(logData);
            cout<<"Вы успешно зарегистрировались как администратор!"<<endl;
        }
        else{
            cout<<"Неправильный пригласительный код!"<<endl;
        }
    }

    void RegisterManager() {
        string log,pass;
        cout<<"Введите логин: ";
        cin>>log;
        cout<<endl;
        cout<<"Введите пароль: ";
        cin>>pass;
        LoginData logData = LoginData(log,pass);
            Singleton<FileWriter>::getInstance().SaveManagerLogPass(logData);
            cout<<"Вы успешно зарегистрировались как менеджер!"<<endl;
    }

public:void ShowMenu()
    {
        char ch;
        while(ch!='0')
        {


        cout<<"1)Войти как администратор\n2)Войти как HR-менеджер\n3)Регистрация как Администратор\n4)Регистрация как Менеджер"<<endl;
        cin>>ch;
        switch (ch) {
            case '1': if(AdminLogin())
                {
                    cout<<"Вы вошли как администратор!"<<endl;
                };
            break;
            case '2': if(ManagerLogin())
                {
                    cout<<"Вы вошли как менеджер!"<<endl;
                }
            case '3': Register();break;
            case '4': RegisterManager();break;
            default: cout<<"Нет такого выбора!"<<endl;break;
        }
        }
    }
};


#endif //KURSACH_OOP_MENU_H
