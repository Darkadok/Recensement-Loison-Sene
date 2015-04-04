
#include "Region.h"
#include "Gestion.h"

int main()
{
	



/*	char vec[10];

	short i;

	for (i = 0; i<10; i++)

	{
		vec[i] = getch();

		if (vec[i] == 13)

		{

			i = 10;

		}

	}

	printf("%s", vec);
	system("pause");*/

	//printf("personnes ont \x82t\x82 recens\x82es");
	int i;
	int* taille_tab_etoile = NULL;
	Region* tab_region = NULL;

	tab_region = ajouterRegion(tab_region, "SilenceIsGolden", &taille_tab_etoile);
	//tab_region = ajouterRegion(tab_region, "toto", &taille_tab_etoile);
	//tab_region = ajouterRegion(tab_region, "titi", &taille_tab_etoile);
	//tab_region = ajouterRegion(tab_region, "tata", &taille_tab_etoile);




	
	

	/*for (i = 0; i < *taille_tab_etoile; i++)
	{
		printf("%s, ", (tab_region + i)->nom_reg);
		printf("\n");
	}*/

	Departement* tab_departement_tmp;
	tab_departement_tmp = (tab_region)->tab_departement;


	(tab_region)->tab_departement = ajouterDepartement((tab_region)->tab_departement, "A", 1, "dupont1", &(tab_region->taille_tab_departement));
	(tab_region)->tab_departement = ajouterDepartement((tab_region)->tab_departement, "B", 1, "dupont2", &(tab_region->taille_tab_departement));
	(tab_region)->tab_departement = ajouterDepartement((tab_region)->tab_departement, "C", 1, "dupont3", &(tab_region->taille_tab_departement));
	(tab_region)->tab_departement = ajouterDepartement((tab_region)->tab_departement, "D", 1, "dupont4", &(tab_region->taille_tab_departement));


	tab_region = supprimerRegion(&tab_region, tab_region, &taille_tab_etoile);

	/*for (int i = 0; i < *(tab_region->taille_tab_departement); i++)
	{
		printf("%s, %d, %s\n", (tab_departement_tmp + i)->nom_dep, (tab_departement_tmp + i)->numero_dep, (tab_departement_tmp + i)->prefecture);
	}

	//detruireTabRegion(&tab_region, &taille_tab_etoile);

	 //ajouterDepartement(tab, char nom_dep[], int numero_dep, int** taille_tab_departement);

	/*for ( i = 0; i < *taille_tab_etoile; i++)
	{
		 ajouterDepartement(&((tab_region+i)->tab_departement), "A",1, &((tab_region+i)->taille_tab_departement));
		 printf("%s-", (tab_region+i)->tab_departement->nom_dep);
	}

	for ( i = 0; i < *taille_tab_etoile; i++)
	{
		 ajouterVille(&(*(tab_region+i).(*(tab_departement+i))->tab_ville), "B", "O", &((tab_region+i)->(tab_departement+i)->taille_tab_ville));
		 printf("%s/", (tab_region+i)->tab_departement->tab_ville->nom_ville);
	}


	(*(tab_region + i))->((tab_departement + i)).nom;


	for ( i = 0; i < *taille_tab_etoile; i++)
	{
	ajouterRecensement(&((tab_region+i)->(tab_departement+i)->(tab_ville+i)->tab_recensement), "2005", 42, &((tab_region+i)->(tab_departement+i)->(tab_ville+i)->taille_tab_recensement));
	printf("%s: %s", (tab_region+i)->(tab_departement+i)->(tab_ville+i)->(tab_recensement+i)->annee,(tab_region+i)->(tab_departement+i)->(tab_ville+i)->(tab_recensement+i)->valeur_recen );
	}*/
	system("pause");

	//lectureFichierDepartement(&tab_region, &taille_tab_etoile);*/
	/*lectureFichierRecensements();*/

	return 0;
}