#include "Classes/Speciefic/Menu.h"
using namespace std;
int main() {
    Singleton<Menu>::getInstance().ShowMenu();
}