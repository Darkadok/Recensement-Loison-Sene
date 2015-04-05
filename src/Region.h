/*
Override
Region.h

2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène

**/

#ifndef REGION_H
#define REGION_H

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <stdio.h>

#include "GestionChaine.h"
#include "Departement.h"

typedef struct Region Region;

struct Region {

wchar_t* nom_reg;
Departement* tab_departement;
int* taille_tab_departement;
};

Region* creerTabRegion(Region* tab_region, int** taille_tab_region, wchar_t nom_reg[]);
Region* ajouterRegion(Region* tab_region, wchar_t nom_reg[], int** taille_tab_region);

void afficherRegion(Region* region);

int rechercheRegionByNom(Region* tab_region, int* taille_tab_region, wchar_t nom_reg[]);

void modifierNomRegion(Region* region, wchar_t nom_reg[]);

void* supprimerRegion(Region** tab_region, Region* region_supp, int** taille_tab_region);
void detruireTabRegion(Region** tab_region, int** taille_tab_region);

#endif