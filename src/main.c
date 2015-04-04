
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

	Departement* tab_departement_tmp;


	//lectureFichierDepartement(&tab_region, &taille_tab_etoile);*/
	lectureFichierRecensements();

	return 0;
}