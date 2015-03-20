#ifndef REGION_H
#define REGION_H

#include <stdlib.h>

#include "Departement.h"

typedef struct Region Region;

struct Region {

char* nom_reg;
Departement* departement;
int taille_tab_departement;
};

void ajouterRegion(Region** tab_region, int* taille_tab_region, char nom_reg[], char numero_dep[]);
Region* modifierRegion(char nom_reg[], char numero_dep[]);
Region* supprimerRegion();

#endif