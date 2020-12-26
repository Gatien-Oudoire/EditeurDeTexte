#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int vie = 1;
    int commande;
    string extension;
    string nomFichierProvisoire;
    string texte;
    cout << "Bienvenue dans l'editeur de texte par Gatien Oudoire" << endl
         << endl
         << " Faite Ctrl + C pour quitter" << endl
         << endl
         << "Entrez le nom du fichier sans extension : ";
    cin >> nomFichierProvisoire;
    cout << "Entrez l extension du fichier " << endl ;
    cin >> extension;
    extension = "." + extension;
    nomFichierProvisoire += extension;
    string const nomFichier = nomFichierProvisoire;
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
                getline(cin, texte);
		if (texte == ":quitter")
		{
		vie = 0;
                }
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
        cout << "Aucun fichier de ce nom existant \nCreation du fichier..." << endl;
        ofstream fichier;
        fichier.open(nomFichier.c_str(), ios::app);
        if (fichier)
        {
            cout << "Fichier cree !" << endl
                 << endl;
	    commande = system("clear");
            cout << "----------" << nomFichier << "----------" << endl
		 << "----------EDITEUR GATIEN OUDOIRE----------" << endl;
            // Lancement de l editeur de texte

            while (vie)
            {
                getline(cin, texte);
		if (texte == ":quitter")
		{
		vie = 0;
		texte = "";
		}
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
