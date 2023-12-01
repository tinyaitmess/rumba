#include "etat.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "tige.h"
struct s_Etat {
    Tige **pic;
    int heuristique;
    int mouvement[2];
    int nv_noeud;
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

Tige *tige_num(Etat *e, int i) { return e->pic[i]; }

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

int nv_noeud(Etat *e) { return e->nv_noeud; }
Etat *bouger(Etat *e, int i, int j, int nv) {
    assert(0 <= i && i < 4 && 0 <= j && j < 4 && i != j);
    assert(!tigeEmpty(e->pic[i]));
    assert(!tigeOverflow(e->pic[j]));
    Etat *res = createEtat();
    memcpy(&res, &e, sizeof(Etat *));
    res->nv_noeud = nv;
    int top = tigeTop(res->pic[i]);
    tigePop(res->pic[i]);
    tigePush(res->pic[j], top);
    res->mouvement[0] = i;
    res->mouvement[1] = j;
    return res;
}

int *chemin(Etat *e) { return e->mouvement; }
void afficherEtat(const Etat *e) {
    tigeFourDump(e->pic[0], e->pic[1], e->pic[2], e->pic[3]);
    for (int i = 1; i < 4; i++) {
        printf("|p%d ", i);
    }
    printf("|p4 |\n\n");
}