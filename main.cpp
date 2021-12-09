#include "Classes/Speciefic/Menu.h"
#include "iomanip"
using namespace std;
int main() {
    Singleton<Menu>::getInstance().ShowMenu();
}