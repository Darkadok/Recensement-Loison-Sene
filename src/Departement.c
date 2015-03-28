#include "Departement.h"


void creerTabDepartement(Departement** tab_departement, int** taille_tab_departement, int taille_nom_dep)
{
	*taille_tab_departement = malloc(sizeof(int));
	**taille_tab_departement = 1;

	*tab_departement = malloc(sizeof(Departement)*(**taille_tab_departement));
	(*tab_departement)->nom_dep = malloc(sizeof(char)*(taille_nom_dep));
	(*tab_departement)->tab_ville = NULL;
	(*tab_departement)->taille_tab_ville = NULL;
	(*tab_departement)->prefecture = NULL;

}


void ajouterDepartement(Departement** tab_departement, char nom_dep[], int numero_dep, int** taille_tab_departement)
{
	int i=0;

	if(*taille_tab_departement == NULL)
	{
		creerTabDepartement(tab_departement, taille_tab_departement, strlen(nom_dep));
		strcpy((*tab_departement)->nom_dep, nom_dep);
		(*tab_departement)->numero_dep = numero_dep;
	}

	else
	{
		Departement* tab_nouveau = malloc (sizeof(Departement)*(**taille_tab_departement)+1);

		for(i = 0; i<**taille_tab_departement; i++)
		{
			*(tab_nouveau+i) = *((*tab_departement)+i);
			i++;
		}

		tab_nouveau->nom_dep = malloc(sizeof(char)* strlen(nom_dep));

		strcpy((tab_nouveau+i)->nom_dep, nom_dep);
		(tab_nouveau+i)->numero_dep = numero_dep;

		(tab_nouveau+i)->tab_ville = NULL;
		(tab_nouveau+i)->taille_tab_ville = NULL; 
		(*tab_departement)->prefecture = NULL;

		(**taille_tab_departement)++;

		free(*tab_departement);
		*tab_departement = tab_nouveau;
	}
}

void modifierNomDepartement(Departement* departement, char nom_dep[])
{
	free(departement->nom_dep);
	departement->nom_dep = malloc(sizeof(char)* strlen(nom_dep));
	strcpy(departement->nom_dep, nom_dep);
}

void modifierNumeroDepartement(Departement* departement, int numero_dep)
{
	departement->numero_dep = numero_dep;
}

void modifierPrefectureDepartement(Departement* departement, Ville* prefecture)
{
	departement->prefecture = prefecture;
}


void supprimerDepartement(Departement** tab_departement, Departement* departement_supp, int** taille_tab_departement)
{
	int i;
	int j=0;


	if(**taille_tab_departement == 1)
	{
		detruireTabDepartement(tab_departement, taille_tab_departement);
	}

	else
	{
		Departement* tab_tmp = malloc(sizeof(Departement)*(**taille_tab_departement)-1);



		for (i=0; i<**taille_tab_departement; i++)
		{
			if(!strcmp(((*tab_departement)+i)->nom_dep,departement_supp->nom_dep))
			{
				*(tab_tmp+j) = *((*tab_departement)+i);
				
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

		(**taille_tab_departement)--;


		free(*tab_departement);
		*tab_departement = tab_tmp;
	}
}

void detruireTabDepartement(Departement** tab_departement, int** taille_tab_departement)
{

	int i;

	if(*tab_departement != NULL)
	{

		for(i=0; i<**taille_tab_departement; i++)
		{	
			detruireTabVille(&(((*tab_departement)+i)->tab_ville), &(((*tab_departement)+i)->taille_tab_ville));
		}

		for(i=0; i<**taille_tab_departement; i++)
		{
			free(((*tab_departement)+i)->nom_dep);
			((*tab_departement)+i)->nom_dep = NULL;
		}

		free(*tab_departement);
		*tab_departement = NULL;
	}

}

