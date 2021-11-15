#include <iostream>

#include "Classes/People/Worker.h"
#include "Classes/Managers/Singleton.h"

int main() {
    auto v =Singleton<EmployerManager>::getInstance().GetWorkersList();
    for(int i=0;v.size();i++)
    {
        cout<<v.at(i).GetName();
    }
}
