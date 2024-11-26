// tree.h

#ifndef TREE_H
#define TREE_H

#include "loc.h"
#include "moves.h"
#include "stack.h"
#include "map.h"

/**
 * @brief Structure pour un noeud dans l'arbre de sélection de mouvements
 */
typedef struct s_noeud_arbre {
    t_localisation loc;               // Localisation après le déplacement
    int cout;                         // Coût associé à ce noeud
    t_deplacement deplacement;        // Déplacement qui a conduit à ce noeud
    struct s_noeud_arbre **enfants;   // Tableau de pointeurs vers les noeuds enfants
    int nb_enfants;                   // Nombre d'enfants
    struct s_noeud_arbre *parent;     // Pointeur vers le noeud parent
} t_noeud_arbre;

/**
 * @brief Structure pour l'arbre de sélection de mouvements
 */
typedef struct s_arbre {
    t_noeud_arbre *racine; // Noeud racine de l'arbre
} t_arbre;

/**
 * @brief Fonction pour créer un nouveau noeud d'arbre
 * @param loc : localisation après le déplacement
 * @param cout : coût de la localisation
 * @param deplacement : déplacement qui a conduit à cette localisation
 * @param parent : pointeur vers le noeud parent
 * @return pointeur vers le noeud d'arbre nouvellement créé
 */
t_noeud_arbre* creerNoeudArbre(t_localisation loc, int cout, t_deplacement deplacement, t_noeud_arbre *parent);

/**
 * @brief Fonction pour créer un arbre vide
 * @return pointeur vers l'arbre nouvellement créé
 */
t_arbre* creerArbre();

/**
 * @brief Fonction pour ajouter un enfant à un noeud parent
 * @param parent : pointeur vers le noeud parent
 * @param enfant : pointeur vers le noeud enfant
 */
void ajouterEnfant(t_noeud_arbre *parent, t_noeud_arbre *enfant);

/**
 * @brief Fonction pour libérer la mémoire allouée pour l'arbre
 * @param noeud : pointeur vers le noeud actuel
 */
void libererArbre(t_noeud_arbre *noeud);

/**
 * @brief Fonction pour trouver la feuille de coût minimum dans l'arbre
 * @param noeud : pointeur vers le noeud actuel
 * @param cout_min : pointeur pour stocker le coût minimum trouvé
 * @param noeud_min : pointeur pour stocker le pointeur vers le noeud de coût minimum
 */
void trouverFeuilleCoutMin(t_noeud_arbre *noeud, int *cout_min, t_noeud_arbre **noeud_min);

/**
 * @brief Fonction pour tracer le chemin d'une feuille à la racine
 * @param noeud : pointeur vers le noeud feuille
 * @param pile : pointeur vers une pile pour stocker les déplacements
 */
void tracerChemin(t_noeud_arbre *noeud, t_pile *pile);

/**
 * @brief Fonction pour construire l'arbre de mouvements récursivement
 * @param noeud : noeud actuel de l'arbre
 * @param carte : la carte
 * @param profondeur : profondeur actuelle (phase)
 * @param profondeur_max : profondeur maximale (total des phases)
 */
void construireArbre(t_noeud_arbre *noeud, t_map carte, int profondeur, int profondeur_max);

#endif // TREE_H
