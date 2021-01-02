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

void lireFichier(ifstream *fichier, string nomFichier, int *compteurLigne)
{

    if (effacer())
        cout << "echec de la mise en place de l environement " << endl;
    else
        afficherCouleur("----------" + nomFichier + "----------", 'B', true);
    string ligne;
    while (getline(*fichier, ligne))
    {
        cout << *compteurLigne << ": " << ligne << endl;
        *compteurLigne += 1;
    };
}

void lireEntreeClavier(int *vie, int *compteurLigne, string *texte, string nomFichier, ofstream *fichier)
{
    afficherLigne(compteurLigne);
    getline(cin, *texte);
    if (texte->c_str()[0] == ':')
        if (*texte == ":quitter" || *texte == ":q") // Il faudrait un switch case
        {
            *vie = 0;
            *texte = "";
        }
        else if (*texte == ":del" || *texte == ":rm")
        {
            if (supprimerFichier(nomFichier, fichier))
            {
                ofstream fichierVide;
                if (*fichier)
                    fichier->close();
                fichierVide.open(nomFichier.c_str(), ios::trunc);
                fichierVide.close();
            }
            else 
            {
                effacer();
                cout << nomFichier << " a ete supprime " << endl;
            }
            *vie = 0;
            *texte = "";
        }
}

int supprimerFichier(string nomFichier, ofstream *fichier)
{
    fichier->close();
    if (SYS == "UNIX")
        return system(("rm " + nomFichier).c_str());
    else if (SYS == "WINDOWS")
        return system(("del " + nomFichier).c_str());
    else
        return 1;
}