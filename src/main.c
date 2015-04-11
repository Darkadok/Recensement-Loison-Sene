
#include "Region.h"
#include "GestionFichier.h"

int main()
{

	int* taille_tab_etoile = NULL;
	Region* tab_region = NULL;
	tab_region = ajouterRegion(tab_region, "SilenceIsGolden", &taille_tab_etoile);

	lectureFichiers(&tab_region, &taille_tab_etoile);

	return 0;
}