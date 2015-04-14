#ifndef GESION_SAISIE_H
#define GESTION_SAISIE_H

#include <wchar.h>
#include <stdio.h>
#include <wctype.h>

int verificationSaisie(wchar_t saisie_utilisateur[], int code_menu);
void enleverAccent(wchar_t chaine[]);

#endif