#include "etat.h"
#include <stdio.h>
#include <stdlib.h>

// Structure représentant un élément de la liste
typedef struct Noeud {
    Etat *etat;
    struct Noeud *suivant;
} Noeud;

// Structure représentant la liste
typedef struct {
    Noeud *debut;
} Liste;

// Fonction pour initialiser une liste vide
void initialiserListe(Liste *liste) { liste->debut = NULL; }

// Fonction pour ajouter un élément au début de la liste
void ajoutTete(Liste *liste, ptrEtat valeur) {
    // Créer un nouveau nœud
    Noeud *nouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Affecter la valeur au nouveau nœud
    nouveauNoeud->etat = valeur;

    // Lier le nouveau nœud au début de la liste
    nouveauNoeud->suivant = liste->debut;
    liste->debut = nouveauNoeud;
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

    // Mettre le pointeur suivant du nœud précédent à NULL pour indiquer la fin de la liste
    precedent->suivant = NULL;
}

Etat *pop(Liste *liste) {
    Etat *tete;
    if (liste->debut == NULL) {
        fprintf(stderr, "La liste est vide.\n");
        exit(EXIT_FAILURE);
    }
    Noeud *precedent = liste->debut;
    tete = liste->debut->etat;
    liste->debut = liste->debut->suivant;
    free(precedent);
    return tete;
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
