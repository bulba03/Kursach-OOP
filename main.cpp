#include "windows.h"
#include "Classes/Speciefic/Menu.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Singleton<Menu>::getInstance().ShowMenu();
}