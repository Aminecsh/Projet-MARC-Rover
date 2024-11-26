// stack.h

#ifndef STACK_H
#define STACK_H

/**
 * @brief Structure po ur la pile des entiers
 */
typedef struct s_pile {
    int *valeurs;      // Tableau de valeurs
    int taille;        // Taille maximum de la pile
    int nbElements;    // Nombre d'éléments dans la pile
} t_pile;

/**
 * @brief Fonction pour créer une pile
 * @param taille : la taille de la pile
 * @return la pile initialisée
 */
t_pile creerPile(int taille);

/**
 * @brief Fonction pour empiler une valeur sur la pile
 * @param p_pile : pointeur vers la pile
 * @param valeur : la valeur à empiler
 */
void empiler(t_pile *p_pile, int valeur);

/**
 * @brief Fonction pour dépiler une valeur de la pile
 * @param p_pile : pointeur vers la pile
 * @return la valeur dépilée
 */
int depiler(t_pile *p_pile);

/**
 * @brief Fonction pour libérer la pile
 * @param p_pile : pointeur vers la pile
 */
void libererPile(t_pile *p_pile);

#endif // STACK_H
