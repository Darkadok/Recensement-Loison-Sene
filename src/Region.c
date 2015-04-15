/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015


Region.c
@author Massamba Sène

**/

#include "Region.h"

void creerTabRegion(Region** tab_region, int** taille_tab_region, wchar_t nom_reg[])
{
	*taille_tab_region = malloc(sizeof(int));
	**taille_tab_region = 1;

	*tab_region = malloc(sizeof(Region));
	(*tab_region)->nom_reg = malloc(sizeof(wchar_t)* (wcslen(nom_reg) + 1));
	(*tab_region)->tab_departement = NULL;
	(*tab_region)->taille_tab_departement = NULL;

	wcscpy((*tab_region)->nom_reg, nom_reg);

}


void ajouterRegion(Region** tab_region, wchar_t nom_reg[], int** taille_tab_region)
{
	int i = 0;
	int j;
	Departement* tab_departement_tmp;

	if (*taille_tab_region == NULL)
	{
		creerTabRegion(tab_region, taille_tab_region, nom_reg);
	}

	else
	{
		*tab_region = realloc(*tab_region, sizeof(Region)*((**taille_tab_region) + 1));


		/****** On remplit la dernière case ******/

		((*tab_region) + **taille_tab_region)->nom_reg = malloc(sizeof(wchar_t)* (wcslen(nom_reg) + 1));

		wcscpy(((*tab_region) + **taille_tab_region)->nom_reg, nom_reg);

		((*tab_region) + **taille_tab_region)->tab_departement = NULL;
		((*tab_region) + **taille_tab_region)->taille_tab_departement = NULL;

		(**taille_tab_region)++;
	}


}


void afficherRegion(Region* region)
{

	wprintf(L"Nom : %ls\n", region->nom_reg);
}



int rechercheRegionByNom(Region* tab_region, int* taille_tab_region, wchar_t nom_reg[])
{
	wchar_t tab_nom_reg_tmp[100];
	wchar_t nom_reg_tmp[100];

	wchar_t nom_reg_sa[100];
	wchar_t tab_nom_reg_sa[100];

	wcscpy(nom_reg_sa, nom_reg);
	enleverAccent(nom_reg_sa);
	wcscpy(nom_reg_tmp, nom_reg_sa);
	toMin(nom_reg_sa, nom_reg_tmp);

	for (int i = 0; i < *taille_tab_region; i++)
	{
		wcscpy(tab_nom_reg_sa, (tab_region+i)->nom_reg);
		enleverAccent(tab_nom_reg_sa);
		wcscpy(tab_nom_reg_tmp, tab_nom_reg_sa);
		toMin(tab_nom_reg_sa, tab_nom_reg_tmp);

		if (!wcscmp(tab_nom_reg_tmp, nom_reg_tmp))
		{

			return i;
		}
	}
	return -1;
}



void modifierNomRegion(Region* region, wchar_t nom_reg[])
{
	region->nom_reg = realloc(region->nom_reg, wcslen(nom_reg) + 1);
	wcscpy(region->nom_reg, nom_reg);
}





void* supprimerRegion(Region** tab_region, Region* region_supp, int** taille_tab_region)
{
	int i, k;
	int j = 0;
	Departement* tab_departement_tmp;


	if (**taille_tab_region == 1)
	{
		detruireTabRegion(tab_region, taille_tab_region);
		return NULL;
	}

	else
	{
		Region* tab_tmp = malloc(sizeof(Region)*(**taille_tab_region) - 1);



		for (i = 0; i < **taille_tab_region; i++)
		{

			/****** Tant  qu'on ne tombe pas sur la région à supprimer, on recopie le contenu des structures *****/

			if (wcscmp(((*tab_region) + i)->nom_reg, region_supp->nom_reg))
			{

				(tab_tmp + j)->nom_reg = malloc(sizeof(wchar_t)* (wcslen(((*tab_region) + i)->nom_reg) + 1));
				wcscpy((tab_tmp + j)->nom_reg, ((*tab_region) + i)->nom_reg);

				(tab_tmp + j)->tab_departement = NULL;
				(tab_tmp + j)->taille_tab_departement = NULL;

				/****** Pour chaque région, on recopie son tableau de départemnts ******/

				if (((*tab_region) + i)->tab_departement != NULL)
				{
					tab_departement_tmp = ((*tab_region) + i)->tab_departement;

					for (k = 0; k< *(((*tab_region) + i)->taille_tab_departement); k++)
					{
						ajouterDepartement((tab_tmp + j)->tab_departement, (tab_departement_tmp + k)->nom_dep, (tab_departement_tmp + k)->numero_dep, (tab_departement_tmp + k)->prefecture, &((tab_tmp + j)->taille_tab_departement));
					}
				}


				j++;
			}

			/***** Pour la région à supprimer, on détruit les départements, les villes et les recensements ******/

			else
			{
				detruireTabDepartement(&(((*tab_region) + i)->tab_departement), &(((*tab_region) + i)->taille_tab_departement));
			}

		}

		(**taille_tab_region)--;

		if (*tab_region != NULL)
		{
			if ((*tab_region)->nom_reg != NULL)
			{
				free((*tab_region)->nom_reg);
				(*tab_region)->nom_reg = NULL;
			}

			free(*tab_region);
			*tab_region = NULL;
		}


		return tab_tmp;
	}
}



void detruireTabRegion(Region** tab_region, int** taille_tab_region)
{

	int i;

	if (*tab_region != NULL)
	{

		for (i = 0; i<**taille_tab_region; i++)
		{
			if (((*tab_region) + i)->nom_reg != NULL)
			{
				free(((*tab_region) + i)->nom_reg);
				((*tab_region) + i)->nom_reg = NULL;
			}

			detruireTabDepartement(&(((*tab_region) + i)->tab_departement), &(((*tab_region) + i)->taille_tab_departement));
		}

		free(*tab_region);
		*tab_region = NULL;
	}

	if (*taille_tab_region != NULL)
	{
		free(*taille_tab_region);
		*taille_tab_region = NULL;
	}

}



