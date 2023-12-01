#include "etat.h"
#include "list.h"
#include "pile.h"

#include "tige.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Liste *chemin;
    bool trouve;
} retourPA;

typedef struct nvN_fE {
    Etat *filsEtat;
    int nv;
} nv_filEtat;

retourPA profondeurDabord(Etat *debut, Etat *fin) {
    Pile *enAttente, *etatsFils;
    Liste *vus, *chemin;
    retourPA r;
    Etat *e;
    int nv = 1;
    etatsFils = initialiserPile();
    enAttente = initialiserPile();
    ajouterTete(enAttente, debut);

    vus = initialiserListe();
    chemin = initialiserListe();
    bool trouve = false;

    while (!estVidePile(enAttente) && !trouve) {
        Etat *prochain = (Etat *)pop(enAttente);
        if (nv == nv_noeud(prochain))
            enleverFinListe(chemin);
        else {
            nv = nv_noeud(prochain);
            ajoutQueue(chemin, prochain);
        }
        ajoutQueue(vus, prochain);
        if (compareEtats(fin, prochain)) {
            r.chemin = chemin;
            r.trouve = true;
            return r;
        } else {
            etatsFils = filsEtat(prochain, nv + 1);
            while ((e = (Etat *)pop(etatsFils)) != NULL) {
                if (!listeContient(vus, e))
                    ajouterTete(enAttente, e);
            }
        }
    }
    return r;
}

int main() { return 0; }