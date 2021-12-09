//
// Created by bulba on 23.11.2021.
//

#include "Menu.h"
#include "../Managers/FileWriter.h"
#include "ManagerMenu.h"
#include "AdminMenu.h"
#include "iomanip"
ostream& table(ostream& stream);

ostream& tableSmall(ostream& stream);
bool Menu::ManagerLogin() {
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

bool Menu::AdminLogin() {
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

void Menu::Register() {
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

void Menu::ShowMenu() {
    char ch;
    while(ch!='0')
    {
        cout<<"1)Войти как администратор\n2)Войти как HR-менеджер\n3)Регистрация как Администратор\n4)Регистрация как Менеджер"<<endl;
        cin>>ch;
        switch (ch) {
            case '1': if(AdminLogin())
                {
                    cout<<"Вы вошли как администратор!"<<endl;
                    Singleton<AdminMenu>::getInstance().ShowMenu();
                };
                break;
            case '2': if(ManagerLogin())
                {
                    cout<<"Вы вошли как менеджер!"<<endl;
                    Singleton<ManagerMenu>::getInstance().OpenMenu();
                };break;
            case '3': Register();break;
            case '4': RegisterManager();break;
            default: cout<<"Нет такого выбора!"<<endl;break;
        }
    }
}

void Menu::ShowWorkers(std::vector<Worker> workers) {
    cout<<"#"<<table<<"Фамилия"<<table<<"Имя"<<table<<"Отчество"<<table
    <<"Возраст"<<table<<"Зарплата"<<tableSmall<<"Специальность"
        <<table<<"Дата принятия на работу"<<endl;
    for(int i=0;i<workers.size();i++)
    {
        cout<<i+1<<table<<workers[i].GetSurname()<<table<<workers[i].GetName()<<table<<workers[i].GetSecondName()<<tableSmall
        <<workers[i].GetAge()<<tableSmall<<workers[i].GetSalary()<<table<<enum_str[(int)workers[i].GetWorkType()]
        <<table<<workers[i].getEmpDate().year<<"-"<<workers[i].getEmpDate().month<<"-"<<workers[i].getEmpDate().day<<endl;
    }
}
ostream& table(ostream& stream) {
    stream <<"|"<< setw(20)<<setfill(' ');
    return stream;
}
ostream& tableSmall(ostream& stream) {
    stream <<"|"<< setw(13)<<setfill(' ');
    return stream;
}
void Menu::RegisterManager() {
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

void Menu::ShowLabor(vector<AvaliableWorker> avaliableWorkers) {
    cout<<right<<"№|"<<setw(20)<<"Имя|"<< setw(20)<<"Возраст|"<<setw(20)<<"Зарплата|"<<setw(20)<<"Специальность"<<setw(20)<<"Стаж работы"<<setw(20)<<endl;
    cout<<avaliableWorkers.size()<<endl;
    for(int i=0;i<avaliableWorkers.size();i++)
    {
        cout<<i+1<<setw(20)<<avaliableWorkers[i].GetName()<<setw(20)<<avaliableWorkers[i].GetAge()<<setw(20)
        <<avaliableWorkers[i].GetSalary()<<setw(20)<<enum_str[(int)avaliableWorkers[i].GetType()]<<setw(20)<<avaliableWorkers[i].GetYearsOfWork()<<endl;
    }
}
