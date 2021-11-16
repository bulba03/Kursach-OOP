#include <iostream>

#include "Classes/People/Worker.h"
#include "Classes/Managers/Singleton.h"

int main() {
    Worker a = Worker();
    auto v =Singleton<EmployerManager>::getInstance().GetWorkersList();
    cout<<v.at(0).GetName();
}
