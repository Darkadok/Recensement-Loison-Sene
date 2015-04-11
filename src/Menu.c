#include "Menu.h"

int menu()
{
	int* taille_tab_etoile = NULL;
	Region* tab_region = NULL;
	lectureFichiers(&tab_region, &taille_tab_etoile);
	system("pause");
	int code_menu = 2;
	/*wchar_t* saisie_utilisateur = NULL; */    //La saisie de l'utilisateur va dans un tableau
	int choix = 0;
	int connexion = 0;
	int choix_tmp = 0;
	do
	{
		system("cls");
		printf("=== MENU PRINCIPAL ===\n");
		printf("\n \t Choisir une option :\n");
		printf("1 -Consulter des donnees \n");
		printf("2 - Espace administration\n");
		printf("0 - Quitter\n");

		printf("\n Saisir votre choix : ");
		/*saisie_utilisateur = malloc(sizeof(int)*)

		verificationSaisie(saisie_utilisateur, code_menu); */
		scanf_s("%d", &choix_tmp);       //test

		switch (choix_tmp)
		{
		case 0:
			detruireTabRegion(&tab_region, &taille_tab_etoile);
			break;
		case 1:
			system("cls");
			menuConsulter(choix_tmp);
			break;
		case 2:
			system("cls");
			menuAdministration(choix_tmp, connexion);
			break;
		default:
			break;
		}
	} while (choix_tmp != 0);

	return 0;
}