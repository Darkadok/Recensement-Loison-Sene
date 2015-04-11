/*
Override
Ville.c

2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène

**/

#include "Ville.h"


void creerTabVille(Ville** tab_ville, int** taille_tab_ville, wchar_t nom_ville[], wchar_t dep_com[])
{
	*taille_tab_ville = malloc(sizeof(int));
	**taille_tab_ville = 1;

	(*tab_ville) = malloc(sizeof(Ville)*(**taille_tab_ville));
	(*tab_ville)->nom_ville = malloc(sizeof(wchar_t)*(wcslen(nom_ville) + 1));
	(*tab_ville)->dep_com = malloc(sizeof(wchar_t)*(wcslen(dep_com) + 1));
	(*tab_ville)->tab_recensement = NULL;
	(*tab_ville)->taille_tab_recensement = NULL;

	wcscpy((*tab_ville)->nom_ville, nom_ville);
	wcscpy((*tab_ville)->dep_com, dep_com);


}


void ajouterVille(Ville** tab_ville, wchar_t nom_ville[], wchar_t dep_com[], int** taille_tab_ville)
{
	int i = 0;
	int j;
	Recensement* tab_recensement_tmp;


	if (*taille_tab_ville == NULL)
	{
		creerTabVille(tab_ville, taille_tab_ville, nom_ville, dep_com);
	}

	else
	{
		*tab_ville = realloc(*tab_ville, sizeof(Ville)*((**taille_tab_ville) + 1));


		/****** On remplit la dernière case ******/

		((*tab_ville) + **taille_tab_ville)->nom_ville = malloc(sizeof(wchar_t)* (wcslen(nom_ville) + 1));

		wcscpy(((*tab_ville) + **taille_tab_ville)->nom_ville, nom_ville);

		((*tab_ville) + **taille_tab_ville)->dep_com = malloc(sizeof(wchar_t)*(wcslen(dep_com) + 1));
		wcscpy(((*tab_ville) + **taille_tab_ville)->dep_com, dep_com);

		((*tab_ville) + **taille_tab_ville)->tab_recensement = NULL;
		((*tab_ville) + **taille_tab_ville)->taille_tab_recensement = NULL;

		(**taille_tab_ville)++;
	}
}


int rechercheVilleByNom(Ville* tab_ville, int* taille_tab_ville, wchar_t nom_ville[])
{
	for (int i = 0; i < *taille_tab_ville; i++)
	{
		if (!wcscmp((tab_ville + i)->nom_ville, nom_ville))
		{
			return i;
		}

	}

	return -1;
}

int rechercheVilleByDepCom(Ville* tab_ville, int* taille_tab_ville, wchar_t dep_com[])
{
	for (int i = 0; i < *taille_tab_ville; i++)
	{
		if (wcscpy((tab_ville + i)->dep_com, dep_com))
		{
			return i;
		}

	}

	return -1;


}


void modifierNomVille(Ville* ville, wchar_t nom_ville[])
{
	free(ville->nom_ville);
	ville->nom_ville = malloc(sizeof(wchar_t)* (wcslen(nom_ville) + 1));
	wcscpy(ville->nom_ville, nom_ville);
}

void modifierDepComVille(Ville* ville, wchar_t dep_com[])
{
	ville->dep_com = dep_com;
}

void* supprimerVille(Ville** tab_ville, int** taille_tab_ville, Ville* ville_supp)
{
	int i;
	int j = 0;
	int k;
	Recensement* tab_recensement_tmp;

	if (**taille_tab_ville == 1)
	{
		detruireTabVille(tab_ville, taille_tab_ville);
		return NULL;
	}

	else
	{

		Ville* tab_tmp = malloc(sizeof(Ville)*((**taille_tab_ville) - 1));

		for (i = 0; i<**taille_tab_ville; i++)
		{

			/****** Tant  qu'on ne tombe pas sur la ville à supprimer, on recopie le contenu des structures *****/

			if (wcscmp(((*tab_ville) + i)->nom_ville, ville_supp->nom_ville))
			{
				(tab_tmp + j)->nom_ville = malloc(sizeof(wchar_t)* (wcslen(((*tab_ville) + i)->nom_ville) + 1));
				wcscpy((tab_tmp + j)->nom_ville, ((*tab_ville) + i)->nom_ville);

				(tab_tmp + j)->dep_com = malloc(sizeof(wchar_t)*(wcslen(((*tab_ville) + i)->dep_com) + 1));
				wcscpy((tab_tmp + j)->dep_com, ((*tab_ville) + i)->dep_com);

				(tab_tmp + j)->tab_recensement = NULL;
				(tab_tmp + j)->taille_tab_recensement = NULL;


				/****** Pour chaque ville, on recopie son tableau de rencensements ******/

				if (((*tab_ville) + i)->tab_recensement != NULL)
				{
					tab_recensement_tmp = ((*tab_ville) + i)->tab_recensement;

					for (k = 0; k < *(((*tab_ville) + i)->taille_tab_recensement); k++)
					{

						ajouterRecensement(&((tab_tmp + j)->tab_recensement), (tab_recensement_tmp + k)->annee, (tab_recensement_tmp + k)->valeur_recen, &((tab_tmp + j)->taille_tab_recensement));
					}
				}

				j++;
			}

			/****** Pour la ville à supprimer, on détruit les recensements ******/

			else
			{
				detruireTabRecensement(&(((*tab_ville) + i)->tab_recensement), &(((*tab_ville) + i)->taille_tab_recensement));
			}
		}

		(**taille_tab_ville)--;

		if (*tab_ville != NULL)
		{
			if ((*tab_ville)->nom_ville != NULL)
			{
				free((*tab_ville)->nom_ville);
				(*tab_ville)->nom_ville = NULL;
			}

			if ((*tab_ville)->dep_com != NULL)
			{
				free((*tab_ville)->dep_com);
				(*tab_ville)->dep_com = NULL;
			}

			free(*tab_ville);
			*tab_ville = NULL;
		}

		return tab_tmp;
	}
}

void detruireTabVille(Ville** tab_ville, int** taille_tab_ville)
{
	int i;

	if (*tab_ville != NULL)
	{

		for (i = 0; i<**taille_tab_ville; i++)
		{
			detruireTabRecensement(&(((*tab_ville) + i)->tab_recensement), &(((*tab_ville) + i)->taille_tab_recensement));
		}

		for (i = 0; i<**taille_tab_ville; i++)
		{
			if (((*tab_ville) + i)->nom_ville != NULL)
			{
				free(((*tab_ville) + i)->nom_ville);
				((*tab_ville) + i)->nom_ville = NULL;
			}

			if (((*tab_ville) + i)->dep_com != NULL)
			{
				free(((*tab_ville) + i)->dep_com);
				((*tab_ville) + i)->dep_com = NULL;
			}
		}

		free(*tab_ville);
		*tab_ville = NULL;
	}

	if (*taille_tab_ville != NULL)
	{
		free(*taille_tab_ville);
		*taille_tab_ville = NULL;
	}
}

void afficherVille(Ville* ville)
{
	wprintf(L"Nom : %ls\n", ville->nom_ville);
}























/*

Ville* creerTabVille(Ville** tab_ville, int** taille_tab_ville, wchar_t nom_ville[], wchar_t dep_com[])
{
	*taille_tab_ville = malloc(sizeof(int));
	**taille_tab_ville = 1;

	(*tab_ville) = malloc(sizeof(Ville)*(**taille_tab_ville));
	(*tab_ville)->nom_ville = malloc(sizeof(wchar_t)*(wcslen(nom_ville) + 1));
	(*tab_ville)->dep_com = malloc(sizeof(wchar_t)*(wcslen(dep_com) + 1));
	(*tab_ville)->tab_recensement = NULL;
	(*tab_ville)->taille_tab_recensement = NULL;

	wcscpy((*tab_ville)->nom_ville, nom_ville);
	wcscpy((*tab_ville)->dep_com, dep_com);

	return *tab_ville;
}


Ville* ajouterVille(Ville** tab_ville, wchar_t nom_ville[], wchar_t dep_com[], int** taille_tab_ville)
{
	int i = 0;
	int j;
	Recensement* tab_recensement_tmp;


	if (*taille_tab_ville == NULL)
	{
		*tab_ville = creerTabVille(tab_ville, taille_tab_ville, nom_ville, dep_com);
	}

	else
	{
		Ville* tab_nouveau = malloc(sizeof(Ville)*((**taille_tab_ville) + 1));

		******* On recopie le contenu du tableau champs par champs ******

		for (i = 0; i<**taille_tab_ville; i++)
		{
			(tab_nouveau + i)->nom_ville = malloc(sizeof(wchar_t)* (wcslen(((*tab_ville) + i)->nom_ville) + 1));
			wcscpy((tab_nouveau + i)->nom_ville, ((*tab_ville) + i)->nom_ville);

			(tab_nouveau + i)->dep_com = malloc(sizeof(wchar_t)*(wcslen(((*tab_ville) + i)->dep_com) + 1));
			wcscpy((tab_nouveau + i)->dep_com, ((*tab_ville) + i)->dep_com);

			(tab_nouveau + i)->tab_recensement = NULL;
			(tab_nouveau + i)->taille_tab_recensement = NULL;


			****** Pour chaque case du tableau de villes, on recopie le tableau de recensements ******

			if (((*tab_ville) + i)->tab_recensement != NULL)
			{
				tab_recensement_tmp = ((*tab_ville) + i)->tab_recensement;

				for (j = 0; j < *(((*tab_ville) + i)->taille_tab_recensement); j++)
				{

					(tab_nouveau + i)->tab_recensement = ajouterRecensement(&((tab_nouveau + i)->tab_recensement), (tab_recensement_tmp + j)->annee, (tab_recensement_tmp + j)->valeur_recen, &((tab_nouveau + i)->taille_tab_recensement));
				}
			}
		}


		 On remplit la dernière case 

		(tab_nouveau + i)->nom_ville = malloc(sizeof(wchar_t)* (wcslen(nom_ville) + 1));

		wcscpy((tab_nouveau + i)->nom_ville, nom_ville);

		(tab_nouveau + i)->dep_com = malloc(sizeof(wchar_t)*(wcslen(dep_com) + 1));
		wcscpy((tab_nouveau + i)->dep_com, dep_com);

		(tab_nouveau + i)->tab_recensement = NULL;
		(tab_nouveau + i)->taille_tab_recensement = NULL;

		(**taille_tab_ville)++;

		if (*tab_ville != NULL)
		{
			if ((*tab_ville)->nom_ville != NULL)
			{
				free((*tab_ville)->nom_ville);
			}

			if ((*tab_ville)->dep_com != NULL)
			{
				free((*tab_ville)->dep_com);
			}

			free(*tab_ville);
		}

		return tab_nouveau;
	}

	return *tab_ville;
}


int rechercheVilleByNom(Ville* tab_ville, int* taille_tab_ville, wchar_t nom_ville[])
{
	for (int i = 0; i < *taille_tab_ville; i++)
	{
		if (!wcscmp((tab_ville + i)->nom_ville, nom_ville))
		{
			return i;
		}

	}

	return -1;
}

int rechercheVilleByDepCom(Ville* tab_ville, int* taille_tab_ville, wchar_t dep_com[])
{
	for (int i = 0; i < *taille_tab_ville; i++)
	{
		if (wcscpy((tab_ville + i)->dep_com, dep_com))
		{
			return i;
		}

	}

	return -1;


}

void afficherVille(Ville* ville)
{



}


void modifierNomVille(Ville* ville, wchar_t nom_ville[])
{
	free(ville->nom_ville);
	ville->nom_ville = malloc(sizeof(wchar_t)* (wcslen(nom_ville) + 1));
	wcscpy(ville->nom_ville, nom_ville);
}

void modifierDepComVille(Ville* ville, wchar_t dep_com[])
{
	ville->dep_com = dep_com;
}

void* supprimerVille(Ville** tab_ville, int** taille_tab_ville, Ville* ville_supp)
{
	int i;
	int j = 0;
	int k;
	Recensement* tab_recensement_tmp;

	if (**taille_tab_ville == 1)
	{
		detruireTabVille(tab_ville, taille_tab_ville);
		return NULL;
	}

	else
	{

		Ville* tab_tmp = malloc(sizeof(Ville)*((**taille_tab_ville) - 1));

		for (i = 0; i<**taille_tab_ville; i++)
		{
Tant  qu'on ne tombe pas sur la ville à supprimer, on recopie le contenu des structures 

			if (wcscmp(((*tab_ville) + i)->nom_ville, ville_supp->nom_ville))
			{
				(tab_tmp + j)->nom_ville = malloc(sizeof(wchar_t)* (wcslen(((*tab_ville) + i)->nom_ville) + 1));
				wcscpy((tab_tmp + j)->nom_ville, ((*tab_ville) + i)->nom_ville);

				tab_tmp->dep_com = malloc(sizeof(wchar_t)*(wcslen(((*tab_ville) + i)->dep_com) + 1));
				wcscpy((tab_tmp + j)->dep_com, ((*tab_ville) + i)->dep_com);

				(tab_tmp + j)->tab_recensement = NULL;
				(tab_tmp + j)->taille_tab_recensement = NULL;

 Pour chaque ville, on recopie son tableau de rencensements 

				if (((*tab_ville) + i)->tab_recensement != NULL)
				{
					tab_recensement_tmp = ((*tab_ville) + i)->tab_recensement;

					for (k = 0; k < *(((*tab_ville) + i)->taille_tab_recensement); k++)
					{

						(tab_tmp + j)->tab_recensement = ajouterRecensement(&((tab_tmp + j)->tab_recensement), (tab_recensement_tmp + k)->annee, (tab_recensement_tmp + k)->valeur_recen, &((tab_tmp + j)->taille_tab_recensement));
					}
				}

				j++;
			}


			else
			{
				detruireTabRecensement(&(((*tab_ville) + i)->tab_recensement), &(((*tab_ville) + i)->taille_tab_recensement));
			}
		}

		(**taille_tab_ville)--;

		return tab_tmp;
	}
}

void detruireTabVille(Ville** tab_ville, int** taille_tab_ville)
{
	int i;

	if (*tab_ville != NULL)
	{

		for (i = 0; i<**taille_tab_ville; i++)
		{
			detruireTabRecensement(&(((*tab_ville) + i)->tab_recensement), &(((*tab_ville) + i)->taille_tab_recensement));
		}

		for (i = 0; i<**taille_tab_ville; i++)
		{
			if (((*tab_ville) + i)->nom_ville != NULL)
			{
				free(((*tab_ville) + i)->nom_ville);
				((*tab_ville) + i)->nom_ville = NULL;
			}

			if (((*tab_ville) + i)->dep_com != NULL)
			{
				free(((*tab_ville) + i)->dep_com);
				((*tab_ville) + i)->dep_com = NULL;
			}
		}

		free(*tab_ville);
		*tab_ville = NULL;
	}

	if (*taille_tab_ville != NULL)
	{
		free(*taille_tab_ville);
		*taille_tab_ville = NULL;
	}
}
*/