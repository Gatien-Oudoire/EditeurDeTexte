#include "fichiers.hpp"

using namespace std;

int creationFichier(string nom, ofstream *fichier)
{
    cout << "1" << endl;
    fichier->open(nom.c_str(), ios::app);
    cout << "2" << endl;
    if (*fichier)
    {
        cout << "3" << endl;
        fichier->close();
        return 0;
    }
    else 
    {
        return 1;
    }
}

void lireFichier(ifstream *fichier, string os)
{
    effacer(os);
    string ligne;
    while (getline(*fichier, ligne))
    {
        cout << ligne << endl;
    };
}

void lireEntreeClavier(int *vie, string *texte) 
{
    getline(cin, *texte);
    if (*texte == ":quitter" || *texte == ":q")
    {
        *vie = 0;
        *texte = "";
    }
}
