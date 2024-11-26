# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(MARC_Rover C)

set(CMAKE_C_STANDARD 11)

# Inclure les répertoires d'en-tête
include_directories(${PROJECT_SOURCE_DIR})

# Fichiers sources
set(SOURCES
    main.c
    loc.c
    moves.c
    map.c
    queue.c
    stack.c
    tree.c
    simulation.c
    performance.c
    visualization.c
    utils.c
)

# Exécutable
add_executable(MARC_Rover ${SOURCES})
