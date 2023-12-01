#include "pile.h"
#include "etat.h"
#include "tige.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure représentant un élément de la liste
struct N {
    void *element;
    struct N *suivant;
};

// Structure représentant la liste
struct l {
    Noeud_pile *debut;
    int taille;
};

// Fonction pour initialiser une liste vide
Pile *initialiserPile() {
    Pile *pile = malloc(sizeof(Pile));
    pile->debut = NULL;
    pile->taille = 0;
    return pile;
}

// Fonction pour ajouter un élément au début de la liste
void ajouterTete(Pile *pile, void *valeur) {
    // Créer un nouveau nœud
    Noeud_pile *nouveauNoeud_pile = (Noeud_pile *)malloc(sizeof(Noeud_pile));
    if (nouveauNoeud_pile == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Affecter la valeur au nouveau nœud
    nouveauNoeud_pile->element = valeur;

    // Lier le nouveau nœud au début de la liste
    nouveauNoeud_pile->suivant = pile->debut;
    pile->debut = nouveauNoeud_pile;
    pile->taille++;
}

bool estVidePile(Pile *l) { return l->taille == 0; }

void **pop(Pile *liste) {
    void *tete;
    if (liste->debut == NULL) {
        return NULL;
    }
    Noeud_pile *precedent = liste->debut;
    tete = liste->debut->element;
    liste->debut = liste->debut->suivant;
    free(precedent);
    liste->taille--;
    return tete;
}

// Fonction pour afficher les éléments de la liste
void afficherPile(const Pile *liste) {
    Noeud_pile *courant = liste->debut;
    while (courant != NULL) {
        // TO DO
    }
    printf("\n");
}

// Fonction pour libérer la mémoire allouée pour la liste
void libererPile(Pile *liste) {
    Noeud_pile *courant = liste->debut;
    Noeud_pile *temp;

    while (courant != NULL) {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    }

    liste->debut = NULL;
}

Pile *filsEtat(Etat *e, int nv) {
    Pile *l;
    Etat *f;

    l = initialiserPile();
    for (int i = 0; i < 4; i++) {
        if (!tigeEmpty(tige_num(e, i))) {
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    if (!tigeOverflow(tige_num(e, j))) {
                        f = bouger(e, i, j, nv);
                        ajouterTete(l, f);
                    }
                }
            }
        }
    }
    return l;
}
