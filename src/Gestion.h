#ifndef GESTION_H
#define GESTION_H

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
