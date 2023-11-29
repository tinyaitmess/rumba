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
    Pile *enAttente,*etatsFils;;
    Liste *vus, *chemin;
    retourPA r;
    Etat *e;
    initialiserPile(enAttente);
    ajouterTete(enAttente, debut);

    initialiserListe(vus);
    initialiserListe(chemin);
    bool trouve = false;
    while (!estVide(enAttente) && !trouve) {
        Etat *prochain = (Etat *)pop(enAttente);
        ajoutQueue(vus, prochain);
        if (compareEtats(fin, prochain)) {
            r.fin = prochain;
            r.trouve = true;
            return r;
        } else {
            etatsFils=filsEtat(prochain);
            
            while ((e=(Etat*)pop(etatsFils))!=NULL){
                if (!listeContient(vus, e))
                    ajouterTete(enAttente, e);
            }
        }
    }
}

int main() { return 0; }