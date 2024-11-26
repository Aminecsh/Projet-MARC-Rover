// performance.h

#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <time.h>

/**
 * @brief Structure pour chronométrer les tâches
 */
typedef struct s_chrono {
    clock_t debut;
    clock_t fin;
    double ecoule;
} t_chrono;

/**
 * @brief Fonction pour démarrer le chronomètre
 * @param chrono : pointeur vers le chronomètre
 */
void demarrerChrono(t_chrono *chrono);

/**
 * @brief Fonction pour arrêter le chronomètre
 * @param chrono : pointeur vers le chronomètre
 */
void arreterChrono(t_chrono *chrono);

/**
 * @brief Fonction pour afficher le temps écoulé
 * @param nom_tache : nom de la tâche
 * @param chrono : chronomètre avec le temps écoulé
 */
void afficherChrono(const char *nom_tache, t_chrono chrono);

#endif // PERFORMANCE_H
