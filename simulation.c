#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simulation.h"
#include "moves.h"
#include "tree.h"
#include "stack.h"
#include "map.h"
#include "visualization.h"
#include "performance.h"

/**
 * @brief Fonction pour exécuter la simulation
 * @param carte : la carte
 * @param loc_depart : localisation de départ de MARC
 */
void executerSimulation(t_map carte, t_localisation loc_depart) {
    t_localisation loc_actuelle = loc_depart;
    int numero_phase = 0;

    // Initialiser le générateur de nombres aléatoires
    srand((unsigned int)time(NULL));

    t_chrono chrono_total, chrono_phase; // Chronos pour mesurer les performances

    // Démarrer le chronomètre global
    demarrerChrono(&chrono_total);

    printf("==========================================================================\n"
           "= Démarrage de la simulation d'entraînement du rover MARC =\n"
           "==========================================================================\n");
    printf("Position de départ de MARC : x = %d, y = %d, orientation = %s\n",
           loc_depart.pos.x, loc_depart.pos.y, obtenirOrientationEnChaine(loc_depart.ori));

    printf("\nCarte initiale :\n");
    visualiserCarte(carte, loc_actuelle); // Affiche la carte avec la position initiale de MARC

    while (carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x] != 0) {
        numero_phase++;
        printf("\n--- Phase %d ---\n", numero_phase);

        // Démarrer le chronomètre pour cette phase
        demarrerChrono(&chrono_phase);

        printf("Position actuelle : x = %d, y = %d, orientation : %s, coût restant : %d\n",
               loc_actuelle.pos.x, loc_actuelle.pos.y, obtenirOrientationEnChaine(loc_actuelle.ori),
               carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x]);

        // Construire l'arbre de sélection de mouvements pour cette phase
        printf("\nConstruction de l'arbre de sélection des mouvements...\n");
        t_arbre *arbre = creerArbre();
        t_noeud_arbre *racine = creerNoeudArbre(loc_actuelle, carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x], -1, NULL);
        arbre->racine = racine;

        printf("Création de l'arbre jusqu'à une profondeur de 5 mouvements...\n");
        construireArbre(racine, carte, 0, 5);
        printf("Arbre construit avec succès.\n");

        // Trouver la feuille de coût minimum
        printf("\nRecherche de la feuille avec le coût minimum...\n");
        int cout_min = COUT_NON_DEFINI;
        t_noeud_arbre *noeud_min = NULL;
        trouverFeuilleCoutMin(arbre->racine, &cout_min, &noeud_min);

        if (noeud_min != NULL) {
            printf("Feuille avec le coût minimum trouvée : coût = %d\n", cout_min);

            // Tracer le chemin du noeud_min à la racine
            printf("\nTraçage du chemin optimal...\n");
            t_pile pile = creerPile(10); // Ajuster la taille si nécessaire
            tracerChemin(noeud_min, &pile);

            printf("\nExécution des déplacements...\n");
            // Appliquer la séquence de déplacements
            while (pile.nbElements > 0) {
                int index_deplacement = depiler(&pile);
                t_deplacement deplacement = (t_deplacement)index_deplacement;
                printf("Déplacement exécuté : %s\n", obtenirDeplacementEnChaine(deplacement));
                mettreAJourLocalisation(&loc_actuelle, deplacement, carte);

                // Afficher la localisation actuelle de MARC
                printf("Nouvelle position de MARC : x = %d, y = %d\n", loc_actuelle.pos.x, loc_actuelle.pos.y);
                printf("Orientation actuelle de MARC : %s\n", obtenirOrientationEnChaine(loc_actuelle.ori));
                printf("Coût actuel à cette position : %d\n", carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x]);

                // Visualiser la carte après chaque déplacement
                visualiserCarte(carte, loc_actuelle);

                // Vérifier si MARC a atteint la station de base
                if (carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x] == 0) {
                    printf("\nMARC a atteint la station de base à la position x = %d, y = %d !\n",
                           loc_actuelle.pos.x, loc_actuelle.pos.y);

                    // Arrêter et afficher le chrono de la phase
                    arreterChrono(&chrono_phase);
                    afficherChrono("Phase actuelle", chrono_phase);

                    libererPile(&pile);
                    libererArbre(arbre->racine);
                    free(arbre);
                    break;
                }

                // Vérifier si MARC est tombé dans une crevasse
                if (carte.sol[loc_actuelle.pos.y][loc_actuelle.pos.x] == CREVASSE) {
                    printf("\nAttention ! MARC est tombé dans une crevasse à la position x = %d, y = %d. Fin de la simulation.\n",
                           loc_actuelle.pos.x, loc_actuelle.pos.y);
                    libererPile(&pile);
                    libererArbre(arbre->racine);
                    free(arbre);
                    return;
                }

                // Vérifier si MARC est sorti de la carte
                if (!estLocalisationValide(loc_actuelle.pos, carte.x_max, carte.y_max)) {
                    printf("\nErreur ! MARC est sorti de la carte à la position x = %d, y = %d. Fin de la simulation.\n",
                           loc_actuelle.pos.x, loc_actuelle.pos.y);
                    libererPile(&pile);
                    libererArbre(arbre->racine);
                    free(arbre);
                    return;
                }
            }
            libererPile(&pile);
        } else {
            printf("Aucun chemin valide trouvé pour cette phase. Fin de la simulation.\n");
            libererArbre(arbre->racine);
            free(arbre);
            break;
        }

        // Arrêter et afficher le chrono pour cette phase
        arreterChrono(&chrono_phase);
        afficherChrono("Phase actuelle", chrono_phase);

        libererArbre(arbre->racine);
        free(arbre);
    }

    // Arrêter et afficher le chrono total
    arreterChrono(&chrono_total);
    afficherChrono("Simulation totale", chrono_total);

    if (carte.couts[loc_actuelle.pos.y][loc_actuelle.pos.x] == 0) {
        printf("\nSimulation terminée avec succès. MARC a atteint la station de base !\n");
    } else {
        printf("\nLa simulation s'est terminée sans atteindre la station de base.\n");
    }
}
