int menuConsulter(int choix_tmp)
{
	choix_tmp = 0;
	do
	{
		system("cls");
		printf("=== MENU DICTIONNAIRE ===\n");
		printf("\n \br Choisir une option :\n");
		printf("1 -Acceder aux informations sur la communes par nom \n");
		printf("2 -Acceder aux informations sur la commune par département \n");
		printf("0 - Revenir au menu précédent\n");
		scanf("%d", &choix_tmp);

		switch (choix_tmp)
		{
		case 1:
			system("cls");
			printf("Pour quelle commune voulez-vous des informations ? \n");
			system("pause");
			break;
		case 2:
			system("cls");
			printf(" Dans quel département se trouve la commune ? \n");
			system("pause");
			break;
		}

	} while (choix_tmp != 0);

	return choix_tmp;
}
