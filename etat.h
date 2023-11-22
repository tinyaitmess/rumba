#ifndef __ETAT_H__
#define __ETAT_H__

#include <stdbool.h>
#include <stdio.h>
#include "stack.h"

typedef struct s_Etat Etat;

typedef Etat* ptrList;

Etat *createEtat();
Etat *pushEtat(int i,Stack *s,Etat *e);
bool compareEtats(Etat e1,Etat e2);
#endif