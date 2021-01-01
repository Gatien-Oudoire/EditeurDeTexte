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
	fichier = creationFichier(nomFichier);

	if (fichier){
		commande = system("clear");
		cout << "----------" << nomFichier << "----------" << endl;

		if (lectureFichier)
			lireFichier(&lectureFichier);

		while (vie)
		{
			lireEntreeClavier(&vie, &texte);
			if (texte != "")
				fichier << texte << endl;
		}
		fichier.close();
	}
	else{
		cout << "Erreur dans l'edition du fichier";
	}
    return 0;
}
