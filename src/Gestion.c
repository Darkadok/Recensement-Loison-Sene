#include "Gestion.h"
int nombrePointVirguleDansLigne(FILE* fichier)
{
	char lettre = NULL;
	int nombre=0;
	while (lettre != '\n')//premiere ligne, cas particulier
	{
		fscanf(fichier, "%c", &lettre);
		if (lettre == ';')
		{
			nombre++;
		}
	}
	return nombre;
}


void lectureFichierDepartement(Region** tab_region, int** taille_tab_region)// => a remplacer par Dépendances de Region
{
	FILE* fichier = NULL;
	char lettre = NULL;
	char numerodep_tmp[3];
	char departement_tmp[200];
	char prefecture_tmp[200];
	char region_tmp[200];
	int is_departement_exist = 0;
	int is_region_exist = 0;
	int i = 0;
	int* taille_tab_departement = NULL ;
	int* ref_taille_tab_departement = NULL;
	Departement* tab_departement = NULL;
	int* ref_tab_departement = NULL;

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

		while (lettre != 'EOF')// parcours le fichier par ligne
		{
			fscanf(fichier, "%3[^;];%200[^;];%200[^;];%s", numerodep_tmp, departement_tmp, prefecture_tmp, region_tmp);
			printf("%s %s %s %s", numerodep_tmp, departement_tmp, prefecture_tmp, region_tmp);
		

			for (int compteur_region = 0; compteur_region < **taille_tab_region; compteur_region++)
			{
				if (!strcmp(*(((*tab_region) + compteur_region)->nom_reg), region_tmp))//on verifie si la region est deja cree
				{
					is_region_exist = 1;
					
				}
			}
			
			if (!is_region_exist)//sinon on l'ajoute
			{

				ajouterRegion(tab_region, region_tmp, taille_tab_region);

				printf("Région créée");
				*tab_region = ((*tab_region) + i)->tab_departement;
				ref_tab_departement = &(((*tab_region) + i) -> tab_departement);
				taille_tab_departement = ((*tab_region) + i)->taille_tab_departement;//plantouile à mort
				ref_taille_tab_departement = &(((*tab_region) + i)->taille_tab_departement);
				
				i++;
			}

			
	
			for (int compteur_departement = 0; compteur_departement < ref_taille_tab_departement; compteur_departement++)
			{
				if (!strcmp(*((tab_departement + compteur_departement)->nom_dep), departement_tmp))
				{
					is_departement_exist = 1;
				}
			}
			
			if (!is_departement_exist)
			{

				ajouterDepartement(ref_tab_departement, departement_tmp, numerodep_tmp, ref_taille_tab_departement);
				// ajouter prefecture

				printf("Departement cree");
			}


			lettre = fgetc(fichier);
		}

		fclose(fichier);
	}
}

void lectureFichierRecensements()
{
	FILE* fichier = NULL;
	char lettre = NULL;
	char* token = NULL;
	char ligne_en_cours[1000];
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
		
		nombre_recensements -= 2;
		rewind(fichier);
		fgets(ligne_en_cours, sizeof(ligne_en_cours), fichier);

		token = strtok(ligne_en_cours, ';');

		/*fgets poru avoir toute la chaine, dans une variable machaine, 
		definir une var char* token, token = strtok(machaine, ';'), strcopy token => ... . 
		tant que fgets != NULL {} \!/ seconde utilisation NUll à la place de machaine de strtok, */
	}
	
	fclose(fichier);
}



ecritureFichierRecensements()
{
	return 0;
}

void ecritureFichierDepartement(Region* tab_region, int* taille_tab_region)
{
	FILE* fichier = NULL;
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
}