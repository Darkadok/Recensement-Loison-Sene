#ifndef RECENSEMENT_H
#define RECENSEMENT_H

#include <stdlib.h>
#include <string.h>

typedef struct Recensement Recensement;

struct Recensement {

char annee[5];
int valeur_recen;
};

Recensement* ajouterRecensement(char annee[], int valeur_recen);
void modifierRecensement(Recensement* recensement, int valeur_recen);
Recensement* supprimerRecensement(Recensement* recensement, int taille_tab_recensement, Recensement* recensement_supp);
Recensement* detruireRecensement(Recensement* recensement);




#endif