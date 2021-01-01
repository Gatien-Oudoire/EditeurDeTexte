//Fichiers sources
#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"
#include "fichiers.hpp"

using namespace std;

#ifdef __unix__
#define SYS "UNIX"
#elif defined WIN32
#define SYS "WINDOWS"
#endif

int main(int argc, char *argv[])
{
    //Variables obligatoires
    int vie(1);
    int commande;
    bool arguments = false;
    string extension;
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
        cout << "Entrez le nom du fichier sans extension : ";
        cin >> nomFichier;
        cout << "Entrez l extension du fichier : ";
        cin >> extension;
        extension = "." + extension;
        nomFichier += extension;
    }

    ifstream lectureFichier(nomFichier.c_str());
    // Recherche si le fichier existe si oui le lit
    if (lectureFichier)
    {
        lireFichier(&lectureFichier, SYS, nomFichier);
    }

    if (!creationFichier(nomFichier, &fichier))
    {
        while (vie)
        {
            lireEntreeClavier(&vie, &texte);
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
