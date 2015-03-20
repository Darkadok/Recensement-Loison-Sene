#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <stdlib.h>

#include "Ville.h"

typedef struct Departement Departement;

struct Departement {

char* nom_dep;
int numero_dep;
Ville* prefecture;
Ville* ville;
int taille_tab_ville;
};

void ajouterDepartement(Departement tab_departement, int *taille_tab_departement, char nom_dep[], char numero_dep[], char prefecture_tmp[]);
Departement* ajouterPrefecture();
void modifierDepartement(Departement* departement, char nom_dep[],int numero_dep, char prefecture[]);
Departement* supprimerDepartement(Departement* departement, Departement* departement_supp, int* taille_tab_departement);
Departement* detruireDepartement();

#endif