// test_simulation.c

#include <stdio.h>
#include "simulation.h"
#include "map.h"
#include "loc.h"

int main() {
    t_map carte = creerCarteDepuisFichier("../maps/example1.map");
    t_position pos_depart = {0, carte.y_max - 1}; // Départ au coin inférieur gauche
    t_localisation loc_depart = loc_init(pos_depart.x, pos_depart.y, NORD);

    executerSimulation(carte, loc_depart);

    libererCarte(carte);
    return 0;
}
