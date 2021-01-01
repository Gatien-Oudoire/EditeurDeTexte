#ifndef __FICHIERS__
#define __FICHIERS__

#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"

int creationFichier(std::string nom, std::ofstream *fichier);
void lireFichier(std::ifstream *fichier, std::string os, std::string nomFichier, int *compteurLigne);
void lireEntreeClavier(int *vie, int *compteurLigne, std::string *texte);

#endif