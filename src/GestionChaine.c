/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015


GestionChaine.c.h
@author Massamba Sène

**/

#include "GestionChaine.h"

void  masquerMdp(wchar_t saisie_mdp[])
{

	int i = 0;
	int stop = 0;


	while (!stop)
	{

		saisie_mdp[i] = getch();
		if (saisie_mdp[i] == '\r')
		{
			stop = 1;
		}
		else
		{
			wprintf("*");
		}
		i++;


	}
	
	saisie_mdp[i] = '\0';
	
}


void toMin(wchar_t chaine_tmp[])// transforme les caractères majuscules de la chaine en minuscules
{
	int i;


	for (i = 0; i < wcslen(chaine_tmp); i++)
	{
		chaine_tmp[i] = towlower(chaine_tmp[i]);// --- ca plante !! ----
	}

}


/**** La vérification se fait avec une chaîne de caractère au cas où l'utilisateur tape plusieurs caractères
et également pour éviter les problèmes avec scanf et les char. *****/

int verificationSaisie(wchar_t saisie_utilisateur[], int code_menu)
{
	
	int choix_tmp = -1;


	if (wcslen(saisie_utilisateur) == 0 || wcslen(saisie_utilisateur) > 1)// on vérifie que la taille de la chaine est bien de 1
	{
		return -1;
	}


	else if (!iswdigit(saisie_utilisateur[0])) // on vérifie si la valeur saisie est bien un entier
	{
		return -1;
	}

	else
	{

		choix_tmp = _wtoi(&saisie_utilisateur[0]);

		if ((choix_tmp > code_menu) || (choix_tmp < 1))//l'entier doit être entre 1 et le code_menu qui correspond 
		{												//au nombre d'options maximums des différents menus
			return -1;
		}

		else
		{
			return choix_tmp;
		}
	}
}

void enleverAccent(wchar_t chaine[])
{
	for (int i = 0; i < wcslen(chaine); i++)
	{
		switch (chaine[i])
		{
		case L'à':
		case L'â':
		case L'Â':


			chaine[i] = L'a';

			break;

		case L'è':
		case L'é':
		case L'ê':
		case L'ë':
		case L'É':
		case L'È':

			chaine[i] = L'e';

			break;


		case L'î':
		case L'ï':

			chaine[i] = L'i';

			break;


		case L'ô':
		case L'Ô':
		case L'ö':
		case L'Ö':
			chaine[i] = L'o';

			break;


		case L'û':
		case L'ü':
		case L'Û':
		case L'Ü':
			chaine[i] = L'u';

			break;

		case L'ç':
			chaine[i] = L'c';

		default:    break;
		}

	}

}
