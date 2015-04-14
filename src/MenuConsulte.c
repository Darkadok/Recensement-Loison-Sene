#include "MenuConsulte.h"


void menuConsulter(int choix_tmp, wchar_t saisie_utilisateur[], Region** tab_region, int** taille_tab_region)
{
	int code_menu = 3;
	choix_tmp = 0;
	int i = 0;
	int num_dep_tmp;
	wchar_t chaine[50];
	wchar_t chaine_tmp[50];

	//pour cas 3 :
	Recensement* no_annee_tmp;
	Departement* tmp;
	Ville* ville_tmp;
	Recensement* recen_tmp;
	FILE* fichier;
	char continuer;

	do
	{
		system("cls");
		printf("=== MENU DICTIONNAIRE ===\n");
		printf("\n \b Choisir une option :\n");
		printf("1 - Acceder aux informations sur la communes par nom \n");
		printf("2 - Acceder aux informations sur la commune par departement \n");
		wprintf(L"3 - Afficher toutes les villes\n");
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
				toMin(chaine, chaine_tmp);

				printf("Recherche par nom commune encore non implemente ... \n");
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
					wscanf(L"%ls", &saisie_utilisateur);//recherche par nom fonction recherche by nom département 
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

		case 3:// ... par Merlin en reprenant le code d'ecritureRecensements code en vitesee => pas fini mais plus ou moins fonctionnelle
			fichier = _wfopen(L"../Import/recensements.csv", L"r");
			int nombre_recensements = nombrePointVirguleDansLigne(fichier) - 2;
			fclose(fichier);
			int nombre_ville_ecrit = 0;
			for (i = 0; i < **taille_tab_region; i++)//pour chaque reg
			{
				for (int j = 0; j < *((*tab_region) + i)->taille_tab_departement; j++)//pour chaque dep de cette region
				{
					tmp = (*tab_region + i)->tab_departement + j;
					for (int l = 0; l < *(tmp->taille_tab_ville); l++)//pour chaque ville
					{
						ville_tmp = tmp->tab_ville + l;

						if (wcscmp(tmp->numero_dep, L"2A") == 0 || wcscmp(tmp->numero_dep, L"2B") == 0)
						{
							wprintf(L"\n%ls;%ls;%ls;", ville_tmp->dep_com, tmp->numero_dep, ville_tmp->nom_ville);
							nombre_ville_ecrit++;
						}
						else
						{
							wprintf(L"\n%ls;%d;%ls;", ville_tmp->dep_com, _wtoi(tmp->numero_dep), ville_tmp->nom_ville);
							nombre_ville_ecrit++;
						}

						for (int k = 0; k < nombre_recensements - 1; k++)//pour chaque recensement
						{
							recen_tmp = ville_tmp->tab_recensement + k;
							wprintf(L"%d;", recen_tmp->valeur_recen);
						}
						recen_tmp = ville_tmp->tab_recensement + (nombre_recensements - 1);
						wprintf(L"%d", recen_tmp->valeur_recen);

						if (nombre_ville_ecrit % 10 == 0)
						{
							wprintf(L"\n\n ============== \nPage %d . Continuer ? (y/n)", nombre_ville_ecrit / 10);
							scanf("%c", &continuer);
							if (continuer != 'y')
							{
								break;
							}
						}
					}
				}
			}
			system("pause");
			break;


		case 0:
			break;
		default:
			break;
		}

	} while (verificationSaisie(saisie_utilisateur, code_menu) != 0);


}