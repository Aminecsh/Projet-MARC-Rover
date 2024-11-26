#include "loc.h"
#include <stdio.h> // Pour les chaînes de caractères dans obtenirOrientationEnChaine

/**
 * @brief Initialiser une localisation avec position et orientation
 * @param x : coordonnée x
 * @param y : coordonnée y
 * @param ori : orientation (NORD, EST, SUD, OUEST)
 * @return la localisation initialisée
 */
t_localisation loc_init(int x, int y, t_orientation ori) {
    t_localisation loc;
    loc.pos.x = x;
    loc.pos.y = y;
    loc.ori = ori;
    return loc;
}

/**
 * @brief Vérifier si une localisation est valide sur une carte
 * @param pos : position à vérifier
 * @param x_max : largeur de la carte
 * @param y_max : hauteur de la carte
 * @return 1 si valide, 0 sinon
 */
int estLocalisationValide(t_position pos, int x_max, int y_max) {
    return (pos.x >= 0 && pos.x < x_max && pos.y >= 0 && pos.y < y_max);
}

/**
 * @brief Obtenir la position à GAUCHE de la position actuelle
 * @param pos : position actuelle
 * @return nouvelle position à gauche
 */
t_position GAUCHE(t_position pos) {
    t_position nouvelle_pos;
    nouvelle_pos.x = pos.x - 1;
    nouvelle_pos.y = pos.y;
    return nouvelle_pos;
}

/**
 * @brief Obtenir la position à DROITE de la position actuelle
 * @param pos : position actuelle
 * @return nouvelle position à droite
 */
t_position DROITE(t_position pos) {
    t_position nouvelle_pos;
    nouvelle_pos.x = pos.x + 1;
    nouvelle_pos.y = pos.y;
    return nouvelle_pos;
}

/**
 * @brief Obtenir la position au HAUT de la position actuelle
 * @param pos : position actuelle
 * @return nouvelle position en haut
 */
t_position HAUT(t_position pos) {
    t_position nouvelle_pos;
    nouvelle_pos.x = pos.x;
    nouvelle_pos.y = pos.y - 1;
    return nouvelle_pos;
}

/**
 * @brief Obtenir la position au BAS de la position actuelle
 * @param pos : position actuelle
 * @return nouvelle position en bas
 */
t_position BAS(t_position pos) {
    t_position nouvelle_pos;
    nouvelle_pos.x = pos.x;
    nouvelle_pos.y = pos.y + 1;
    return nouvelle_pos;
}

/**
 * @brief Obtenir une chaîne lisible représentant l'orientation
 * @param ori : orientation actuelle
 * @return chaîne représentant l'orientation
 */
const char* obtenirOrientationEnChaine(t_orientation ori) {
    switch (ori) {
        case NORD: return "NORD";
        case EST: return "EST";
        case SUD: return "SUD";
        case OUEST: return "OUEST";
        default: return "INCONNUE";
    }
}
