// main.c

#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "loc.h"
#include "simulation.h"

int main() {
    // Charger la carte
    t_map carte = creerCarteDepuisFichier("maps-backup/example1.map");

    // Définir la position de départ et l'orientation de MARC
    // Départ au coin inférieur gauche face au NORD
    t_position pos_depart = {0, carte.y_max - 1};
    t_localisation loc_depart = loc_init(pos_depart.x, pos_depart.y, NORD);

    // Exécuter la simulation
    executerSimulation(carte, loc_depart);

    // Libérer la mémoire allouée
    libererCarte(carte);

    return 0;
}

