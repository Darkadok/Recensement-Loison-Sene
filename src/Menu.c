#include"Menu.h"

int main(int argc, char *argv[])
{
	int choix = 0;
	do
	{
		system("cls");
		printf("=== MENU PRINCIPAL ===\n");
		printf("\n Choisir une option :\n");
		printf("1 -Consulter des données \n");
		printf("2 - Espace administration\n");
		printf("0 - Quitter\n");
		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
			menuConsulter(choix); /*  ajouter les variables pour affichage */
			break;
		case 2:
			menuAdmin(choix);
			break;
		default:
			/*Créer la fonction de mauvaise saisie*/
			break;
		}
	} while (choix != 0);

	return 0;
}


int menuConsulter(int choix) /*  ajouter les variables pour affichage */
{

	int choix = 0;
	do
	{
		system("cls");
		printf("=== MENU DICTIONNAIRE ===\n");
		printf("\n Choisir une option :\n");
		printf("1 -Accèder aux informations sur la communes par nom");
		printf("2 -Accèder aux informations sur la commune par département\n");
		printf("0 - Revenir au menu précédent\n");
		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
			menuNom(choix); /*  ajouter les variables pour affichage */
			break;

		case 2:
			break;
		case 3:
			break;
		}

	} while (choix != 0);

	return 0;
}




void menuAdmin(int choix)
{

	int pass = 0;
	int saisie_utilisateur = 0;

	do
	{
		printf("Accès sécurisé mot de passe nécessaire\n");
		printf("Saisir le mot de passe administration");
		scanf("%d", &saisie_utilisateur);

	} while (pass != saisie_utilisateur);


	int choix = 0;

	do
	{
		system("cls");
		printf("=== MENU ADMINISTRATION ===\n");
		printf("\n Choisir une option :\n");
		printf("1 -Ajouter une commune ou un rescencement");
		printf("2 -Modifier des données\n");
		printf("3 -Supprimer des données \n");
		printf("0 -Menu principal \n");
		scanf("%d", &choix);

		switch (choix)
		{
		case 1:
			menuAjouter(choix); /*  ajouter les variables pour affichage */
			break;
		case 2:
			menuModifier(choix); /*  ajouter les variables pour affichage */
			break;
		case 3:
			menuSupprimer(choix); /*  ajouter les variables pour affichage */
			break;
		}

	} while (choix != 0);

	return 0;
}

void menuAjouter(int choix) /*  ajouter les variables pour affichage */
{
	int choix2 = 0;

	do
	{
		system("cls");
		printf("=== MENU AJOUT===\n");
		printf("\n Choisir une option :\n");
		printf("1 -Ajouter une region\n");
		printf("2 -Ajouter un departement\n");
		printf("3 -Ajouter une commune");
		printf("4 -Ajouter un rescencement\n");
		printf("0 -Menu précédent\n");
		scanf("%d", &choix);

		switch (choix2)
		{
		case 1:
			menuRegion(choix2); /* ajouter les variables pour affichage*/
			break;
		case 2:
			menuDepartement(choix2); /* ajouter les variables pour affichage*/
			break;
		case 3:
			menuCommune(choix2); /* ajouter les variables pour affichage*/
			break;
		case 4:
			menuRescencement(choix2); /* ajouter les variables pour affichage*/
			break;
		}

	} while (choix != 0);

	return 0;
}

void menuModifier(choix)
{




}