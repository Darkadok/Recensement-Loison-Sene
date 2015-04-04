#include "Gestion.h"
#include "Menu.h"
void main()
{
	int* taille_tab_etoile = NULL;
	Region* tab_region = NULL;

	lectureFichierRecensements();
	lectureFichierDepartement(&tab_region, &taille_tab_etoile);	
	ajouterRegion(&tab_region, "SilenceIsGolden", &taille_tab_etoile);
}
