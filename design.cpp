#include "design.hpp"

using namespace std;

int effacer()
{
    if (SYS == "WINDOWS")
        system("cls");
    else if (SYS == "UNIX")
        system("clear");
    else
        return 1;
    return 0;
}

void afficherLigne(int *compteurLigne)
{
    cout << *compteurLigne << ": ";
    *compteurLigne += 1;
}
