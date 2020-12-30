//Fichiers sources
#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"
#include "fichiers.hpp"

using namespace std;

#ifdef __unix__
string OperatingSystem = "unix";
#endif

#ifdef WIN32
string OperatingSystem = "windows";
#endif

int main(int argc, char *argv[])
{
    //Variables obligatoires
    int vie(1);
    int commande;
    bool arguments = false;
    string extension;
    string nomFichierProvisoire;
    string texte;
    string nomFichier;
    ofstream fichier;

    // Detection des arguments
    if (argc == 3)
        arguments = true;

    cout << "Bienvenue dans l'editeur de texte par G.O." << endl
         << endl
         << "Entrez :quitter pour sortir du programme" << endl
         << endl;
    if (arguments)
    {
        nomFichier = (string)argv[1] + "." + (string)argv[2];
    }

    else
    {
        cout << "Entrez le nom du fichier sans extension : ";
        cin >> nomFichierProvisoire;
        cout << "Entrez l extension du fichier : ";
        cin >> extension;
        extension = "." + extension;
        nomFichierProvisoire += extension;
        nomFichier = nomFichierProvisoire;
    }
    ifstream lectureFichier(nomFichier.c_str());
    // Recherche si le fichier existe si oui le lit
    if (lectureFichier)
    {
        cout << "Ouverture du fichier ..." << endl;

        lireFichier(&lectureFichier, OperatingSystem);

        if (creationFichier(nomFichier, &fichier) == 0)
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
    }
    // Si le fichier n existe pas le cree
    else
    {
        cout << "Aucun fichier de ce nom existant" << endl
             << "Creation du fichier..." << endl;
        if (creationFichier(nomFichier, &fichier) == 0)
        {
            cout << "Fichier cree !" << endl
                 << endl;
            effacer(OperatingSystem);
            cout << "----------" << nomFichier << "----------" << endl;
            // Lancement de l editeur de texte
            while (vie)
            {
                lireEntreeClavier(&vie, &texte);
                if (texte != "")
                    fichier << texte << endl;
            }
        }
        else
        {
            cout << "Impossible de creer un fichier" << endl;
        }
        fichier.close();
    }
    return 0;
}
