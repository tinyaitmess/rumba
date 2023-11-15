#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE_S_MAX 3

typedef struct filo {
    int size;
    int stack[SIZE_S_MAX];
} filo;

/*
constructeur
pop
top
push
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
*/

typedef struct etat {
    filo pic[4];
    int heuristique;
} etat;

bool testEtatBut(etat prochain) {}

bool profondeurDabord(etat debut, etat *fin) {
    fifo enAttente;
    add(enAttente, debut);
    list vus = malloc(sizeof(list));
    bool trouve = false;
    while (enAttente != NULL && !trouve) {
        etat prochain = pop(enAttente);
        add(vus, prochain);
        if (testEtatBut(prochain)) {
            *fin = prochain;
            return true;
        } else {
            for ()
        }
    }
}
