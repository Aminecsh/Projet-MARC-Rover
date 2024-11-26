// visualization.c

#include <stdio.h>
#include "visualization.h"

void visualiserCarte(t_map carte, t_localisation loc) {
    for (int i = 0; i < carte.y_max; i++) {
        for (int j = 0; j < carte.x_max; j++) {
            if (i == loc.pos.y && j == loc.pos.x) {
                printf(" M "); // Position actuelle de MARC
            } else if (carte.sol[i][j] == STATION_BASE) {
                printf(" B ");
            } else {
                switch (carte.sol[i][j]) {
                    case PLAINE:
                        printf(" - ");
                        break;
                    case ERG:
                        printf(" ~ ");
                        break;
                    case REG:
                        printf(" ^ ");
                        break;
                    case CREVASSE:
                        printf(" X ");
                        break;
                    default:
                        printf(" ? ");
                        break;
                }
            }
        }
        printf("\n");
    }
}
