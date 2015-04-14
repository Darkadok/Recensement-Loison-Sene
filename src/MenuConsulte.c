#include "MenuConsulte.h"


void menuConsulter(int choix_tmp, wchar_t saisie_utilisateur[])
{
	int code_menu = 2;
	choix_tmp = 0;
	int i = 0;
	int num_dep_tmp;
	wchar_t chaine[50];
	wchar_t chaine_tmp[50];
	do
	{
		system("cls");
		printf("=== MENU DICTIONNAIRE ===\n");
		printf("\n \b Choisir une option :\n");
		printf("1 - Acceder aux informations sur la communes par nom \n");
		printf("2 - Acceder aux informations sur la commune par departement \n");
		printf("0 - Revenir au menu precedent\n");
		printf("\n Saisir votre choix : ");
		wscanf(L"%ls", saisie_utilisateur);
		

		switch (verificationSaisie(saisie_utilisateur, code_menu))
		{
		case 1:
			system("cls");
			printf("Pour quelle commune voulez-vous des informations ? \n");
			printf("Indiquer le nom : \n");
			wscanf(L"%ls", chaine);
			if (wcslen(chaine) > 4)
			{
				toMin(chaine,chaine_tmp);
				 //recherche par nom fonction recherche by nom commune
				printf("Recherche par nom commune \n");
			}
			system("pause");
			break;
		case 2:
			system("cls");
			printf(" Dans quel département se trouve la commune ? \n");
			printf("Inscriver le numéro sous la forme 01  ou le nom :");
			system("pause");
			do{
				if (wcslen(saisie_utilisateur) > 3)
				{
					wscanf(L"%ls", &saisie_utilisateur); //recherche par nom fonction recherche by nom département 

					i++;
				}
				else if (!iswdigit(saisie_utilisateur[1]))
				{
					num_dep_tmp = _wtoi(&saisie_utilisateur[0]); //recherche par numéro fonction recherche by numéro

					i++;
				}
			} while (i == 0);
			system("pause");
			break;

			case 0:
				break;
			default:
				break;
		}

	} while (verificationSaisie(saisie_utilisateur, code_menu) != 0);

			
}