// moves.h

#ifndef MOVES_H
#define MOVES_H

#include "loc.h"
#include "map.h" // Inclure les définitions de la carte

/**
 * @brief Tableau de chaînes pour les déplacements possibles du robot
 */
static const char *_deplacements[] = {
    "A 10m",   // Avancer de 10 mètres
    "A 20m",   // Avancer de 20 mètres
    "A 30m",   // Avancer de 30 mètres
    "R 10m",   // Reculer de 10 mètres
    "T gauche",  // Tourner à gauche (+90 degrés)
    "T droite", // Tourner à droite (-90 degrés)
    "Demi-tour"   // Tourner de 180 degrés
};

/**
 * @brief Énumération pour les déplacements possibles du robot
 */
typedef enum e_deplacement {
    AVANCER_10,    // Avancer de 10 mètres
    AVANCER_20,    // Avancer de 20 mètres
    AVANCER_30,    // Avancer de 30 mètres
    RECULER_10,    // Reculer de 10 mètres
    TOURNER_GAUCHE,  // Tourner à gauche
    TOURNER_DROITE, // Tourner à droite
    DEMI_TOUR   // Demi-tour
} t_deplacement;

/**
 * @brief Fonction pour obtenir un t_deplacement en chaîne
 * @param deplacement : le déplacement à convertir
 * @return la chaîne correspondant au déplacement
 */
const char *obtenirDeplacementEnChaine(t_deplacement deplacement);

/**
 * @brief Fonction pour effectuer un déplacement et obtenir la nouvelle localisation
 * @param loc : localisation actuelle
 * @param deplacement : déplacement à effectuer
 * @param carte : la carte pour les informations de terrain et de pente
 * @return nouvelle localisation après le déplacement
 */
t_localisation mouvement(t_localisation loc, t_deplacement deplacement, t_map carte);

/**
 * @brief Fonction pour mettre à jour la localisation en place
 * @param p_loc : pointeur vers la localisation actuelle
 * @param deplacement : déplacement à effectuer
 * @param carte : la carte
 */
void mettreAJourLocalisation(t_localisation *p_loc, t_deplacement deplacement, t_map carte);

#endif // MOVES_H
