#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <stdlib.h>

#include "Ville.h"

typedef struct Departement Departement;

struct Departement {

char* nom_dep;
int numero_dep;
char* prefecture;
Ville* tab_ville;
int* taille_tab_ville;
};

Departement* creerTabDepartement(Departement* tab_departement, int** taille_tab_departement, char nom_dep[], int numero_dep, char prefecture[]);
Departement* ajouterDepartement(Departement* tab_departement, char nom_dep[], int numero_dep, char prefecture[], int** taille_tab_departement);

void afficherDepartement(Departement* departement);

int rechercheDepartementByNom(Departement* tab_departement, char nom_dep[]);
int rechercheDepartementByNumDep(Departement* tab_departement, int numero_dep);
int rechercheDepartementByPrefecture(Departement* tab_departement, char prefecture[]);

void modifierNomDepartement(Departement* departement, char nom_dep[]);
void modifierNumeroDepartement(Departement* departement, int numero_dep);
void modifierPrefectureDepartement(Departement* departement, char* prefecture);

void* supprimerDepartement(Departement** departement, Departement* departement_supp, int** taille_tab_departement);
void detruireTabDepartement(Departement** departement, int** taille_tab_departement);

#endif