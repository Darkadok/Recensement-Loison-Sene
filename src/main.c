
#include "Region.h"
#include "GestionFichier.h"

int main()
{
	
	wchar_t test[3] = L"01";
	printf("%d", _wtoi(test));


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

	lectureFichiers(&tab_region, &taille_tab_etoile);

	return 0;
}