#include "Consulter.h"
#include"GestionChaine.h" 

int menuConsulter(int choix_tmp, wchar_t saisie_utilisateur[])
{
	int code_menu = 2;
	choix_tmp = 0;
	int i = 0;
	int num_dep_tmp;
	do
	{
		system("cls");
		printf("=== MENU DICTIONNAIRE ===\n");
		printf("\n \br Choisir une option :\n");
		printf("1 -Acceder aux informations sur la communes par nom \n");
		printf("2 -Acceder aux informations sur la commune par département \n");
		printf("0 - Revenir au menu précédent\n");
		wscanf(L"%ls", &saisie_utilisateur);
		verificationSaisie(saisie_utilisateur, code_menu);

		switch (choix_tmp)
		{
		case 1:
			system("cls");
			printf("Pour quelle commune voulez-vous des informations ? \n");
			printf("Indiquer le nom : ");
			system("pause");
			if (wcslen(saisie_utilisateur) > 4)
			{
				wscanf(L"%ls", &saisie_utilisateur); //recherche par nom fonction recherche by nom commune
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
				else if (!iswdigit(saisie_utilisateur[0]))
				{ 
					num_dep_tmp = _wtoi(&saisie_utilisateur[0]); //recherche par numéro fonction recherche by numéro
					i++;
				}
			} while (i == 0);
			system("pause");
			break;
		}

	} while (choix_tmp != 0);

	return choix_tmp;
}
