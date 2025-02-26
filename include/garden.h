#ifndef GARDEN_H
#define GARDEN_H

#include "plot.h"

#define GARDEN_SIZE 25    // 25x25 garden grid for plots

// Garden struct
typedef struct {
    Plot plots[GARDEN_SIZE][GARDEN_SIZE];    // 2D array of plots
    int level;                               // Garden level (for progression mechanics)
    int xp;                                  // Current experience points
    int xpToNextLevel;                // Experience points required to level up, start with 100.
} Garden;

// Function declarations
void initializeGarden(Garden *garden);
void waterGardenPlot(Garden *garden, int x, int y);
void displayGardenPlants(Garden *garden);
void plantInGardenPlot(Garden *garden, int x, int y, const char *plantName);
void harvestGardenPlot(Garden *garden, int x, int y);

// Game mechanics function prototypes
void gainGardenXP(Garden *garden, int xp);
void displayGardenStatus(Garden *garden);

#endif    // GARDEN_H