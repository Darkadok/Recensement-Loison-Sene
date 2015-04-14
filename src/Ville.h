/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015


Ville.h
@author Massamba Sène

**/

#ifndef VILLE_H
#define VILLE_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>

#include "GestionSaisie.h"
#include "Recensement.h"

typedef struct Ville Ville;

struct Ville {

	wchar_t* nom_ville;
	wchar_t* dep_com;
	Recensement* tab_recensement;
	int* taille_tab_recensement;
};


void creerTabVille(Ville** tab_ville, int** taille_tab_ville, wchar_t nom_ville[], wchar_t dep_com[]);
void ajouterVille(Ville** tab_ville, wchar_t nom_ville[], wchar_t dep_com[], int** taille_tab_ville);

void afficherVille(Ville* ville);

int rechercheVilleByNom(Ville* tab_ville, int* taille_tab_ville, wchar_t nom_ville[]);
int rechercheVilleByDepCom(Ville* tab_ville, int* taille_tab_ville, wchar_t dep_com[]);

void modifierNomVille(Ville* ville, wchar_t nom_ville[]);
void modifierDepComVille(Ville* ville, wchar_t dep_com[]);

void* supprimerVille(Ville** tab_ville, int** taille_tab_ville, Ville* ville_supp);
void detruireTabVille(Ville** tab_ville, int** taille_tab_ville);


#endif