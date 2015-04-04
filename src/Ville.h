#ifndef VILLE_H
#define VILLE_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>

#include "Recensement.h"

typedef struct Ville Ville;

struct Ville {

wchar_t* nom_ville;
int dep_com;
Recensement* tab_recensement;
int* taille_tab_recensement;
};

Ville* creerTabVille(Ville* tab_ville, int** taille_tab_ville, wchar_t nom_ville[], int dep_com);
Ville* ajouterVille(Ville* tab_ville, wchar_t nom_ville[], int dep_com, int** taille_tab_ville);

void afficherVille(Ville* ville);

int rechercheVilleByNom(Ville* tab_ville, int* taille_tab_ville, wchar_t nom_ville[]);
int rechercheVilleByDepCom(Ville* tab_ville, int* taille_tab_ville, int dep_com);

void modifierNomVille(Ville* ville, wchar_t nom_ville[]);
void modifierDepComVille(Ville* ville, int dep_com);

void* supprimerVille(Ville** tab_ville, int** taille_tab_ville, Ville* ville_supp);
void detruireTabVille(Ville** tab_ville, int** taille_tab_ville);


#endif