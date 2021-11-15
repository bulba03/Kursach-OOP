//
// Created by bulba on 15.11.2021.
//

#include "Worker.h"
Task* Worker::GetActiveTasks() {
    for(int i=0;i<tasks.size();i++)
    {
        if(tasks.at(i).state == TaskState::Active)
        {
            tasks.at(i);
        }
    }
    return nullptr;
}

void Worker::ShowInfo() {
    Person::ShowInfo();
    auto b = GetActiveTasks();
    if(b!= nullptr)
    {
    cout << "Active Task: " << b->taskTitle<<endl;
    cout << "Task discription:" << b->taskDiscription<<endl;
    }
    else
    {
        cout<<name<<" Net activnix zadach"<<endl;
    }
}
