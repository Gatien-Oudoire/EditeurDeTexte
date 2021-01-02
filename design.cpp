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

void afficherCouleur(string texte, char couleur, bool sauterLigne)
{
    if(SYS == "UNIX")
    {
    map<char, int> codeCouleur;
    codeCouleur.insert(pair<char, int>('R', 31));
    codeCouleur.insert(pair<char, int>('V', 32));
    codeCouleur.insert(pair<char, int>('B', 34));
    codeCouleur.insert(pair<char, int>('G', 90));
    cout << "\033[1;" << codeCouleur[couleur] << "m" << texte << "\033[0m";
    }
    else 
        cout << texte;
    if (sauterLigne)
        cout << endl;
}
