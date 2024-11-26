// stack.c

#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/**
 * @brief Fonction pour créer une pile
 * @param taille : la taille de la pile
 * @return la pile initialisée
 */
t_pile creerPile(int taille) {
    assert(taille > 0);
    t_pile pile;
    pile.taille = taille;
    pile.nbElements = 0;
    pile.valeurs = (int *)malloc(taille * sizeof(int));
    return pile;
}

/**
 * @brief Fonction pour empiler une valeur sur la pile
 * @param p_pile : pointeur vers la pile
 * @param valeur : la valeur à empiler
 */
void empiler(t_pile *p_pile, int valeur) {
    assert(p_pile->nbElements < p_pile->taille);
    p_pile->valeurs[p_pile->nbElements] = valeur;
    p_pile->nbElements++;
}

/**
 * @brief Fonction pour dépiler une valeur de la pile
 * @param p_pile : pointeur vers la pile
 * @return la valeur dépilée
 */
int depiler(t_pile *p_pile) {
    assert(p_pile->nbElements > 0);
    p_pile->nbElements--;
    return p_pile->valeurs[p_pile->nbElements];
}

/**
 * @brief Fonction pour libérer la pile
 * @param p_pile : pointeur vers la pile
 */
void libererPile(t_pile *p_pile) {
    free(p_pile->valeurs);
    p_pile->valeurs = NULL;
    p_pile->taille = 0;
    p_pile->nbElements = 0;
}
