#include "pile.h"
#include "etat.h"
#include "tige.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Structure représentant un élément de la liste
typedef struct Noeud {
    void *element;
    struct Noeud *suivant;
} Noeud;

// Structure représentant la liste
typedef struct l {
    Noeud *debut;
    int taille;
} Pile;

// Fonction pour initialiser une liste vide
void initialiserPile(Pile *pile) {
    pile->debut = NULL;
    pile->taille = 0;
}

// Fonction pour ajouter un élément au début de la liste
void ajoutTete(Pile *pile, void *valeur) {
    // Créer un nouveau nœud
    Noeud *nouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Affecter la valeur au nouveau nœud
    nouveauNoeud->element = valeur;

    // Lier le nouveau nœud au début de la liste
    nouveauNoeud->suivant = pile->debut;
    pile->debut = nouveauNoeud;
    pile->taille++;
}

bool estVide(Pile *l) { return l->taille == 0; }

void **pop(Pile *liste) {
    void *tete;
    if (liste->debut == NULL) {
        return NULL;
    }
    Noeud *precedent = liste->debut;
    tete = liste->debut->element;
    liste->debut = liste->debut->suivant;
    free(precedent);
    liste->taille--;
    return tete;
}

// Fonction pour afficher les éléments de la liste
void afficherPile(const Pile *liste) {
    Noeud *courant = liste->debut;
    while (courant != NULL) {
        // TO DO
    }
    printf("\n");
}

// Fonction pour libérer la mémoire allouée pour la liste
void libererListe(Pile *liste) {
    Noeud *courant = liste->debut;
    Noeud *temp;

    while (courant != NULL) {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    }

    liste->debut = NULL;
}

Pile *filsEtat(Etat *e) {
    Pile *l;
    Etat *f;
    initialiserPile(l);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                f = bouger(e, i, j);
                ajoutTete(l, f);
            }
        }
    }
    return l;
}
