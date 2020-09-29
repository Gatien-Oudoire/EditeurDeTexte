#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream essai;
    essai.open("essai.txt", ios::app);
    essai << "GLAND";
    essai.close();
    string nomFichierProvisoire;
    cout << "Bienvenue dans l'editeur de texte par Gatien Oudoire" << endl
         << endl
         << "Entrez le nom du fichier : ";
    cin >> nomFichierProvisoire;
    string const nomFichier = nomFichierProvisoire;
    ifstream lectureFichier(nomFichier.c_str());

    if (lectureFichier)
    {
        cout << "Ouverture du fichier ...";
    }
    else
    {
        cout << "Aucun fichier de ce nom existant \nCreation du fichier..." << endl;
        ofstream fichier;
        fichier.open(nomFichier.c_str(), ios::app);
        if (fichier)
        {
            cout << "Fichier cree !" << endl
                 << "----------" << nomFichier << "----------" << endl;
            string texte;
            fichier << "----------EDITEUR GATIEN OUDOIRE----------";
            while (1)
            {
                getline(cin, texte);
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