#include "etat.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Structure représentant un élément de la liste
struct N {
    Etat *etat;
    struct N *suivant;
};

// Structure représentant la liste
struct l {
    Noeud *debut;
    int taille;
};

// Fonction pour initialiser une liste vide
Liste *initialiserListe() {
    Liste *liste = malloc(sizeof(Liste));
    liste->debut = NULL;
    liste->taille = 0;
    return liste;
}

// Fonction pour enlever un élément en fin de liste
void enleverFinListe(Liste *liste) {
    if (liste->debut == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        return;
    }

    // Si la liste a un seul élément, le supprimer
    if (liste->debut->suivant == NULL) {
        free(liste->debut);
        liste->debut = NULL;
        return;
    }

    // Trouver le nœud avant le dernier nœud
    Noeud *precedent = liste->debut;
    while (precedent->suivant->suivant != NULL) {
        precedent = precedent->suivant;
    }

    // Libérer le dernier nœud
    free(precedent->suivant);
    liste->taille--;
    // Mettre le pointeur suivant du nœud précédent à NULL pour indiquer la fin de la liste
    precedent->suivant = NULL;
}

bool estVide(Liste *l) { return l->taille == 0; }

void ajoutQueue(Liste *l, Etat *e) {
    Noeud *nouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouveauNoeud->etat = e;
    nouveauNoeud->suivant = NULL; // Assurez-vous de définir le suivant sur NULL

    if (l->debut == NULL) {
        // La liste est vide, donc le nouveau nœud est le début de la liste
        l->debut = nouveauNoeud;
    } else {
        // Trouver le dernier nœud dans la liste
        Noeud *dernier = l->debut;
        while (dernier->suivant != NULL) {
            dernier = dernier->suivant;
        }

        // Ajouter le nouveau nœud à la fin de la liste
        dernier->suivant = nouveauNoeud;
    }
    l->taille++;
}

bool listeContient(const Liste *liste, Etat *etat) {
    Noeud *courant = liste->debut;

    while (courant != NULL && !compareEtats(etat, courant->etat)) {
        courant = courant->suivant;
    }
    if (courant == NULL) {
        return false;
    }
    return true;
}

// Fonction pour afficher les éléments de la liste
void afficherListe(const Liste *liste) {
    Noeud *courant = liste->debut;
    while (courant != NULL) {
        // TO DO
    }
    printf("\n");
}

// Fonction pour libérer la mémoire allouée pour la liste
void libererListe(Liste *liste) {
    Noeud *courant = liste->debut;
    Noeud *temp;

    while (courant != NULL) {
        temp = courant;
        courant = courant->suivant;
        free(temp);
    }

    liste->debut = NULL;
}
