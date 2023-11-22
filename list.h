#ifndef LIST_H
#define LIST_H


#include "etat.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;

typedef struct l Liste;

void initialiserListe(Liste *liste);
void ajouterDebutListe(Liste *liste, ptrEtat valeur);
void enleverFinListe(Liste *liste);
Etat *pop(Liste *liste);
bool listeContient(const Liste *liste, const ptrEtat etat);
void afficherListe(const Liste *liste);
void libererListe(Liste *liste);
List *filsEtat(const Etat *e);


#endif
