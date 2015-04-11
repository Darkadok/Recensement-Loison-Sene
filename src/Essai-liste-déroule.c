#include <stdio.h>
#include <conio.h>


void menuDéroulant(choix_tmp)
{
	int i;
	int k1 = 0;
	int k2 = 0;

	for (i = 0; i; i++) // i devra etre égale au modluo du nombre de ligne par écran
	{
		while (!kbhit())
		{
			k1 = getch();
			if (k1 == 224)
			{
				k2 = getch();
				if (k2 == 72) //Flèche du haut 
				{

				}
				else if (k2 == 80) //Flèche du bas
				{

				}
			}
			else
			{
				return 0;
			}
		}

	}
}