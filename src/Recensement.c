/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015


Recensement.c
@author Massamba Sène

**/

#include "Recensement.h"



void creerTabRecensement(Recensement** tab_recensement, int annee, int valeur_recen, int** taille_tab_recensement)
{
	*taille_tab_recensement = malloc(sizeof(int));
	**taille_tab_recensement = 1;

	*tab_recensement = malloc(sizeof(Recensement)*(**taille_tab_recensement));

	(*tab_recensement)->annee = annee;
	(*tab_recensement)->valeur_recen = valeur_recen;


}

void ajouterRecensement(Recensement** tab_recensement, int annee, int valeur_recen, int** taille_tab_recensement)
{


	if (*taille_tab_recensement == NULL)
	{
		creerTabRecensement(tab_recensement, annee, valeur_recen, taille_tab_recensement);
	}

	else
	{

		*tab_recensement = realloc(*tab_recensement, sizeof(Recensement)* ((**taille_tab_recensement) + 1));

		/****** On remplit la dernière case ******/

		((*tab_recensement) + **taille_tab_recensement)->annee = annee;
		((*tab_recensement) + **taille_tab_recensement)->valeur_recen = valeur_recen;

		(**taille_tab_recensement)++;
	}
}


void afficherRecensement(Recensement* recensement)
{

	wprintf(L"%ls personnes ont %lct%c recens%lces en %d.", recensement->annee, 130, 130, 130, recensement->valeur_recen);

}



int rechercheRecensement(Recensement* tab_recensement, int* taille_tab_recensement, int annee)
{

	for (int i = 0; i < *taille_tab_recensement; i++)
	{
		if ((tab_recensement + i)->annee == annee)
		{

			return i;
		}
	}

	return -1;
}


void modifierValeurRecensement(Recensement* recensement, int valeur_recen)
{
	recensement->valeur_recen = valeur_recen;
}

void modifierAnneeRecensement(Recensement* recensement, int annee)
{
	recensement->annee = annee;
}

void* supprimerRecensement(Recensement** tab_recensement, int** taille_tab_recensement, Recensement* recensement_supp)
{
	int i;
	int j = 0;



	if (**taille_tab_recensement == 1)
	{
		detruireTabRecensement(tab_recensement, taille_tab_recensement);
		return NULL;
	}

	else
	{

		Recensement* tab_tmp = malloc(sizeof(Recensement)*((**taille_tab_recensement) - 1));



		for (i = 0; i<**taille_tab_recensement; i++)
		{
			if (((*tab_recensement) + i)->annee = recensement_supp->annee)
			{
				(tab_tmp + j)->valeur_recen = ((*tab_recensement) + i)->valeur_recen;
				(tab_tmp + j)->annee = ((*tab_recensement) + i)->annee;

				j++;
			}
		}

		(**taille_tab_recensement)--;

		if (*tab_recensement != NULL)
		{
			free(*tab_recensement);
		}

		return tab_tmp;
	}
}

void detruireTabRecensement(Recensement** tab_recensement, int** taille_tab_recensement)
{

	if (*tab_recensement != NULL)
	{
		free(*tab_recensement);
		*tab_recensement = NULL;
	}

	if (*taille_tab_recensement != NULL)
	{
		free(*taille_tab_recensement);
		*taille_tab_recensement = NULL;
	}
}


