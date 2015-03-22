#include "Recensement.h"


void creerTabRecensement(Recensement** tab_recensement, int** taille_tab_recensement)
{
	*taille_tab_recensement = malloc(sizeof(int));
	**taille_tab_recensement = 1;

	*tab_recensement = malloc(sizeof(Recensement)*(**taille_tab_recensement));

}

void ajouterRecensement(Recensement** tab_recensement, char annee[], int valeur_recen, int** taille_tab_recensement)
{
	int i;


	if(*taille_tab_recensement == NULL)
	{
		creerTabRecensement(tab_recensement, taille_tab_recensement);

		strcpy((*tab_recensement)->annee, annee);
		(*tab_recensement)->valeur_recen = valeur_recen;
	}

	else
	{

		Recensement* tab_nouveau = malloc(sizeof(Recensement)*(**taille_tab_recensement)+1);

		for (i=0; i<**taille_tab_recensement; i++)
		{

				*(tab_nouveau+i) = *((*tab_recensement)+i);
				i++;
		}

		strcpy((tab_nouveau+i)->annee, annee);
		(tab_nouveau+i)->valeur_recen = valeur_recen;

		(**taille_tab_recensement)++;

		free(*tab_recensement);
		*tab_recensement = tab_nouveau;
	}

}

void modifierValeurRecensement(Recensement* recensement, int valeur_recen)
{
	recensement->valeur_recen = valeur_recen;
}

void modifierAnneeRecensement(Recensement* recensement, char annee[])
{
	strcpy(recensement->annee, annee);
}

void supprimerRecensement(Recensement** tab_recensement, int** taille_tab_recensement, Recensement* recensement_supp)
{
	int i;
	int j=0;
	

	if(**taille_tab_recensement == 1)
	{
		detruireTabRecensement(tab_recensement, taille_tab_recensement);
	}

	else
	{

		Recensement* tab_tmp = malloc(sizeof(Recensement)*(**taille_tab_recensement)-1);



		for (i=0; i<**taille_tab_recensement; i++)
		{
			if(!strcmp(((*tab_recensement)+i)->annee,recensement_supp->annee))
			{
				*(tab_tmp+j) = *((*tab_recensement)+i);
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

		(**taille_tab_recensement)--;

		free(*tab_recensement);
		*tab_recensement = tab_tmp;
	}
}

void detruireTabRecensement(Recensement** tab_recensement, int** taille_tab_recensement)
{

	if(*tab_recensement != NULL)
	{
		free(*tab_recensement);
		free(*taille_tab_recensement);

		*tab_recensement = NULL;
		*taille_tab_recensement = NULL;
	}
}