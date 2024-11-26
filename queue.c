// queue.c

#include <stdlib.h>
#include <assert.h>
#include "queue.h"

/**
 * @brief Fonction pour créer une file
 * @param taille : la taille de la file
 * @return la file initialisée
 */
t_file creerFile(int taille) {
    assert(taille > 0);
    t_file file;
    file.taille = taille;
    file.debut = 0;
    file.fin = 0;
    file.valeurs = (t_position *)malloc(taille * sizeof(t_position));
    return file;
}

/**
 * @brief Fonction pour enfiler une valeur dans la file
 * @param p_file : pointeur vers la file
 * @param pos : la position à enfiler
 */
void enfiler(t_file *p_file, t_position pos) {
    assert((p_file->fin - p_file->debut) < p_file->taille);
    p_file->valeurs[p_file->fin % p_file->taille] = pos;
    p_file->fin++;
}

/**
 * @brief Fonction pour défiler une valeur de la file
 * @param p_file : pointeur vers la file
 * @return la position défilée
 */
t_position defiler(t_file *p_file) {
    assert(p_file->fin != p_file->debut);
    t_position pos = p_file->valeurs[p_file->debut % p_file->taille];
    p_file->debut++;
    return pos;
}

/**
 * @brief Fonction pour libérer la file
 * @param p_file : pointeur vers la file
 */
void libererFile(t_file *p_file) {
    free(p_file->valeurs);
    p_file->valeurs = NULL;
    p_file->taille = 0;
    p_file->debut = 0;
    p_file->fin = 0;
}
