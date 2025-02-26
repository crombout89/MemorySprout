#ifndef GARDEN_H
#define GARDEN_H

#include "plot.h"
#include "weather.h"
#include "inventory.h"

#define GARDEN_SIZE 25    // 25x25 garden grid for plots

// Garden struct
typedef struct {
    Plot plots[GARDEN_SIZE][GARDEN_SIZE];    // 2D array of plots
    int level;                               // Garden level (for progression mechanics)
    int xp;                                  // Current experience points
    int xpToNextLevel;                       // Experience points required to level up, start with 100.
    Season currentSeason;                    // The current season on the farm
    Weather currentWeather;                  // The current weather on the farm
    int daysInSeason;                        // How many days have passed in the current season
    Inventory inventory;                     // Inventory to hold game items
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

// Weather/Season related function prototypes
void applyWeatherEffects(Garden *garden);
void advanceSeason(Garden *garden);
void updateWeather(Garden *garden);

#endif    // GARDEN_H