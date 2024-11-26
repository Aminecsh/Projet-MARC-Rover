// map.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"
#include "loc.h"
#include "queue.h" // Ensure this is included


/* Prototypes des fonctions locales */
void calculerCouts(t_map carte);
void supprimerFauxCrevasses(t_map carte);

/* Définitions des fonctions */

t_position obtenirPositionBase(t_map carte)
{
    t_position pos;
    int trouve = 0;
    for (int i = 0; i < carte.y_max && !trouve; i++)
    {
        for (int j = 0; j < carte.x_max && !trouve; j++)
        {
            if (carte.sol[i][j] == STATION_BASE)
            {
                pos.x = j;
                pos.y = i;
                trouve = 1;
            }
        }
    }
    if (!trouve)
    {
        fprintf(stderr, "Erreur : station de base non trouvée dans la carte\n");
        exit(1);
    }
    return pos;
}

void libererCarte(t_map carte) {
    for (int i = 0; i < carte.y_max; i++) {
        free(carte.sol[i]);
        free(carte.couts[i]);
    }
    free(carte.sol);
    free(carte.couts);
}

void supprimerFauxCrevasses(t_map carte)
{
    // Implémentation pour supprimer les faux coûts de crevasses
    // Pour simplifier, nous supposons que c'est géré dans calculerCouts
}

void calculerCouts(t_map carte)
{
    t_position stationBase = obtenirPositionBase(carte);
    t_file file = creerFile(carte.x_max * carte.y_max);
    enfiler(&file, stationBase);
    carte.couts[stationBase.y][stationBase.x] = 0;

    while (file.debut != file.fin)
    {
        t_position pos = defiler(&file);
        int cout_self = _cout_sol[carte.sol[pos.y][pos.x]];

        // Obtenir les voisins
        t_position voisins[4] = {GAUCHE(pos), DROITE(pos), HAUT(pos), BAS(pos)};

        for (int i = 0; i < 4; i++) {
            t_position voisin = voisins[i];
            if (estLocalisationValide(voisin, carte.x_max, carte.y_max)) {
                int cout_voisin = carte.couts[voisin.y][voisin.x];
                int nouveau_cout = carte.couts[pos.y][pos.x] + cout_self;
                if (nouveau_cout < cout_voisin) {
                    carte.couts[voisin.y][voisin.x] = nouveau_cout;
                    enfiler(&file, voisin);
                }
            }
        }
    }

    free(file.valeurs);
}

/* Définitions des fonctions exportées */

t_map creerCarteDepuisFichier(char *nom_fichier)
{
    t_map carte;
    int xdim, ydim;
    FILE *fichier = fopen(nom_fichier,"rt");
    if (fichier == NULL)
    {
        fprintf(stderr, "Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        exit(1);
    }
    fscanf(fichier, "%d", &ydim);
    fscanf(fichier, "%d", &xdim);
    carte.x_max = xdim;
    carte.y_max = ydim;

    // Allouer la mémoire pour sol et pentes
    carte.sol = (t_sol **)malloc(ydim * sizeof(t_sol *));
    carte.pentes = (t_direction_pente **)malloc(ydim * sizeof(t_direction_pente *));
    for (int i = 0; i < ydim; i++)
    {
        carte.sol[i] = (t_sol *)malloc(xdim * sizeof(t_sol));
        carte.pentes[i] = (t_direction_pente *)malloc(xdim * sizeof(t_direction_pente));
    }

    // Allouer la mémoire pour les coûts
    carte.couts = (int **)malloc(ydim * sizeof(int *));
    for (int i = 0; i < ydim; i++)
    {
        carte.couts[i] = (int *)malloc(xdim * sizeof(int));
    }

    // Lire les données de sol et de pente
    for (int i = 0; i < ydim; i++)
    {
        for (int j = 0; j < xdim; j++)
        {
            int valeur_sol, valeur_pente;
            fscanf(fichier, "%d %d", &valeur_sol, &valeur_pente);
            carte.sol[i][j] = (t_sol)valeur_sol;
            carte.pentes[i][j] = (t_direction_pente)valeur_pente;
            carte.couts[i][j] = COUT_NON_DEFINI;
        }
    }
    fclose(fichier);

    calculerCouts(carte);
    supprimerFauxCrevasses(carte);
    return carte;
}

void afficherCarte(t_map carte)
{
    for (int i = 0; i < carte.y_max; i++)
    {
        for (int rep = 0; rep < 3; rep++)
        {
            for (int j = 0; j < carte.x_max; j++)
            {
                char c[4];
                switch (carte.sol[i][j])
                {
                    case STATION_BASE:
                        strcpy(c, (rep == 1) ? " B " : "   ");
                        break;
                    case PLAINE:
                        strcpy(c, "---");
                        break;
                    case ERG:
                        strcpy(c, "~~~");
                        break;
                    case REG:
                        strcpy(c, "^^^");
                        break;
                    case CREVASSE:
                        strcpy(c, "   "); // Pourrait utiliser des caractères spéciaux
                        break;
                    default:
                        strcpy(c, "???");
                        break;
                }
                printf("%s", c);
            }
            printf("\n");
        }
    }
}
