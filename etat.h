#ifndef __ETAT_H__
#define __ETAT_H__

#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

typedef struct s_Etat Etat;

typedef Etat* ptrEtat;

Etat *createEtat();
Etat *pushEtat(int i,Stack *s,Etat *e);
bool compareEtats(const Etat *e1,const Etat *e2);
Etat *bouger(const Etat *e,int i,int j);
void afficherEtat(const Etat *e);
#endif