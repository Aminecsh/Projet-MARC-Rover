// test_tree.c

#include <stdio.h>
#include <assert.h>
#include "tree.h"
#include "map.h"
#include "stack.h"

void tester_creerNoeudArbre() {
    t_localisation loc = loc_init(0, 0, NORD);
    t_noeud_arbre *noeud = creerNoeudArbre(loc, 0, -1, NULL);
    assert(noeud != NULL);
    assert(noeud->loc.pos.x == 0 && noeud->loc.pos.y == 0);
    libererArbre(noeud);
}

void tester_ajouterEnfant() {
    t_localisation loc = loc_init(0, 0, NORD);
    t_noeud_arbre *parent = creerNoeudArbre(loc, 0, -1, NULL);
    t_noeud_arbre *enfant = creerNoeudArbre(loc, 1, AVANCER_10, parent);
    ajouterEnfant(parent, enfant);
    assert(parent->nb_enfants == 1);
    assert(parent->enfants[0] == enfant);
    libererArbre(parent);
}

int main() {
    tester_creerNoeudArbre();
    tester_ajouterEnfant();
    printf("Tous les tests d'arbre ont réussi.\n");
    return 0;
}
