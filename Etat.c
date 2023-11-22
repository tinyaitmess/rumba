#include "etat.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
struct s_Etat {
    Stack **pic;
    int heuristique;
};

Etat *createEtat() {
    Etat *e = malloc(sizeof(Etat));
    e->pic = malloc(sizeof(Stack *) * 4);
    for (int i = 0; i < 4; i++) {
        e->pic[i] = createStack();
    }
    e->heuristique = 0;
    return e;
}

Etat *pushEtat(int i, Stack *s, Etat *e) {
    e->pic[i] = s;
    return e;
}

bool compareEtats(Etat *e1, Etat *e2) {
    for (int i = 0; i < 4; i++) {
        if (!compareStack(e1->pic[i], e2->pic[i]))
            return false;
    }
    return true;
}

Etat *bouger(const Etat e, int i, int j) {
    assert(0 <= i && i < 4 && 0 <= j && j < 4 && i != j);
    assert(!stackEmpty(e.pic[i]));
    assert(!stackOverflow(e.pic[j]));
    Etat *res = createEtat();
    memcpy(&res, &e, sizeof(Etat *));
    int *top = stackTop(res->pic[i]);
    stackPop(res->pic[i]);
    stackPush(res->pic[j], top);
    return res;
}