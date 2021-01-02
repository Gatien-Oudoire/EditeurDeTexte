//Fichiers sources
#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"
#include "fichiers.hpp"

using namespace std;



int main(int argc, char *argv[])
{
    //Variables obligatoires
    int vie(1);
    int commande;
    int compteurLigne = 1;
    string texte;
    string nomFichier;
    ofstream fichier;

    cout << "Bienvenue dans l'editeur de texte par G.O." << endl
         << endl
         << "Entrez :quitter pour sortir du programme" << endl
         << endl;

    if (argc == 3)
        nomFichier = (string)argv[1] + "." + (string)argv[2];

    else if (argc == 2)
        nomFichier = (string)argv[1];

    else
    {
        cout << "Veuillez entrez des arguments ex: edt index.html" << endl
             << endl;
        return 1;
    }

    ifstream lectureFichier(nomFichier.c_str());
    // Recherche si le fichier existe si oui le lit
    if (lectureFichier)
    {
        lireFichier(&lectureFichier, nomFichier, &compteurLigne);
    }
    else
    {
        effacer();
        cout << "----------" << nomFichier << "----------" << endl;
    }

    if (!creationFichier(nomFichier, &fichier))
    {
        while (vie)
        {
            lireEntreeClavier(&vie, &compteurLigne, &texte, nomFichier, &fichier);
            if (texte != "")
                fichier << texte << endl;
        }
        fichier.close();
    }
    else
    {
        cout << "Erreur dans l edition du fichier";
    }
    return 0;
}
