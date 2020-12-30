#include "design.hpp"

using namespace std;

void effacer(string os)
{
    if (os == "win32")
        system("cls");
    else if (os == "unix")
        system("clear");
    return;
}

