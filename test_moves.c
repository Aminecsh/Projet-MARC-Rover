// test_moves.c

#include <stdio.h>
#include <assert.h>
#include "moves.h"
#include "map.h"

void tester_mouvement() {
    t_map carte = creerCarteDepuisFichier("../maps/example1.map");
    t_localisation loc = loc_init(2, 2, NORD);
    t_localisation nouvelle_loc = mouvement(loc, AVANCER_10, carte);
    assert(nouvelle_loc.pos.x == loc.pos.x && nouvelle_loc.pos.y == loc.pos.y - 1);
    printf("Déplacement AVANCER_10 de (%d, %d) à (%d, %d)\n",
           loc.pos.x, loc.pos.y, nouvelle_loc.pos.x, nouvelle_loc.pos.y);
    libererCarte(carte);
}

int main() {
    tester_mouvement();
    printf("Tous les tests de mouvements ont réussi.\n");
    return 0;
}
