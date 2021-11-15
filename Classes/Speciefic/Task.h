//
// Created by bulba on 15.11.2021.
//

#ifndef KURSACH_OOP_TASK_H
#define KURSACH_OOP_TASK_H

#include <iostream>
#include "../Enums/TaskState.h"

using namespace std;
class Task {
public: string taskTitle;
    string taskDiscription;
public:
    TaskState state;
    Task();
    Task(string tittle, string discription);

};




#endif //KURSACH_OOP_TASK_H
