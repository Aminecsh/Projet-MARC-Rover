// test_map.c

#include <stdio.h>
#include <assert.h>
#include "map.h"

void tester_obtenirPositionBase() {
    t_map carte = creerCarteDepuisFichier("../maps/example1.map");
    t_position pos_base = obtenirPositionBase(carte);
    assert(pos_base.x >= 0 && pos_base.y >= 0);
    printf("Station de base trouvée à (%d, %d)\n", pos_base.x, pos_base.y);
    libererCarte(carte);
}

void tester_calculerCouts() {
    t_map carte = creerCarteDepuisFichier("../maps/example1.map");
    calculerCouts(carte);
    // Vérifier que le coût de la station de base est zéro
    t_position pos_base = obtenirPositionBase(carte);
    assert(carte.couts[pos_base.y][pos_base.x] == 0);
    // Optionnellement , afficher les coûts ou effectuer d'autres assertions
    libererCarte(carte);
}

int main() {
    tester_obtenirPositionBase();
    tester_calculerCouts();
    printf("Tous les tests de carte ont réussi.\n");
    return 0;
}
