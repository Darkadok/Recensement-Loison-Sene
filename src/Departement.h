/*
Override
Departement.h

2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène

**/


#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <stdlib.h>
#include <wchar.h>
#include <stdio.h>

#include "Ville.h"

typedef struct Departement Departement;

struct Departement {

	wchar_t* nom_dep;
	wchar_t* numero_dep;
	wchar_t* prefecture;
	Ville* tab_ville;
	int* taille_tab_ville;
};

void afficherDepartement(Departement* departement);

void creerTabDepartement(Departement** tab_departement, int** taille_tab_departement, wchar_t nom_dep[], wchar_t numero_dep[], wchar_t prefecture[]);
void ajouterDepartement(Departement** tab_departement, wchar_t nom_dep[], wchar_t numero_dep[], wchar_t prefecture[], int** taille_tab_departement);

void triTabDepartement(Departement* tab_departement, int* taille_tab_departement);

void afficherDepartement(Departement* departement);

int rechercheDepartementByNom(Departement* tab_departement, int* taille_tab_departement, wchar_t nom_dep[]);
int rechercheDepartementByNumDep(Departement* tab_departement, int* taille_tab_departement, wchar_t numero_dep[]);
int rechercheDepartementByPrefecture(Departement* tab_departement, int* taille_tab_departement, wchar_t prefecture[]);

void modifierNomDepartement(Departement* departement, wchar_t nom_dep[]);
void modifierNumeroDepartement(Departement* departement, wchar_t numero_dep[]);
void modifierPrefectureDepartement(Departement* departement, wchar_t* prefecture);

void* supprimerDepartement(Departement** departement, Departement* departement_supp, int** taille_tab_departement);
void detruireTabDepartement(Departement** departement, int** taille_tab_departement);

#endif
