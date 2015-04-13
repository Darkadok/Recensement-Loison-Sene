/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba S�ne

2014/2015


GestionChaine.h
@author Massamba S�ne

**/

#ifndef GESION_CHAINE_H
#define GESTION_CHAINE_H

#include <wchar.h>
#include <stdio.h>
#include <wctype.h>

void masquerMdp(wchar_t saisie_mdp[]);
void toMin(wchar_t chaine_tmp[]);
int verificationSaisie(wchar_t saisie_utilisateur[], int code_menu);
void enleverAccent(wchar_t chaine[]);


#endif
