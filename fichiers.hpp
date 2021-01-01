#ifndef __FICHIERS__
#define __FICHIERS__

#include <iostream>
#include <fstream>
#include <string>

#include "design.hpp"

int creationFichier(std::string nom, std::ofstream *fichier);
void lireFichier(std::ifstream *fichier, std::string os, std::string nomFichier);
void lireEntreeClavier(int *vie, std::string *texte);

#endif