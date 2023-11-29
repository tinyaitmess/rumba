#ifndef PILE_H
#define PILE_H



#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;

typedef struct l Pile;

void initialiserPile(Pile *liste);
void ajouterTete(Pile *liste, void* valeur);

void* *pop(Pile *liste);

void afficherPile(const Pile *liste);
void libererPile(Pile *liste);


#endif
