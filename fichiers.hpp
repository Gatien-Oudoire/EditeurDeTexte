#ifndef __FICHIERS__
#define __FICHIERS__

#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"

int creationFichier(std::string nom, std::ofstream *fichier);
int supprimerFichier(std::string nomFichier, std::ofstream *fichier);
void lireFichier(std::ifstream *fichier, std::string nomFichier, int *compteurLigne);
void lireEntreeClavier(int *vie, int *compteurLigne, std::string *texte, std::string nomFichier, std::ofstream *fichier);

#endif