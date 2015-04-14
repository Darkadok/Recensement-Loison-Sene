#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "GestionSaisie.h" 
#include "MenuAdministration.h"
#include "MenuConsulte.h"
#include "Region.h"


//Fonctions de lecture 
int menu();

//Fonctions en rapport avec l'administration
void menuAdmin(int choix);
void menuAjouter(int choix);
void menuSupprimer(int choix);

void lapin();

void color(int couleurDuTexte, int couleurDeFond);

#endif
