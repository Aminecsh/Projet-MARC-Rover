// tree.c

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#include "map.h"

/**
 * @brief Fonction pour créer un nouveau noeud d'arbre
 */
t_noeud_arbre* creerNoeudArbre(t_localisation loc, int cout, t_deplacement deplacement, t_noeud_arbre *parent) {
    t_noeud_arbre *noeud = (t_noeud_arbre*)malloc(sizeof(t_noeud_arbre));
    if (noeud == NULL) {
        fprintf(stderr, "Erreur : Échec de l'allocation mémoire pour le noeud d'arbre.\n");
        exit(1);
    }
    noeud->loc = loc;
    noeud->cout = cout;
    noeud->deplacement = deplacement;
    noeud->enfants = NULL;
    noeud->nb_enfants = 0;
    noeud->parent = parent;
    return noeud;
}

/**
 * @brief Fonction pour créer un arbre vide
 */
t_arbre* creerArbre() {
    t_arbre *arbre = (t_arbre*)malloc(sizeof(t_arbre));
    if (arbre == NULL) {
        fprintf(stderr, "Erreur : Échec de l'allocation mémoire pour l'arbre.\n");
        exit(1);
    }
    arbre->racine = NULL;
    return arbre;
}

/**
 * @brief Fonction pour ajouter un enfant à un noeud parent
 */
void ajouterEnfant(t_noeud_arbre *parent, t_noeud_arbre *enfant) {
    parent->enfants = (t_noeud_arbre**)realloc(parent->enfants,
                     sizeof(t_noeud_arbre*) * (parent->nb_enfants + 1));
    if (parent->enfants == NULL) {
        fprintf(stderr, "Erreur : Échec de l'allocation mémoire lors de l'ajout d'un enfant.\n");
        exit(1);
    }
    parent->enfants[parent->nb_enfants] = enfant;
    parent->nb_enfants++;
}

/**
 * @brief Fonction pour libérer la mémoire allouée pour l'arbre
 */
void libererArbre(t_noeud_arbre *noeud) {
    if (noeud == NULL) return;
    for (int i = 0; i < noeud->nb_enfants; i++) {
        libererArbre(noeud->enfants[i]);
    }
    free(noeud->enfants);
    free(noeud);
}

/**
 * @brief Fonction pour trouver la feuille de coût minimum dans l'arbre
 */
void trouverFeuilleCoutMin(t_noeud_arbre *noeud, int *cout_min, t_noeud_arbre **noeud_min) {
    if (noeud == NULL) return;
    if (noeud->nb_enfants == 0) {
        if (noeud->cout < *cout_min) {
            *cout_min = noeud->cout;
            *noeud_min = noeud;
        }
        return;
    }
    for (int i = 0; i < noeud->nb_enfants; i++) {
        trouverFeuilleCoutMin(noeud->enfants[i], cout_min, noeud_min);
    }
}

/**
 * @brief Fonction pour tracer le chemin d'une feuille à la racine
 */
void tracerChemin(t_noeud_arbre *noeud, t_pile *pile) {
    while (noeud->parent != NULL) {
        empiler(pile, noeud->deplacement);
        noeud = noeud->parent;
    }
}

/**
 * @brief Fonction pour construire l'arbre de mouvements récursivement
 */
void construireArbre(t_noeud_arbre *noeud, t_map carte, int profondeur, int profondeur_max) {
    if (profondeur >= profondeur_max) return;

    int total_deplacements = 7; // Nombre de déplacements possibles

    for (int i = 0; i < total_deplacements; i++) {
        t_deplacement deplacement_courant = (t_deplacement)i;
        t_localisation nouvelle_loc = mouvement(noeud->loc, deplacement_courant, carte);

        if (estLocalisationValide(nouvelle_loc.pos, carte.x_max, carte.y_max)) {
            if (carte.sol[nouvelle_loc.pos.y][nouvelle_loc.pos.x] == CREVASSE) {
                continue; // Ignorer les crevasses
            }

            int nouveau_cout = carte.couts[nouvelle_loc.pos.y][nouvelle_loc.pos.x];
            t_noeud_arbre *enfant = creerNoeudArbre(nouvelle_loc, nouveau_cout, deplacement_courant, noeud);
            ajouterEnfant(noeud, enfant);

            construireArbre(enfant, carte, profondeur + 1, profondeur_max);
        }
    }
}
