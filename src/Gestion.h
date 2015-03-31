#ifndef GESTION_H
#define GESTION_H

#include "Region.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
int nombrePointVirguleDansLigne(FILE* fichier);

void lectureFichierDepartement(Region** tab_region, int** taille_tab_region);
void ecritureFichierDepartement(Region* tab_region, int* taille_tab_region);
void lectureFichierRecensements();
void ecritureFichierRecensements();
#endif
