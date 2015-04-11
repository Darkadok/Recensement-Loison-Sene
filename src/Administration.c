#include "Administration.h"

int menuAdministration(choix_tmp, connexion)
{
	do
	{
		int connexion = 0;
		int mdp = 1; //Remplacer avec wchar 
		int saisie_mdp = 1; //Remplacer avec wchar 
		int i = 0;
		int compteur = 0;
		/*wchar_t *saisie_mdp =NULL; *///Saisie de l'utilisateur stockée dans un tableau

		printf("=== Veuillez entrez votre mot de passe ===\n");
		system("pause");
		/*masquerMdp(saisie_mdp);*/

		if (saisie_mdp == mdp) //A modifier
		{
			printf("=== Espace Administrateur ===\n");
			connexion = 1;
			system("pause");
		}
		else
		{
			printf("=== Mot de passe incorrect ===\n");
		}

	} while (connexion == 0);
}
