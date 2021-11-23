//
// Created by bulba on 19.11.2021.
//

#ifndef KURSACH_OOP_MANAGERMENU_H
#define KURSACH_OOP_MANAGERMENU_H

using namespace std;
#include <iostream>
#include <iomanip>
#include "Menu.h"
#include "../Managers/Labor.h"
#include "../Managers/EmployerManager.h"

class ManagerMenu: Singleton<ManagerMenu>, public Menu{
public:
    void OpenMenu();

private: static bool isValueInRange(int val, int min, int max);
};


#endif //KURSACH_OOP_MANAGERMENU_H
