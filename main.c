#include "etat.h"
#include "list.h"

#include "stack.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*typedef struct filo {
    int size;
    int stack[SIZE_S_MAX];
} Stack;
*/
/*
constructeur
-pop
-top
-push
bouger(filo a, filo b){
    push(top(a),b);
    pop(a);
}

*/

/*
implementer liste avec sentinelle qui prendre des etats
*/

/*
fonction de comparaison entre états
 -comparaison stack
*/
/**
typedef struct etat {
    Stack *pic;
    int heuristique;
} etat;

bool testEtatBut(etat prochain) {}
*/
bool profondeurDabord(Etat *debut, Etat *fin) {
    Liste *enAttente;
    initialiserListe(enAttente);
    ajoutTete(enAttente, debut);
    Liste *vus;
    initialiserListe(vus);
    bool trouve = false;
    while (enAttente != NULL && !trouve) {
        Etat *prochain = pop(enAttente);
        add(vus, prochain);
        if (testEtatBut(prochain)) {
            *fin = prochain;
            return true;
        } else {
            for ()
        }
    }
}

int main() { return 0; }