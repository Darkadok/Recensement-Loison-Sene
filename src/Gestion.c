#include "Gestion.h"
int nombrePointVirguleDansLigne(FILE* fichier)
{
	char lettre = NULL;
	int nombre=0;
	while (lettre != '\n')//premiere ligne, cas general
	{
		fscanf(fichier, "%c", &lettre);
		if (lettre == ';')
		{
			nombre++;
		}
	}
	return nombre;
}


void lectureFichierDepartement(Region** tab_region, int** taille_tab_region)// => a remplacer par D�pendances de Region
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

				printf("R�gion cr��e");
				*tab_region = ((*tab_region) + i)->tab_departement;
				ref_tab_departement = &(((*tab_region) + i) -> tab_departement);
				taille_tab_departement = ((*tab_region) + i)->taille_tab_departement;//plantouile � mort
				ref_taille_tab_departement = &(((*tab_region) + i)->taille_tab_departement);

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
			i++;
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
		
		nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
		rewind(fichier);
		fgets(ligne_en_cours, sizeof(ligne_en_cours), fichier);

		token = strtok(ligne_en_cours, ';');

		/*fgets poru avoir toute la chaine, dans une variable machaine, 
		definir une var char* token, token = strtok(machaine, ';'), strcopy token => ... . 
		tant que fgets != NULL {} \!/ seconde utilisation NUll � la place de machaine de strtok, */
	}
	
	fclose(fichier);
}


void ecritureFichierDepartement(Region* tab_region, int* taille_tab_region)
{
	FILE* fichier = NULL;
	int i;
	int no_dep;
	char nom_dep[200];
	char prefecture[200];
	char nom_region[200];
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
		
			fprintf(fichier, "%d;%s;%s;%s\n", no_dep, nom_dep, prefecture, nom_region);
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
	else
	{
		int nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
		fprintf(fichier, "%s;%s;%s;", "DEPCOM","DEP","LIBMIN");//cas de la premiere ligne
		for (i = 0; i < nombre_recensements; i++)
		{
			fprintf(fichier, "%s;", "Recemement + i ");//Ou est stocke les ann�es de recensement ?
		}
		for (i = 0; i < "nombre ville total"; i++)//comment connaitre le nombre de ville au total?
		{
			fprintf(fichier, "\n%d;%d;%s;", "dep_com + i", "numero_dep +i", "nom_ville + i");//Ou sont plac�es ces merdes..
			for (i = 0; i < nombre_recensements; i++)
			{
				fprintf(fichier, "%s;", "Recemement + i ");//m�me combat
			}
		}
		fclose(fichier);
	}
	
}