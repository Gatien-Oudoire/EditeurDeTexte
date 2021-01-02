#ifndef __DESIGN__
#define __DESIGN__

#ifdef __unix__
#define SYS "UNIX"
#elif defined WIN32
#define SYS "WINDOWS"
#endif

#include <string>
#include <iostream>

int effacer();
void afficherLigne(int *compteurLigne);

#endif