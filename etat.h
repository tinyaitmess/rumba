#ifndef __ETAT_H__
#define __ETAT_H__

#include <stdbool.h>
#include <stdio.h>
#include "tige.h"

typedef struct s_Etat Etat;

typedef Etat* ptrEtat;

Etat *createEtat();
Etat *pushEtat(int i,Tige *s,Etat *e);
bool compareEtats(Etat *e1,Etat *e2);
#endif