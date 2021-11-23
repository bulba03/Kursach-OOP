//
// Created by bulba on 23.11.2021.
//

#ifndef KURSACH_OOP_MENU_H
#define KURSACH_OOP_MENU_H

#include <iostream>

#include "LoginData.h"
#include "../Managers/Singleton.h"
#include "../People/Worker.h"
#include "../People/AvaliableWorker.h"

using namespace std;
class Menu: Singleton<Menu> {
public:
private: bool AdminLogin();
    bool ManagerLogin();

    void Register();

    void RegisterManager();

public:void ShowMenu();

protected: void ShowWorkers(std::vector<Worker> workers);
    void ShowLabor(vector<AvaliableWorker> avaliableWorkers);
};
#endif //KURSACH_OOP_MENU_H
