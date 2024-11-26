// simulation.h

#ifndef SIMULATION_H
#define SIMULATION_H

#include "loc.h"
#include "map.h"

/**
 * @brief Fonction pour exécuter la simulation
 * @param carte : la carte
 * @param loc_depart : localisation de départ de MARC
 */
void executerSimulation(t_map carte, t_localisation loc_depart);

#endif // SIMULATION_H
