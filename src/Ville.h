#ifndef VILLE_H
#define VILLE_H


#include <stdlib.h>

#include "Recensement.h"

typedef struct Ville Ville;

struct Ville {

char* nom_ville;
char* code_postal;
Recensement* recensement;
int taille_tab_recensement;
};

Ville* ajouterVille(char nom_ville[], char code_postal[]);
void modifierVille(Ville* ville, char code_postal[]);
Ville* supprimerVille(Ville* ville, int taille_tab_ville, Ville* ville_supp);
Ville* detruireVille(Ville* ville, int taille_tab_ville);


#endif