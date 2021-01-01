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

void lireFichier(ifstream *fichier, string os, string nomFichier, int *compteurLigne)
{

    if (effacer(os))
        cout << "echec de la mise en place de l environement " << endl;
    else
        cout << "----------" << nomFichier << "----------" << endl;
    string ligne;
    while (getline(*fichier, ligne))
    {
        cout << *compteurLigne << ": " << ligne << endl;
        *compteurLigne += 1;
    };
}

void lireEntreeClavier(int *vie, int *compteurLigne, string *texte)
{
    afficherLigne(compteurLigne);
    getline(cin, *texte);
    if (*texte == ":quitter" || *texte == ":q")
    {
        *vie = 0;
        *texte = "";
    }
}
