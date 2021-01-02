#ifndef __DESIGN__
#define __DESIGN__

#ifdef __unix__
#define SYS "UNIX"
#elif defined WIN32
#define SYS "WINDOWS"
#endif

#include <string>
#include <iostream>
#include <map>

int effacer();
void afficherLigne(int *compteurLigne);
void afficherCouleur(std::string texte, char couleur, bool sauterLigne=false);

#endif