/*
Override
GestionFichier.h

2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène

**/

#ifndef GESTION_FICHIER_H
#define GESTION_FICHIER_H

#include "Region.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
int nombrePointVirguleDansLigne(FILE* fichier);

void lectureFichiers(Region** tab_region, int** taille_tab_region);
void ecritureFichierDepartements(Region* tab_region, int* taille_tab_region);
void ecritureFichierRecensements(Region* tab_region, int* taille_tab_region);
#endif
