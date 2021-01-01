#include "design.hpp"

using namespace std;

int effacer(string os)
{
    if (os == "WINDOWS")
        system("cls");
    else if (os == "UNIX")
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
