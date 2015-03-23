#ifndef GESTION_H
#define GESTION_H

#include "Region.h"
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
int NombrePointVirguleDansLigne(FILE* fichier);
void lectureFichierRecensements();
void lectureFichierDepartement(Region** tab_region, int** taille_tab_region, Departement** tab_departement, int** taille_tab_departement);
#endif