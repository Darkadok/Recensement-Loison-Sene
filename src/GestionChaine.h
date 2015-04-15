/*
Override
@author Alexandre Courcoul, Merlin Loison & Massamba Sène

2014/2015


GestionChaine.h
@author Massamba Sène

**/

#ifndef GESION_CHAINE_H
#define GESTION_CHAINE_H

#include <wchar.h>
#include <stdio.h>
#include <wctype.h>

int verificationSaisie(wchar_t saisie_utilisateur[], int code_menu);
void enleverAccent(wchar_t chaine[]);
void toMin(wchar_t chaine[], wchar_t chaine_tmp[]);
void  masquerMdp(wchar_t saisie_mdp[]);

#endif