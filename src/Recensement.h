#ifndef RECENSEMENT_H
#define RECENSEMENT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>


typedef struct Recensement Recensement;

struct Recensement {

char annee[5];
int valeur_recen;
};

Recensement* creerTabRecensement(Recensement* tab_recensement, char annee[], int valeur_recen, int** taille_tab_recensement);
Recensement* ajouterRecensement(Recensement* tab_recensement, char annee[], int valeur_recen, int** taille_tab_recensement);

void afficherRecensement(Recensement* recensement, char tab_accent[]);

int rechercheRecensement(Recensement* tab_recensement, int* taille_tab_recensement, char annee[]);

void modifierValeurRecensement(Recensement* recensement, int valeur_recen);
void modifierAnneeRecensement(Recensement* recensement, char annee[]);

void* supprimerRecensement(Recensement** tab_recensement, int** taille_tab_recensement, Recensement* recensement_supp);
void detruireTabRecensement(Recensement** tab_recensement, int** taille_tab_recensement);




#endif