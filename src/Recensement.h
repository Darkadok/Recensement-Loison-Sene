/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015

Recensement.h
@author Massamba Sène

**/

#ifndef RECENSEMENT_H
#define RECENSEMENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>


typedef struct Recensement Recensement;

struct Recensement {

	int annee;
	int valeur_recen;
};


void creerTabRecensement(Recensement** tab_recensement, int annee, int valeur_recen, int** taille_tab_recensement);
void ajouterRecensement(Recensement** tab_recensement, int annee, int valeur_recen, int** taille_tab_recensement);

void afficherRecensement(Recensement* recensement);

int rechercheRecensement(Recensement* tab_recensement, int* taille_tab_recensement, int annee);

void modifierValeurRecensement(Recensement* recensement, int valeur_recen);
void modifierAnneeRecensement(Recensement* recensement, int annee);

void* supprimerRecensement(Recensement** tab_recensement, int** taille_tab_recensement, Recensement* recensement_supp);
void detruireTabRecensement(Recensement** tab_recensement, int** taille_tab_recensement);




#endif
