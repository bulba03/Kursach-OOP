//
// Created by bulba on 23.11.2021.
//

#ifndef KURSACH_OOP_ADMINMENU_H
#define KURSACH_OOP_ADMINMENU_H
#include "../Managers/Singleton.h"
#include "Menu.h"

class AdminMenu: Singleton<AdminMenu>, public Menu{
public: void ShowMenu();
};


#endif //KURSACH_OOP_ADMINMENU_H
