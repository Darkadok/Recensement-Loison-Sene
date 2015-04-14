#include "MenuAdministration.h"


void menuAdministration(int choix_tmp, int connexion)
{
	int j = 0;
	do
	{
		int connexion = 0;
		wchar_t mdp[] = L"a123"; // Exemple de mot de passe pour accéder
		wchar_t saisie_mdp[50];   
			system("cls");
			printf("\nSaisisser votre mot de passe: (3 essais \n");
			masquerMdp(saisie_mdp);
			if (wcscmp(mdp, saisie_mdp) == 0) 
			{
				wchar_t saisie_utilisateur[50];
				connexion = 1;
				int code_menu = 3;
				do
				{
					system("cls");
					printf("=== MENU SECURISE ===\n");
					printf("\n Choisir une option :\n");
					printf("\n1 - Ajouter un recenssement ou une commune\n");
					printf("2 - Modifier les informations d une commune\n");
					printf("3 - Supprimer une commune ou un recenssement\n");
					printf("0 - Deconnexion\n");

					printf("\n Saisir votre choix : ");
					wscanf(L"%s", saisie_utilisateur);
					int code_menu = 3;
					switch (verificationSaisie(saisie_utilisateur, code_menu))
					{
					case 1:
						code_menu = 2;
						system("cls");
						printf("=== MENU AJOUTER Recenssement===\n");
						printf("\n1 - Ajouter un recenssement\n");
						printf("2 - Ajouter une commune\n");
						printf("0 - Retour\n");
						wscanf(L"%s", saisie_utilisateur);
						verificationSaisie(saisie_utilisateur, code_menu);
						saisie_utilisateur[1] = -1;
						break;
					case 2:
						system("cls");
						printf("=== MENU MODIFIER Commune ===\n");
						printf("\nSaisissez le nom de la commune a modifier\n");
						//wscanf(L"%s", saisie_utilisateur);
						system("pause");
						break;
					case 3:
						code_menu = 2;
						system("cls");
						printf("=== MENU SUPPRIMER Commune ou Recencement ===\n");
						printf("\n1 - Supprimer un recenssement\n");
						printf("2 - Supprimer une commune\n");
						printf("0 - Retour\n");
						wscanf(L"%s", saisie_utilisateur);
						verificationSaisie(saisie_utilisateur, code_menu);
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
	} while (j < 3);
}
 