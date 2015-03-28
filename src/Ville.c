#include "Ville.h"


void creerTabVille(Ville** tab_ville, int** taille_tab_ville, int taille_nom_ville, int taille_dep_com)
{
	*taille_tab_ville = malloc(sizeof(int));
	**taille_tab_ville = 1;

	*tab_ville = malloc(sizeof(Ville)*(**taille_tab_ville));
	(*tab_ville)->nom_ville = malloc(sizeof(char)*(taille_nom_ville));
	(*tab_ville)->dep_com = malloc(sizeof(char)*(taille_dep_com));
	(*tab_ville)->tab_recensement = NULL;
	(*tab_ville)->taille_tab_recensement = NULL;

}


void ajouterVille(Ville** tab_ville, char nom_ville[], char dep_com[], int** taille_tab_ville)
{
	int i=0;

	if(*taille_tab_ville == NULL)
	{
		creerTabVille(tab_ville, taille_tab_ville, strlen(nom_ville), strlen(dep_com));
		strcpy((*tab_ville)->nom_ville, nom_ville);
		strcpy((*tab_ville)->dep_com, dep_com);
	}

	else
	{
		Ville* tab_nouveau = malloc (sizeof(Ville)*(**taille_tab_ville)+1);

		for(i = 0; i<**taille_tab_ville; i++)
		{
			*(tab_nouveau+i) = *((*tab_ville)+i);
			i++;
		}

		tab_nouveau->dep_com = malloc(sizeof(char)* strlen(dep_com));
		tab_nouveau->nom_ville = malloc(sizeof(char)* strlen(nom_ville));

		strcpy((tab_nouveau+i)->nom_ville, nom_ville);
		strcpy((tab_nouveau+i)->dep_com, dep_com);

		(tab_nouveau+i)->tab_recensement = NULL;
		(tab_nouveau+i)->taille_tab_recensement = NULL; 


		(**taille_tab_ville)++;
		
		free(*tab_ville);
		*tab_ville = tab_nouveau;
	}
}

void modifierNomVille(Ville* ville, char nom_ville[])
{
	free(ville->nom_ville);
	ville->nom_ville = malloc(sizeof(char)* strlen(nom_ville));
	strcpy(ville->nom_ville, nom_ville);
}

void modifierDepComVille(Ville* ville, char dep_com[])
{
	free(ville->dep_com);
	ville->dep_com = malloc(sizeof(char)* strlen(dep_com));
	strcpy(ville->dep_com, dep_com);
}

void supprimerVille(Ville** tab_ville, int** taille_tab_ville, Ville* ville_supp)
{
	int i;
	int j=0;

	if(**taille_tab_ville == 1)
	{
		detruireTabVille(tab_ville, taille_tab_ville);
	}

	else
	{

		Ville* tab_tmp = malloc(sizeof(Ville)*(**taille_tab_ville)-1);

		for (i=0; i<**taille_tab_ville; i++)
		{
			if(!strcmp(((*tab_ville)+i)->nom_ville, ville_supp->nom_ville))
			{
				*(tab_tmp+j) = *((*tab_ville)+i);
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

		(**taille_tab_ville)--;

		free(*tab_ville);
		*tab_ville = tab_tmp;
	}
}

void detruireTabVille(Ville** tab_ville, int** taille_tab_ville)
{
	int i;

	if(*tab_ville != NULL)
	{

		for(i=0; i<**taille_tab_ville; i++)
		{	
			detruireTabRecensement(&(((*tab_ville)+i)->tab_recensement), &(((*tab_ville)+i)->taille_tab_recensement));
		}

		for(i=0; i<**taille_tab_ville; i++)
		{
			free(((*tab_ville)+i)->nom_ville);
			((*tab_ville)+i)->nom_ville = NULL;

			free(((*tab_ville)+i)->dep_com);
			((*tab_ville)+i)->dep_com = NULL;
		}

		free(*tab_ville);
		*tab_ville=NULL;

		free(*taille_tab_ville);
		*taille_tab_ville=NULL;
	}
}