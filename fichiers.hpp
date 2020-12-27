#ifndef __FICHIERS__
#define __FICHIERS__

#include <iostream>
#include <fstream>
#include <string>

std::ofstream creationFichier(std::string nom);
void lireFichier(std::ifstream *fichier);
void lireEntreeClavier(int *vie, std::string *texte);

#endif