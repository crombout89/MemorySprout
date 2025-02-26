#ifndef GARDEN_H
#define GARDEN_H

#include "plot.h"

#define GARDEN_SIZE 25    // 25x25 garden grid for plots

// Garden struct
typedef struct {
    Plot plots[GARDEN_SIZE][GARDEN_SIZE];    // 2D array of plots
    int level;                               // Garden level (for progression mechanics)
} Garden;

// Function declarations
void initializeGarden(Garden *garden);
void waterGardenPlot(Garden *garden, int x, int y);
void displayGardenPlants(Garden *garden);
void plantInGardenPlot(Garden *garden, int x, int y, const char *plantName);
void harvestGardenPlot(Garden *garden, int x, int y);

#endif    // GARDEN_H