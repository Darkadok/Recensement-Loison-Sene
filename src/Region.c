#include "Region.h"


void creerTabRegion(Region** tab_region, int** taille_tab_region, int taille_nom_reg)
{
	*taille_tab_region = malloc(sizeof(int));
	**taille_tab_region = 1;

	*tab_region = malloc(sizeof(Region)*(**taille_tab_region));
	(*tab_region)->nom_reg = malloc(sizeof(char)*(taille_nom_reg));
	(*tab_region)->tab_departement = NULL;
	(*tab_region)->taille_tab_departement = NULL;
}


void ajouterRegion(Region** tab_region, char nom_reg[], int** taille_tab_region)
{
	int i=0;

	if(*taille_tab_region == NULL)
	{
		creerTabRegion(tab_region, taille_tab_region, strlen(nom_reg));
		strcpy((*tab_region)->nom_reg, nom_reg);
	}

	else
	{
		Region* tab_nouveau = malloc (sizeof(Region)*(**taille_tab_region)+1);

		for(i = 0; i<**taille_tab_region; i++)
		{
			*(tab_nouveau+i) = *((*tab_region)+i);
			i++;
		}

		tab_nouveau->nom_reg = malloc(sizeof(char)* strlen(nom_reg));

		strcpy((tab_nouveau+i)->nom_reg, nom_reg);

		(tab_nouveau+i)->tab_departement = NULL;
		(tab_nouveau+i)->taille_tab_departement = NULL; 

		free(*tab_region);
		*tab_region = tab_nouveau;
	}
}

void modifierNomRegion(Region* region, char nom_reg[])
{
	free(region->nom_reg);
	region->nom_reg = malloc(sizeof(char)* strlen(nom_reg));
	strcpy(region->nom_reg, nom_reg);
}

void supprimerRegion(Region** tab_region, Region* region_supp, int** taille_tab_region)
{
	int i;
	int j=0;


	if(**taille_tab_region == 1)
	{
		detruireTabRegion(tab_region, taille_tab_region);
	}

	else
	{
		Region* tab_tmp = malloc(sizeof(Region)*(**taille_tab_region)-1);



		for (i=0; i<**taille_tab_region; i++)
		{
			if(!strcmp(((*tab_region)+i)->nom_reg,region_supp->nom_reg))
			{
				*(tab_tmp+j) = *((*tab_region)+i);
				
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}

		(**taille_tab_region)--;


		free(*tab_region);
		*tab_region = tab_tmp;
	}
}

void detruireTabRegion(Region** tab_region, int** taille_tab_region)
{

	int i;

	if(*tab_region != NULL)
	{

		for(i=0; i<**taille_tab_region; i++)
		{	
			detruireTabDepartement(&(((*tab_region)+i)->tab_departement), &(((*tab_region)+i)->taille_tab_departement));
		}

		for(i=0; i<**taille_tab_region; i++)
		{
			free(((*tab_region)+i)->nom_reg);
			((*tab_region)+i)->nom_reg = NULL;
		}

		free(*tab_region);
		*tab_region = NULL;
	}

}

