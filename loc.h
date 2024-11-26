#ifndef LOC_H
#define LOC_H

/**
 * @brief Énumération pour l'orientation du robot (NORD, EST, SUD, OUEST)
 */
typedef enum e_orientation {
    NORD,
    EST,
    SUD,
    OUEST
} t_orientation;

/**
 * @brief Structure pour la position du robot
 */
typedef struct e_position {
    int x; // Coordonnée x
    int y; // Coordonnée y
} t_position;

/**
 * @brief Structure pour la localisation du robot
 */
typedef struct s_localisation {
    t_position      pos; // Position x, y
    t_orientation   ori; // Orientation
} t_localisation;

/**
 * @brief Initialiser la localisation du robot
 * @param x : position x
 * @param y : position y
 * @param ori : orientation du robot
 * @return la localisation initialisée
 */
t_localisation loc_init(int x, int y, t_orientation ori);

/**
 * @brief Vérifier si une position est valide pour le robot
 * @param pos : position du robot
 * @param x_max : largeur de la carte
 * @param y_max : hauteur de la carte
 * @return 1 si la position est valide, 0 sinon
 */
int estLocalisationValide(t_position pos, int x_max, int y_max);

/**
 * @brief Obtenir la position à GAUCHE d'une position donnée
 * @param pos : position actuelle
 * @return nouvelle position à gauche
 */
t_position GAUCHE(t_position pos);

/**
 * @brief Obtenir la position à DROITE d'une position donnée
 * @param pos : position actuelle
 * @return nouvelle position à droite
 */
t_position DROITE(t_position pos);

/**
 * @brief Obtenir la position en HAUT d'une position donnée
 * @param pos : position actuelle
 * @return nouvelle position en haut
 */
t_position HAUT(t_position pos);

/**
 * @brief Obtenir la position en BAS d'une position donnée
 * @param pos : position actuelle
 * @return nouvelle position en bas
 */
t_position BAS(t_position pos);

/**
 * @brief Obtenir une chaîne lisible représentant l'orientation
 * @param ori : orientation (NORD, EST, SUD, OUEST)
 * @return chaîne représentant l'orientation
 */
const char* obtenirOrientationEnChaine(t_orientation ori);

#endif // LOC_H
