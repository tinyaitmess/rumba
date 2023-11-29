#ifndef LIST_H
#define LIST_H


#include "etat.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;

typedef struct l Liste;

void initialiserListe(Liste *liste);

void enleverFinListe(Liste *liste);
bool estVide(Liste *l);
void ajoutQueue(Liste *l, Etat *e);
bool listeContient(const Liste *liste, const ptrEtat etat);
void afficherListe(const Liste *liste);
void libererListe(Liste *liste);


#endif
