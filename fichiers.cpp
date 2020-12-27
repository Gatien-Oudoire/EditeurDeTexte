#include "fichiers.hpp"

using namespace std;

void lireEntreeClavier(int *vie, string *texte) 
{
    getline(cin, *texte);
    if (*texte == ":quitter" || *texte == ":q")
    {
        *vie = 0;
        *texte = "";
    }
}
