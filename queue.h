// queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include "loc.h"

/**
 * @brief Structure pour  la file de positions
 */
typedef struct s_file {
    t_position *valeurs; // Tableau de positions
    int taille;          // Taille maximale de la file
    int fin;             // Index du dernier élément
    int debut;           // Index du premier élément
} t_file;

/**
 * @brief Fonction pour créer une file
 * @param taille : la taille de la file
 * @return la file initialisée
 */
t_file creerFile(int taille);

/**
 * @brief Fonction pour enfiler une position dans la file
 * @param p_file : pointeur vers la file
 * @param pos : la position à enfiler
 */
void enfiler(t_file *p_file, t_position pos);

/**
 * @brief Fonction pour défiler une position de la file
 * @param p_file : pointeur vers la file
 * @return la position défilée
 */
t_position defiler(t_file *p_file);

/**
 * @brief Fonction pour libérer la file
 * @param p_file : pointeur vers la file
 */
void libererFile(t_file *p_file);

#endif // QUEUE_H
