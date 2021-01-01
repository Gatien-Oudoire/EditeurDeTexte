#include "fichiers.hpp"

using namespace std;

int creationFichier(string nom, ofstream *fichier)
{
    fichier->open(nom.c_str(), ios::app);
    if (*fichier)
        return 0;
    else 
        return 1;
}

void lireFichier(ifstream *fichier, string os, string nomFichier)
{

    if (effacer(os))
        cout << "echec de la mise en place de l environement " << endl;
    else 
        cout << "----------" << nomFichier << "----------" << endl;
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
