#include <iostream>
#include <fstream>
#include <string>
#include "fichiers.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    //Variables obligatoires
    int vie(1);
    int commande;
    string extension;
    string nomFichierProvisoire;
    string texte;
    string nomFichier;
    bool arguments = false;

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
        cout << "Entrez l extension du fichier ";
        cin >> extension;
        extension = "." + extension;
        nomFichierProvisoire += extension;
        nomFichier = nomFichierProvisoire;
    }
    ifstream lectureFichier(nomFichier.c_str());
    // Recherche si le fichier existe si oui le lit
    if (lectureFichier)
    {
        cout << "Ouverture du fichier ..." << endl
             << endl;
        commande = system("clear");
        string ligne;
        while (getline(lectureFichier, ligne))
        {
            cout << ligne << endl;
        };
        ofstream fichier;

        fichier.open(nomFichier.c_str(), ios::app);
        if (fichier)
        {
            while (vie)
            {
                lireEntreeClavier(&vie, &texte);
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
        ofstream fichier;
        fichier.open(nomFichier.c_str(), ios::app);
        if (fichier)
        {
            cout << "Fichier cree !" << endl
                 << endl;
            commande = system("clear");
            cout << "----------" << nomFichier << "----------" << endl;
            // Lancement de l editeur de texte

            while (vie)
            {
                lireEntreeClavier(&vie, &texte);
                fichier << texte << endl;
            }
        }
        else
        {
            cout << "Erreur dans la creation du fichier" << endl;
        }
        fichier.close();
    }
    return 0;
}
