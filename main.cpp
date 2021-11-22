#include "windows.h"
#include "Classes/Speciefic/AdminMenu.h"
#include "Classes/Managers/FileWriter.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Worker a = Worker();
    a.SetInfo(500, 23040,"ABOBA", WorkType::Programmer);
    Singleton<FileWriter>::getInstance().SaveWorker(a);
    Singleton<FileWriter>::getInstance().LoadWorkers();
    auto b=Singleton<EmployerManager>::getInstance().GetWorkersList();
    cout<<b[0].GetName();
    cout<<b[1].GetName();

}