#ifndef LIST_H
#define LIST_H


#include "etat.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct N Noeud;

typedef struct l Liste;

Liste *initialiserListe();

void enleverFinListe(Liste *liste);
bool estVide(Liste *l);
void ajoutQueue(Liste *l, Etat *e);
bool listeContient(const Liste *liste, const ptrEtat etat);
void afficherListe(const Liste *liste);
void libererListe(Liste *liste);


#endif
