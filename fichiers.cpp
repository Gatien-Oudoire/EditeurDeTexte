#include "fichiers.hpp"

using namespace std;

ofstream creationFichier(string nom)
{
    ofstream fichier;
    fichier.open(nom.c_str(), ios::app);
    if (fichier)
    {
        return fichier;
    }
    else
    {
        cout << "ERREUR DANS LA CREATION DU FICHIER";
    }
}

void lireFichier(ifstream *fichier)
{
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
