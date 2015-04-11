/*
Override
Departement.c

2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène

**/


#include "Departement.h"


Departement* creerTabDepartement(Departement** tab_departement, int** taille_tab_departement, wchar_t nom_dep[], wchar_t numero_dep[], wchar_t prefecture[])
{
	*taille_tab_departement = malloc(sizeof(int));
	**taille_tab_departement = 1;

	*tab_departement = malloc(sizeof(Departement)*(**taille_tab_departement));
	(*tab_departement)->nom_dep = malloc(sizeof(wchar_t)*(wcslen(nom_dep) + 1));
	(*tab_departement)->tab_ville = NULL;
	(*tab_departement)->taille_tab_ville = NULL;
	(*tab_departement)->prefecture = malloc(sizeof(wchar_t) * (wcslen(prefecture) + 1));
	(*tab_departement)->numero_dep = malloc(sizeof(wchar_t)* (wcslen(numero_dep) + 1));

	wcscpy((*tab_departement)->numero_dep, numero_dep);
	wcscpy((*tab_departement)->nom_dep, nom_dep);
	wcscpy((*tab_departement)->prefecture, prefecture);

	return *tab_departement;
}


Departement* ajouterDepartement(Departement** tab_departement, wchar_t nom_dep[], wchar_t numero_dep[], wchar_t prefecture[], int** taille_tab_departement)
{
	int i = 0;
	int j;
	Ville* tab_ville_tmp;

	if (*taille_tab_departement == NULL)
	{
		*tab_departement = creerTabDepartement(tab_departement, taille_tab_departement, nom_dep, numero_dep, prefecture);
	}

	else
	{
		Departement* tab_nouveau = malloc(sizeof(Departement)* ((**taille_tab_departement) + 1));


		/******* On recopie le contenu du tableau champs par champs ******/

		for (i = 0; i<**taille_tab_departement; i++)
		{
			(tab_nouveau + i)->nom_dep = malloc(sizeof(wchar_t)* (wcslen(((*tab_departement) + i)->nom_dep) + 1));
			wcscpy((tab_nouveau + i)->nom_dep, ((*tab_departement) + i)->nom_dep);


			(tab_nouveau + i)->numero_dep = malloc(sizeof(wchar_t)* (wcslen(((*tab_departement) + i)->numero_dep) + 1));
			wcscpy((tab_nouveau + i)->numero_dep, ((*tab_departement) + i)->numero_dep);

			(tab_nouveau + i)->tab_ville = NULL;
			(tab_nouveau + i)->taille_tab_ville = NULL;
			(tab_nouveau + i)->prefecture = NULL;

			/****** Pour chaque case du tableau de départements, on recopie le tableau de villes ******/

			if (((*tab_departement) + i)->tab_ville != NULL)
			{
				tab_ville_tmp = ((*tab_departement) + i)->tab_ville;

				for (j = 0; j < *(((*tab_departement) + i)->taille_tab_ville); j++)
				{
					(tab_nouveau + i)->tab_ville = ajouterVille(&((tab_nouveau + i)->tab_ville), (tab_ville_tmp + j)->nom_ville, (tab_ville_tmp + j)->dep_com, &((tab_nouveau + i)->taille_tab_ville));
				}

			}

			/***** Copie de la préfecture *****/

			if (((*tab_departement) + i)->prefecture != NULL)
			{
				(tab_nouveau + i)->prefecture = malloc(sizeof(Ville) *(wcslen(((*tab_departement) + i)->prefecture) + 1));
				wcscpy((tab_nouveau + i)->prefecture, ((*tab_departement) + i)->prefecture);
			}

		}

		/****** On remplit la dernière case ******/

		(tab_nouveau + i)->nom_dep = malloc(sizeof(wchar_t)* (wcslen(nom_dep) + 1));
		wcscpy((tab_nouveau + i)->nom_dep, nom_dep);

		(tab_nouveau + i)->numero_dep = malloc(sizeof(wchar_t)* (wcslen(numero_dep) + 1));
		wcscpy((tab_nouveau + i)->numero_dep, numero_dep);

		(tab_nouveau + i)->prefecture = malloc(sizeof(wchar_t) * (wcslen(prefecture) + 1));
		wcscpy((tab_nouveau + i)->prefecture, prefecture);

		(tab_nouveau + i)->tab_ville = NULL;
		(tab_nouveau + i)->taille_tab_ville = NULL;



		(**taille_tab_departement)++;

		if (*tab_departement != NULL)
		{
			if ((*tab_departement)->nom_dep != NULL)
			{
				(*tab_departement)->nom_dep;
			}

			if ((*tab_departement)->numero_dep != NULL)
			{
				(*tab_departement)->numero_dep;
			}


			if ((*tab_departement)->prefecture != NULL)
			{
				(*tab_departement)->prefecture;
			}

			free(*tab_departement);
		}

		return tab_nouveau;
	}

	return *tab_departement;
}


int rechercheDepartementByNom(Departement* tab_departement, int* taille_tab_departement, wchar_t nom_dep[])
{
	for (int i = 0; i < *taille_tab_departement; i++)
	{
		if (!wcscmp((tab_departement + i)->nom_dep, nom_dep))
		{
			return i;
		}
	}

	return -1;
}

int rechercheDepartementByNumDep(Departement* tab_departement, int* taille_tab_departement, wchar_t numero_dep[])
{
	for (int i = 0; i < *taille_tab_departement; i++)
	{
		if ((tab_departement + i)->numero_dep == numero_dep)
		{
			return i;
		}
	}

	return -1;
}

int rechercheDepartementByPrefecture(Departement* tab_departement, int* taille_tab_departement, wchar_t prefecture[])
{
	for (int i = 0; i < *taille_tab_departement; i++)
	{
		if (!wcscmp((tab_departement + i)->prefecture, prefecture))
		{
			return i;
		}
	}

	return -1;

}

void modifierNomDepartement(Departement* departement, wchar_t nom_dep[])
{
	free(departement->nom_dep);
	departement->nom_dep = malloc(sizeof(wchar_t)* (wcslen(nom_dep) + 1));
	wcscpy(departement->nom_dep, nom_dep);
}

void modifierNumeroDepartement(Departement* departement, wchar_t numero_dep[])
{
	free(departement->numero_dep);
	departement->numero_dep = malloc(sizeof(wchar_t)* (wcslen(numero_dep) + 1));
	wcscpy(departement->numero_dep, numero_dep);
}

void modifierPrefectureDepartement(Departement* departement, wchar_t* prefecture)
{
	free(departement->prefecture);
	departement->prefecture = malloc(sizeof(wchar_t) * (wcslen(prefecture) + 1));
	wcscpy(departement->prefecture, prefecture);
}


void* supprimerDepartement(Departement** tab_departement, Departement* departement_supp, int** taille_tab_departement)
{
	int i, k;
	int j = 0;
	Ville* tab_ville_tmp;

	if (**taille_tab_departement == 1)
	{
		detruireTabDepartement(tab_departement, taille_tab_departement);
		return NULL;
	}

	else
	{
		Departement* tab_tmp = malloc(sizeof(Departement)*((**taille_tab_departement) - 1));



		for (i = 0; i<**taille_tab_departement; i++)
		{
			/****** Tant  qu'on ne tombe pas sur le département à supprimer, on recopie le contenu des structures *****/


			if (wcscmp(((*tab_departement) + i)->nom_dep, departement_supp->nom_dep))
			{
				(tab_tmp + j)->nom_dep = malloc(sizeof(wchar_t)* (wcslen(((*tab_departement) + i)->nom_dep) + 1));
				wcscpy((tab_tmp + j)->nom_dep, ((*tab_departement) + i)->nom_dep);

				(tab_tmp + j)->numero_dep = malloc(sizeof(wchar_t)* (wcslen(((*tab_departement) + i)->numero_dep) + 1));
				wcscpy((tab_tmp + j)->numero_dep, ((*tab_departement) + i)->numero_dep);

				(tab_tmp + j)->tab_ville = NULL;
				(tab_tmp + j)->taille_tab_ville = NULL;
				(tab_tmp + j)->prefecture = NULL;

				/****** Pour chaque département, on recopie son tableau de villes ******/

				if (((*tab_departement) + i)->tab_ville != NULL)
				{
					tab_ville_tmp = ((*tab_departement) + i)->tab_ville;

					for (k = 0; k< *(((*tab_departement) + i)->taille_tab_ville); k++)
					{
						(tab_tmp + j)->tab_ville = ajouterVille((tab_tmp + j)->tab_ville, (tab_ville_tmp + k)->nom_ville, (tab_ville_tmp + k)->dep_com, &((tab_tmp + j)->taille_tab_ville));
					}
				}


				/***** Copie de la préfecture *****/

				if (((*tab_departement) + i)->prefecture != NULL)
				{
					(tab_tmp + j)->prefecture = malloc(sizeof(Ville) *(wcslen(((*tab_departement) + i)->prefecture) + 1));
					wcscpy((tab_tmp + j)->prefecture, ((*tab_departement) + i)->prefecture);
				}

				j++;
			}

			/****** Pour le département à supprimer, on détruit les villes et les recensements ******/

			else
			{
				detruireTabVille(&(((*tab_departement) + i)->tab_ville), &(((*tab_departement) + i)->taille_tab_ville));
			}

		}

		(**taille_tab_departement)--;

		return tab_tmp;
	}
}


void detruireTabDepartement(Departement** tab_departement, int** taille_tab_departement)
{

	int i;

	if (*tab_departement != NULL)
	{

		for (i = 0; i < **taille_tab_departement; i++)
		{
			if (((*tab_departement) + i)->prefecture != NULL)
			{
				free(((*tab_departement) + i)->prefecture);
				((*tab_departement) + i)->prefecture = NULL;
			}

			if (((*tab_departement) + i)->nom_dep != NULL)
			{
				free(((*tab_departement) + i)->nom_dep);
				((*tab_departement) + i)->nom_dep = NULL;
			}

			if (((*tab_departement) + i)->numero_dep != NULL)
			{
				free(((*tab_departement) + i)->numero_dep);
				((*tab_departement) + i)->numero_dep = NULL;
			}

			detruireTabVille(&(((*tab_departement) + i)->tab_ville), &(((*tab_departement) + i)->taille_tab_ville));
		}



		free(*tab_departement);
		*tab_departement = NULL;
	}

	if (*taille_tab_departement != NULL)
	{

		free(*taille_tab_departement);
		*taille_tab_departement = NULL;
	}

}

