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

void afficherCouleur(string texte, char couleur, string texteSupp)
{
    if (SYS == "UNIX")
    {
        map<char, int> codeCouleur = {{'R', 31}, {'B', 34}};
        cout << "\033[1;" << codeCouleur[couleur] << "m" << texte << "\033[0m";
    }
    else
        cout << texte;
    if (texteSupp.size() > 0)
        cout << texteSupp;
}
