#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "GestionChaine.h" 
#include "Administration.h"
#include "Consulter.h"
#include "Region.h"


//Fonctions de lecture 
int menu();
int menuConsulter(int choix);

//Fonctions en rapport avec l'administration
void menuAdmin(int choix);
void menuAjouter(int choix);/*prototypes � typer !*/
void menuSupprimer(int choix);

void lapin();

void color(int couleurDuTexte, int couleurDeFond);

#endif
