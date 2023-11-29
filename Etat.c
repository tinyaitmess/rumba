#include "etat.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "tige.h"
struct s_Etat {
    Tige **pic;
    int heuristique;
};

Etat *createEtat() {
    Etat *e = malloc(sizeof(Etat));
    e->pic = malloc(sizeof(ptrTige) * 4);
    for (int i = 0; i < 4; i++) {
        e->pic[i] = createTige();
    }
    e->heuristique = 0;
    return e;
}

Etat *pushEtat(int i, Tige *s, Etat *e) {
    e->pic[i] = s;
    return e;
}

bool compareEtats(Etat *e1, Etat *e2) {
    for (int i = 0; i < 4; i++) {
        if (!compareTiges(e1->pic[i], e2->pic[i]))
            return false;
    }
    return true;
}

Etat *bouger(Etat *e, int i, int j) {
    assert(0 <= i && i < 4 && 0 <= j && j < 4 && i != j);
    assert(!tigeEmpty(e->pic[i]));
    assert(!tigeOverflow(e->pic[j]));
    Etat *res = createEtat();
    memcpy(&res, &e, sizeof(Etat *));
    int top = tigeTop(res->pic[i]);
    tigePop(res->pic[i]);
    tigePush(res->pic[j], top);
    return res;
}

void afficherEtat(const Etat *e) {
    tigeFourDump(e->pic[0], e->pic[1], e->pic[2], e->pic[3]);
    for (int i = 1; i < 4; i++) {
        printf("|p%d ", i);
    }
    printf("|p4 |\n\n");
}