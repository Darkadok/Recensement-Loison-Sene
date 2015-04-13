/*
Override
GestionFichier.c
by Merlin
2014/2015

@author Alexandre Courcoul, Merlin Loison & Massamba Sène


**/

#include "GestionFichier.h"

int nombrePointVirguleDansLigne(FILE* fichier)
{
	wchar_t lettre = NULL;
	int nombre = 0;
	while (lettre != '\n')//premiere ligne, cas general
	{
		fwscanf(fichier, L"%lc", &lettre);
		if (lettre == ';')
		{
			nombre++;
		}
	}
	return nombre;
}


void* lectureFichiers(Region** tab_region, int** taille_tab_region)// => a remplacer par Dépendances
{
	FILE* fichier = NULL;
	wchar_t ligne_en_cours[1000] = { 0 };
	wchar_t numerodep_tmp[10] = { 0 };
	wchar_t departement_tmp[200] = { 0 };
	wchar_t prefecture_tmp[200] = { 0 };
	wchar_t nom_region_tmp[200] = { 0 };;
	wchar_t* token = NULL;
	int is_departement_exist = 0;
	int is_region_exist = 0;
	int i = 0;
	int compteur_region;
	int* taille_tab_departement = NULL;
	int* ref_taille_tab_departement = NULL;
	Departement* tab_departement = NULL;
	int* ref_tab_departement = NULL;

	// ****************--------------------- premier fichier, fichier des departements ---------------******************************
#if _DEBUG
	fichier = _wfopen(L"../../../../GIT/Recensement/Import/departements.csv", L"r");
#endif
#if !_DEBUG
	fichier = _wfopen(L"../Import/departements.csv", L"r");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else
	{
		*taille_tab_region = malloc(sizeof(int));
		**taille_tab_region = 0;

		while ((fgetws(ligne_en_cours, sizeof(ligne_en_cours), fichier)) != NULL)// parcours le fichier par ligne
		{
			is_region_exist = 0;
			token = wcstok(ligne_en_cours, L";");
			wcscpy(numerodep_tmp, token);
			token = wcstok(NULL, L";");
			wcscpy(departement_tmp, token);
			token = wcstok(NULL, L";");
			wcscpy(prefecture_tmp, token);
			token = wcstok(NULL, L"\n");
			wcscpy(nom_region_tmp, token);

			wprintf(L"%ls \n", departement_tmp);
			for (compteur_region = 0; compteur_region < **taille_tab_region; compteur_region++)
			{
				if (!(wcscmp((((*tab_region) + compteur_region)->nom_reg), nom_region_tmp)))//on verifie si la region est deja cree
				{
					is_region_exist = 1;
					ajouterDepartement(&(((*tab_region) + compteur_region)->tab_departement), departement_tmp, numerodep_tmp, prefecture_tmp, &(((*tab_region) + compteur_region)->taille_tab_departement));
					wprintf(L"Departement ajouté à région existante. \n");
					wprintf(L"%d \n", **taille_tab_region);
					break;
				}
			}

			if (!is_region_exist)//sinon on l'ajoute
			{
				ajouterRegion(tab_region, nom_region_tmp, taille_tab_region);
				wprintf(L"R%lcgion %ls cr%lc%lce \n", 130, nom_region_tmp, 130, 130);
				wprintf(L"%d \n", **taille_tab_region);
(				ajouterDepartement(&(((*tab_region) + (**taille_tab_region) - 1)->tab_departement), departement_tmp, numerodep_tmp, prefecture_tmp, &(((*tab_region) + **taille_tab_region - 1)->taille_tab_departement)));//ne marche pas encore

			}
		}
		fclose(fichier);

	}
	// ****************--------------------- deuxieme fichier, fichier des recensements  ---------------******************************

	fichier = NULL;
	token = NULL;
	i = NULL;



#if _DEBUG
	fichier = _wfopen(L"../../../../GIT/Recensement/Import/recensements.csv", L"r");
#endif
#if !_DEBUG
	fichier = _wfopen(L"../Import/recensements.csv", L"r");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else
	{
		int nombre_recensements = 0;
		nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
		int tableau_annee_reference[50];
		int valeur_recensement_tmp = 0;
		wchar_t nom_ville_tmp[200];
		wchar_t depcom_tmp[200];
		wchar_t no_dep_tmp[15];
		int is_num_dep_egal = 0;
		int nombre_ville_total = 0;
		Departement** tmp;

		rewind(fichier);
		fgetws(ligne_en_cours, sizeof(ligne_en_cours), fichier);
		token = wcstok(ligne_en_cours, L";");
		wcscpy(ligne_en_cours, token);
		for (i = 0; i < 2; i++)
		{
			token = wcstok(NULL, L";");
			wcscpy(ligne_en_cours, token);
		}

		for (i = 0; i < nombre_recensements - 1; i++)
		{
			token = wcstok(NULL, L";");
			wcscpy(ligne_en_cours, token);
			tableau_annee_reference[i] = _wtoi(ligne_en_cours);

		}
		token = wcstok(NULL, L"\n");
		wcscpy(ligne_en_cours, token);
		tableau_annee_reference[i] = _wtoi(ligne_en_cours);

		while (fgetws(ligne_en_cours, sizeof(ligne_en_cours), fichier) != NULL)
		{
			wprintf(L"%ls", ligne_en_cours);
			token = wcstok(ligne_en_cours, L";");
			wcscpy(depcom_tmp, token);//depcom
			token = wcstok(NULL, L";");
			wcscpy(no_dep_tmp, token);//dep
			token = wcstok(NULL, L";");
			wcscpy(nom_ville_tmp, token);//nomville

			for (i = 0; i < **taille_tab_region; i++)//pour chaque région
			{
				tmp = &(((*tab_region) + i)->tab_departement);
				for (int j = 0; j < *(((*tab_region) + i)->taille_tab_departement); j++)//pour chaque dep de cette region
				{
					
					/*wprintf(L"No de dep en cours : %ls \n", ((*tmp) + j)->numero_dep);
					wprintf(L"No lu dans fichier : %ls \n", no_dep_tmp);*/

					if ((wcscmp(((*tmp) + j)->numero_dep, L"2A") == 0) || (wcscmp(((*tmp) + j)->numero_dep, L"2B") == 0) || (wcscmp(no_dep_tmp, L"2B") == 0) || (wcscmp(no_dep_tmp, L"2A") == 0))//cas speciaux de la CORSE
					{
						if (wcscmp((((*tmp) + j)->numero_dep), no_dep_tmp) == 0)
						{
							is_num_dep_egal = 1;
						}
					}
					else
					{
						if (_wtoi(((*tmp) + j)->numero_dep) == _wtoi(no_dep_tmp))
						{
							is_num_dep_egal = 1;
						}
					}
					if (is_num_dep_egal) //si le no du dep = no en cours => ya SOUCIS
					{
						ajouterVille(&(((*tmp) + j)->tab_ville), nom_ville_tmp, depcom_tmp, &(((*tmp) + j)->taille_tab_ville));
						nombre_ville_total++;

						wprintf(L"%ls ajouté dans la region %ls", nom_ville_tmp, ((*tab_region) + i)->nom_reg);
						wprintf(L" dans le departement %ls\n", (((*tmp) + j)->nom_dep));
						wprintf(L"nombre ville total : %d \n", nombre_ville_total);
						int taille_tableau_ville_tmp = *(((*tmp) + j)->taille_tab_ville);
						Ville** ville_tmp = &(((*tmp) + j)->tab_ville);
						Ville* ville_en_cours = ((*ville_tmp) + taille_tableau_ville_tmp - 1);

						int k;

						for (k = 0; k < nombre_recensements - 1; k++)
						{
							token = wcstok(NULL, L";");
							wcscpy(ligne_en_cours, token);
							valeur_recensement_tmp = _wtoi(ligne_en_cours);
							ajouterRecensement(&(ville_en_cours->tab_recensement), tableau_annee_reference[k], valeur_recensement_tmp, &(ville_en_cours->taille_tab_recensement));
						}
						token = wcstok(NULL, L"\n");
						wcscpy(ligne_en_cours, token);
						valeur_recensement_tmp = _wtoi(ligne_en_cours);
						ajouterRecensement(&(ville_en_cours->tab_recensement), tableau_annee_reference[k], valeur_recensement_tmp, &(ville_en_cours->taille_tab_recensement));
						is_num_dep_egal = 0;
					}
				}
			}
		}
	}
	rechercheVilleByNom((*tab_region + 1)->tab_departement->tab_ville, (*tab_region + 1)->tab_departement->taille_tab_ville, L"abbecourt");
	fclose(fichier);
}

void* ecritureFichierDepartements(Region* tab_region, int* taille_tab_region)
{
	//fichier pas range
	FILE* fichier = NULL;
	int i;
	Departement* tmp;
#if _DEBUG
	fichier = _wfopen(L"../../../../GIT/Recensement/Import/departements_test.csv", L"w+");//!!!--A changer --!!!
#endif
#if !_DEBUG
	fichier = _wfopen(L"../Import/departements.csv", L"w+");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else
	{
		for (i = 0; i < *taille_tab_region; i++)//héhéhé
		{
			tmp = ((tab_region)+i)->tab_departement;
			for (int j = 0; j < *((tab_region)+i)->taille_tab_departement; j++)//pour chaque dep de cette region	
			{
				fwprintf(fichier, L"%ls;%ls;%ls;%ls\n", (tmp + j)->numero_dep, (tmp + j)->nom_dep, (tmp + j)->prefecture, (tab_region + i)->nom_reg);
			}
		}
		wprintf(L"ecriture ok !");
		fclose(fichier);
	}

}

void* ecritureFichierRecensements(Region* tab_region, int* taille_tab_region)
{
	FILE* fichier = NULL;
	Recensement* no_annee_tmp;
	Departement* tmp;
	Ville* ville_tmp;
	Recensement* recen_tmp;
	int nombre_ville_ecrit = 0;

	int i;
	fichier = _wfopen(L"../Import/recensements.csv", L"r");
	int nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
	fclose(fichier);
	fichier = NULL;
#if _DEBUG
	fichier = _wfopen(L"../../../../GIT/Recensement/Import/recensements_test.csv", L"w+");
#endif
#if !_DEBUG
	fichier = _wfopen(L"../Import/recensements.csv", L"w+");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else// ! Les recencements sont par ordre antechronologique !
	{

		fwprintf(fichier, L"%ls;%ls;%ls;", L"DEPCOM", L"DEP", L"LIBMIN");//cas de la premiere ligne

		for (i = 0; i < nombre_recensements - 1; i++)//annees de references
		{
			no_annee_tmp = tab_region->tab_departement->tab_ville->tab_recensement + i;
			fprintf(fichier, "%d;", no_annee_tmp->annee);
		}
		no_annee_tmp = tab_region->tab_departement->tab_ville->tab_recensement + (nombre_recensements - 1);
		fprintf(fichier, "%d", no_annee_tmp->annee);

		for (i = 0; i < *taille_tab_region; i++)//pour chaque reg
		{
			for (int j = 0; j < *((tab_region)+i)->taille_tab_departement; j++)//pour chaque dep de cette region
			{
				tmp = (tab_region + i)->tab_departement + j ;
				for (int l = 0; l < *(tmp->taille_tab_ville); l++)//pour chaque ville
				{	
					ville_tmp = tmp->tab_ville + l;
					
					if (wcscmp(tmp->numero_dep, L"2A") == 0 || wcscmp(tmp->numero_dep, L"2B") == 0)
					{
						fwprintf(fichier, L"\n%ls;%ls;%ls;", ville_tmp->dep_com, tmp->numero_dep, ville_tmp->nom_ville);
						nombre_ville_ecrit++;
					}
					else
					{
						fwprintf(fichier, L"\n%ls;%d;%ls;", ville_tmp->dep_com, _wtoi(tmp->numero_dep), ville_tmp->nom_ville);
						nombre_ville_ecrit++;
					}
					
					for (int k = 0; k < nombre_recensements - 1; k++)//pour chaque recensement
					{
						recen_tmp = ville_tmp->tab_recensement + k;
						fprintf(fichier, "%d;", recen_tmp->valeur_recen);
					}
					recen_tmp = ville_tmp->tab_recensement + (nombre_recensements - 1);
					fprintf(fichier, "%d", recen_tmp->valeur_recen);
				}
			}
		}
	fclose(fichier);
	printf("\n\n\nFELICITATION l'ecriture des %d villes est ok !\n\n", nombre_ville_ecrit);
	}
}
