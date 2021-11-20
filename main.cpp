#include <iostream>
#include "windows.h"
#include "Classes/Speciefic/AdminMenu.h"
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Worker a = Worker();
    auto v =Singleton<EmployerManager>::getInstance().GetWorkersList();
    v.at(0).ShowInfo();
    cout<<v.at(0).GetAllTasks().size();
    Singleton<AdminMenu>::getInstance().ShowWorkers();
}