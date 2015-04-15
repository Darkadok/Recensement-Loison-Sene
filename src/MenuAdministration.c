#include "MenuAdministration.h"



void menuAdministration(int choix_tmp, int connexion)
{
	int j = 0;
	do
	{
		int connexion = 0;
		wchar_t mdp[] = L"a123"; // Exemple de mot de passe
		wchar_t saisie_mdp[50];
		system("cls");
		printf("\nSaisissez votre mot de passe: (3 essais) \n");
		masquerMdp(saisie_mdp);
		if (wcscmp(mdp, saisie_mdp) == 0)
		{
			wchar_t saisie_utilisateur[50];
			connexion = 1;
			int code_menu = 4;
			do
			{
				system("cls");
				printf("=== MENU ADMINISTRATEUR ===\n");
				printf("\n Choisir une option :\n");
				printf("\n1 - Ajouter un recensement ou une commune\n");
				printf("2 - Modifier les informations d'une commune\n");
				printf("3 - Supprimer une commune ou un recensement\n");
				printf("4 - Afficher toutes les communes\n");
				printf("0 - Deconnexion\n");

				printf("\n Saisir votre choix : ");
				wscanf(L"%ls", saisie_utilisateur);
				int code_menu = 3;
				switch (verificationSaisie(saisie_utilisateur, 5))
				{
				case 1:
					code_menu = 2;
					system("cls");
					printf("=== MENU AJOUTER Recensement===\n");
					printf("\n1 - Ajouter un recensement\n");
					printf("2 - Ajouter une commune\n");
					printf("0 - Retour\n");
					wscanf(L"%s", saisie_utilisateur);
					verificationSaisie(saisie_utilisateur, 3);
					saisie_utilisateur[1] = -1;
					break;
				case 2:
					system("cls");
					printf("=== MENU MODIFIER Commune ===\n");
					wprintf(L"\nSaisissez le nom de la commune %lc modifier\n", 133);
					//wscanf(L"%s", saisie_utilisateur);
					system("pause");
					break;
				case 3:
					code_menu = 2;
					system("cls");
					printf("=== MENU SUPPRIMER Commune ou Recencement ===\n");
					printf("\n1 - Supprimer un recensement\n");
					printf("2 - Supprimer une commune\n");
					printf("0 - Retour\n");
					wscanf(L"%s", saisie_utilisateur);
					verificationSaisie(saisie_utilisateur, 3);
					saisie_utilisateur[1] = -1;
					break;
				case 4:
					system("cls");
					printf("=== MENU COMMUNE ===\n");
					printf("0 - Retour\n");
					wscanf(L"%s", saisie_utilisateur);
					verificationSaisie(saisie_utilisateur, 1);
					saisie_utilisateur[1] = -1;
					break;
				default:
					break;
				}
			} while (verificationSaisie(saisie_utilisateur, code_menu) != 0);

			connexion = 0;
			j = 3;
		}
		else
		{
			j++;
		}
	} while (j < 4);
}
