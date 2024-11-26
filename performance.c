// performance.c

#include <stdio.h>
#include <time.h>
#include "performance.h"

void demarrerChrono(t_chrono *chrono) {
    chrono->debut = clock();
}

void arreterChrono(t_chrono *chrono) {
    chrono->fin = clock();
    chrono->ecoule = ((double)(chrono->fin - chrono->debut)) / CLOCKS_PER_SEC;
}

void afficherChrono(const char *nom_tache, t_chrono chrono) {
    printf("%s a pris %.6f secondes.\n", nom_tache, chrono.ecoule);
}
