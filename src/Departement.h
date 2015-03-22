#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <stdlib.h>

#include "Ville.h"

typedef struct Departement Departement;

struct Departement {

char* nom_dep;
int numero_dep;
Ville* prefecture;
Ville* tab_ville;
int* taille_tab_ville;
};

void creerTabDepartement(Departement** tab_departement, int** taille_tab_departement, int taille_nom_dep);
void ajouterDepartement(Departement** tab_departement, char nom_dep[], int numero_dep, int** taille_tab_departement);
void modifierNomDepartement(Departement* departement, char nom_dep[]);
void modifierNumeroDepartement(Departement* departement, int numero_dep);
void modifierPrefectureDepartement(Departement* departement, Ville* prefecture);
void supprimerDepartement(Departement** departement, Departement* departement_supp, int** taille_tab_departement);
void detruireTabDepartement(Departement** departement, int** taille_tab_departement);

#endif