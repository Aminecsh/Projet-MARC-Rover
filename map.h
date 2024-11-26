// map.h

#ifndef MAP_H
#define MAP_H

#include "loc.h"

#define COUT_NON_DEFINI 65535

/**
 * @brief Énumération pour les sols possibles de la carte
 */
typedef enum e_sol
{
    STATION_BASE,
    PLAINE,
    ERG,
    REG,
    CREVASSE
} t_sol;

/**
 * @brief Énumération pour les directions de pente
 */
typedef enum e_direction_pente
{
    PAS_DE_PENTE,
    DESCEND_NORD,
    DESCEND_EST,
    DESCEND_SUD,
    DESCEND_OUEST
} t_direction_pente;

/**
 * @brief Tableau des coûts pour les sols
 */
static const int _cout_sol[5] = {0, 1, 2, 4, 10000};

/**
 * @brief Structure pour la carte
 */
typedef struct s_map
{
    t_sol               **sol;
    t_direction_pente   **pentes;
    int                 **couts;
    int                 x_max;
    int                 y_max;
} t_map;

/**
 * @brief Fonction pour initialiser la carte à partir d'un fichier
 * @param nom_fichier : le nom du fichier
 * @return la carte
 */
t_map creerCarteDepuisFichier(char *nom_fichier);

/**
 * @brief Afficher la carte avec des caractères
 * @param carte : la carte à afficher
 */
void afficherCarte(t_map carte);

/**
 * @brief Fonction pour libérer la mémoire allouée pour la carte
 * @param carte : la carte à libérer
 */
void libererCarte(t_map carte);

/**
 * @brief Fonction pour obtenir la position de la station de base
 * @param carte : la carte
 * @return la position de la station de base
 */
t_position obtenirPositionBase(t_map carte);

#endif // MAP_H
