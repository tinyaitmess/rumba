#include "etat.h"
#include "list.h"
#include "pile.h"

#include "tige.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Etat *fin;
    bool trouve;
} retourPA;

retourPA profondeurDabord(Etat *debut, Etat *fin) {
    Pile *enAttente;
    Liste *vus, *chemin;
    retourPA r;
    initialiserPile(enAttente);
    ajouterTete(enAttente, debut);

    initialiserListe(vus);
    initialiserListe(chemin);
    bool trouve = false;
    while (!estVide(enAttente) && !trouve) {
        Etat *prochain = pop(enAttente);
        ajoutQueue(vus, prochain);
        if (testEtatBut(prochain)) {
            r.fin = prochain;
            r.trouve = true;
            return r;
        } else {
            for ()
        }
    }
}

int main() { return 0; }