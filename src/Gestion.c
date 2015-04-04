#include "Gestion.h"
int nombrePointVirguleDansLigne(FILE* fichier)
{
	wchar_t lettre = NULL;
	int nombre=0;
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


void lectureFichiers(Region** tab_region, int** taille_tab_region)// => a remplacer par Dépendances
{
	FILE* fichier = NULL;
	wchar_t ligne_en_cours[1000];
	wchar_t numerodep_tmp[3];
	wchar_t departement_tmp[200];
	wchar_t prefecture_tmp[200];
	wchar_t nom_region_tmp[200];
	
	wchar_t* token = NULL;
	int is_departement_exist = 0;
	int is_region_exist = 0;
	int i = 0;
	int* taille_tab_departement = NULL ;
	int* ref_taille_tab_departement = NULL;
	Departement* tab_departement = NULL;
	int* ref_tab_departement = NULL;


// ****************--------------------- premier fichier, fichier des departements ---------------******************************
#if _DEBUG
	fichier = fopen("../../../../GIT/Recensement/Import/departements.csv", "r");
#endif
#if !_DEBUG
	fichier = fopen("../Import/departements.csv", "r");
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

			token = wcstok(ligne_en_cours, ";");
			wcscpy(numerodep_tmp, token);
			token = wcstok(NULL, ";");
			wcscpy(departement_tmp, token);
			token = wcstok(NULL, ";");
			wcscpy(prefecture_tmp, token);
			token = wcstok(NULL, "\n");
			wcscpy(nom_region_tmp, token);
			for (int compteur_region = 0; compteur_region < **taille_tab_region; compteur_region++)
			{
				if (!wcscmp(*(((*tab_region) + compteur_region)->nom_reg), nom_region_tmp))//on verifie si la region est deja cree
				{
					is_region_exist = 1;
					
				}
			}
			
/*			if (!is_region_exist)//sinon on l'ajoute
			{
				ajouterRegion(tab_region, nom_region_tmp, taille_tab_region);

				wprintf("Région creee");
				*tab_region = ((*tab_region) + i)->tab_departement;
				ref_tab_departement = &(((*tab_region) + i) -> tab_departement);
				taille_tab_departement = ((*tab_region) + i)->taille_tab_departement;//plantouile à mort
				ref_taille_tab_departement = &(((*tab_region) + i)->taille_tab_departement);
			}

			
	
			for (int compteur_departement = 0; compteur_departement < ref_taille_tab_departement; compteur_departement++)
			{
				if (!wcscmp(*((tab_departement + compteur_departement)->nom_dep), departement_tmp))
				{
					is_departement_exist = 1;
				}
			}
			
			if (!is_departement_exist)
			{

				//ajouterDepartement(ref_tab_departement, departement_tmp, numerodep_tmp, ref_taille_tab_departement);
				// ajouter prefecture

				wprintf("Departement cree");
			}


			lettre = fgetwc(fichier);
			i++;*/
		}
	
		fclose(fichier);
	}
// ****************--------------------- deuxieme fichier, fichier des recensements  ---------------******************************

		fichier = NULL;
		token = NULL;
		i = NULL;

		int nombre_recensements = 0;

#if _DEBUG
		fichier = fopen("../../../../GIT/Recensement/Import/recensements.csv", "r");
#endif
#if !_DEBUG
		fichier = fopen("../Import/recensements.csv", "r");
#endif
		if (fichier == NULL)
		{
			return NULL;
		}
		else
		{

			nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
			int tableau_annee_reference[50];
			rewind(fichier);
			fgetws(ligne_en_cours, sizeof(ligne_en_cours), fichier);
			token = wcstok(ligne_en_cours, ";");
			wcscpy(ligne_en_cours, token);
			for (i = 0; i < 2; i++)
			{
				token = wcstok(NULL, ";");
				wcscpy(ligne_en_cours, token);
			}

			for (i = 0; i<nombre_recensements - 1; i++)
			{
				token = wcstok(NULL, ";");
				wcscpy(ligne_en_cours, token);
				tableau_annee_reference[i] = _wtoi(ligne_en_cours);

				/* ligne en cours => tableau contenant les ann�es de references.*/
			}
			token = wcstok(NULL, "\n");
			wcscpy(ligne_en_cours, token);
			tableau_annee_reference[i] = _wtoi(ligne_en_cours);
			/* ligne en cours => tableau contenant les ann�es de references � la derni�re case.*/
			/*pour toutes les ann�es*/
			i = 0;
			while (fgetws(ligne_en_cours, sizeof(ligne_en_cours), fichier) != NULL)
			{

				token = wcstok(ligne_en_cours, ";");
				wcscpy(ligne_en_cours, token);
				/*depcom_ville -> ligne en cours*/

				token = wcstok(NULL, ";");
				wcscpy(ligne_en_cours, token);
				/*dep_ville -> ligne en cours*/
				token = wcstok(NULL, ";");
				wcscpy(ligne_en_cours, token);
				/*nom_ville -> ligne en cours*/
				for (i = 0; i < nombre_recensements - 1; i++)
				{
					token = wcstok(NULL, ";");
					wcscpy(ligne_en_cours, token);
					/*valeur_recensement_ville_+i-> ligne en cours*/
				}
				token = wcstok(NULL, "\n");
				wcscpy(ligne_en_cours, token);
				/* ligne en cours => tableau contenant les ann�es de references � la derni�re case.*/

			}
		}

		fclose(fichier);
}

void ecritureFichierDepartements(Region* tab_region, int* taille_tab_region)
{
	FILE* fichier = NULL;
	int i;
	int no_dep;
	wchar_t nom_dep[200];
	wchar_t prefecture[200];
	wchar_t nom_region[200];
#if _DEBUG
	fichier = fopen("../../../../GIT/Recensement/Import/departements.csv", "w+");
#endif
#if !_DEBUG
	fichier = fopen("../Import/departements.csv", "w+");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else
	{
		for (i = 0; i < *taille_tab_region; i++)
		{	
			/*no_dep = *tab_region ->;
			nom_dep = tab_region;
			prefecture = tab_region;
			nom_region = (*(tab_region + i) ->nom_reg);   => i don't fucking know what i'm supposed to do here*/
		
			fwprintf(fichier, "%d;%ls;%ls;%ls\n", no_dep, nom_dep, prefecture, nom_region);
		}
		fclose(fichier);
	}
	
}

void ecritureFichierRecensements(Region* tab_region, int* taille_tab_region)
{
	FILE* fichier = NULL;
	int i;
#if _DEBUG
	fichier = fopen("../../../../GIT/Recensement/Import/recensements.csv", "w+");
#endif
#if !_DEBUG
	fichier = fopen("../Import/recensements.csv", "w+");
#endif
	if (fichier == NULL)
	{
		return NULL;
	}
	else// ! Les rencement sont par ordre antechronologique !
	{
		int nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
		fwprintf(fichier, "%ls;%ls;%ls;", "DEPCOM", "DEP", "LIBMIN");//cas de la premiere ligne
		for (i = 0; i < nombre_recensements; i++)
		{
			fwprintf(fichier, "%ls;", "Recemement + i ");//Ou est stocke les années de recensement ?
		}
		for (i = 0; i < "nombre ville total"; i++)//comment connaitre le nombre de ville au total?
		{
			fwprintf(fichier, "\n%d;%d;%ls;", "dep_com + i", "numero_dep +i", "nom_ville + i");//Ou sont placées ces merdes..
			for (i = 0; i < nombre_recensements; i++)
			{
				fwprintf(fichier, "%ls;", "Recemement + i ");//même combat
			}
		}
		fclose(fichier);
	}
}
