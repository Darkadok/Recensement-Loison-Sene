#include <stdio.h>
#include <conio.h>


void menuD�roulant(choix_tmp)
{
	int i;
	int k1 = 0;
	int k2 = 0;

	for (i = 0; i; i++) // i devra etre �gale au modluo du nombre de ligne par �cran
	{
		while (!kbhit())
		{
			k1 = getch();
			if (k1 == 224)
			{
				k2 = getch();
				if (k2 == 72) //Fl�che du haut 
				{

				}
				else if (k2 == 80) //Fl�che du bas
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