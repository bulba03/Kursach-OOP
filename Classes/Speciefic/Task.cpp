//
// Created by bulba on 15.11.2021.
//

#include "Task.h"

Task::Task() {
        cout<<"Vvedite nazvanie zadachi: ";
        cin>>taskTitle;
        cout<<"vvedite opisanie: ";
        cin>>taskDiscription;
        state =TaskState::Active;
}

Task::Task(string tittle, string discription) {
    taskTitle = tittle;
    taskDiscription = discription;
    state=TaskState::Active;
    cout<<static_cast<char>(state);
}
