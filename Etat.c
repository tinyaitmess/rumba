#include "etat.h"
#include <assert.h>
#include <stdlib.h>

#include "stack.h"
struct s_Etat {
    Stack **pic;
    int heuristique;
};

Etat *createEtat() {
    Etat *e = malloc(sizeof(Etat));
    return e;
}

Etat *pushEtat(int i, Stack *s, Etat *e) {
    e->pic[i] = s;
    return e;
}

bool compareEtats(Etat e1, Etat e2) {
    for (int i = 0; i < 4; i++) {
        if (!compareStack(e1.pic[i], e2.pic[i]))
            return false;
    }
    return true;
}