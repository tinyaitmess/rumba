#include "etat.h"

#ifndef PILE_H
#define PILE_H



#include <stdio.h>
#include <stdlib.h>

typedef struct N Noeud_pile;

typedef struct l Pile;

Pile *initialiserPile();
void ajouterTete(Pile *liste, void* valeur);

void* *pop(Pile *liste);

void afficherPile(const Pile *liste);
bool estVidePile(Pile *l);
void libererPile(Pile *liste);
Pile *filsEtat(Etat *e,int nv);


#endif
