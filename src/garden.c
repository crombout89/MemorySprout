#include "garden.h"
#include "plot.h"
#include <stdio.h>

// Initialize the garden
void initializeGarden(Garden *garden) {
    garden->level = 1;                          // Start at level 1
    garden->xp = 0;                             // Start with 0 experience points
    garden->xpToNextLevel = 100;                // Require 100 XP for the next level
    garden->currentSeason = SEASON_SPRING;      // The game storyline starts in the Spring
    garden->currentWeather = WEATHER_SUNNY;     // The first day in the game is sunny
    garden->daysInSeason = 1;                   // First day of the season

    initializeInventory(&garden->inventory);    // Initialize the inventory

    for (int row = 0; row < GARDEN_SIZE; row++) {
        for (int col = 0; col < GARDEN_SIZE; col++) {
            initializePlot(&garden->plots[row][col]);
        }
    }
    printf("Garden initialized with size %dx%d at level %d. All plots are empty.\n",
        GARDEN_SIZE, GARDEN_SIZE, garden->level);
}

// Water a specific plot in the garden
void waterGardenPlot(Garden *garden, int row, int col) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        waterPlot(&garden->plots[row][col]);
        gainGardenXP(garden, 5);        // Gain 5 XP for watering
    } else {
        printf("Invalid plot coordinates (%d, %d).\n", row, col);
    }
}

// Display all the plants in the garden
void displayGardenPlants(Garden *garden) {
    printf("Plants in the garden:\n");
    int hasPlants = 0;  // Flag to check if any plants are present
    for (int row = 0; row < GARDEN_SIZE; row++) {
        for (int col = 0; col < GARDEN_SIZE; col++) {
            Plot *plot = &garden->plots[row][col];
            if (plot->plantName != NULL) {
                printf("Plot (%d, %d): %s\n", row, col, plot->plantName);
                hasPlants = 1;
            }
        }
    }
    if (!hasPlants) {
        printf("There are no plants in the garden.\n");
    }
}

// Plant a crop in a specific garden plot
void plantInGardenPlot(Garden *garden, int row, int col, const char *plantName) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        plantInPlot(&garden->plots[row][col], plantName);
        gainGardenXP(garden, 10);       // Gain 10 XP for planting
    } else {
        printf("Invalid plot coordinates (%d, %d).\n", row, col);
    }
}

// Harvest the plant from a specific plot
void harvestGardenPlot(Garden *garden, int row, int col) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        harvestPlot(&garden->plots[row][col]);
        gainGardenXP(garden, 15);        // Gain 15 XP for harvesting
    } else {
        printf("Invalid plot coordinates (%d, %d).\n", row, col);
    }
}

// Implement weather effects
void applyWeatherEffects(Garden *garden) {
    for (int row = 0; row < GARDEN_SIZE; row++) {
        for (int col = 0; col < GARDEN_SIZE; col++) {
            Plot *plot = &garden->plots[row][col];
            switch (garden->currentWeather) {
                case WEATHER_SUNNY:
                    plot->moisture -= 10;           // Sunny weather dries out the soil
                    break;
                case WEATHER_CLOUDY:
                    plot->moisture -= 5;            // Cloudy weather dries soil out slower
                case WEATHER_RAINY:
                    plot->moisture += 25;            // Rainy weather increases moisture a lot
                case WEATHER_DROUGHT:
                    plot->moisture -= 20;           // Drought has a large drying effect on the soil
            }
            // Keep moisture within the defined bounds (0-100)
            if (plot->moisture < 0) { plot->moisture = 0; }
            if (plot->moisture > 100) { plot->moisture = 100; }
        }
    }
}

// Update weather to randomly cycle through options
void updateWeather(Garden *garden) {
    garden->currentWeather = rand() % 4;        // WEATHER_SUNNY TO WEATHER_DROUGHT
    printf("Today's weather is %s.\n", getWeatherName(garden->currentWeather));
}

// Advance the season in the game
void advanceSeason(Garden *garden) {
    garden->daysInSeason++;
    if (garden->daysInSeason > 31) {
        garden->daysInSeason = 0;
        garden->currentSeason = (garden->currentSeason + 1) % 4;        // Cycle through all 4 seasons
        printf("The season has changed to %s!\n", getSeasonName(garden->currentSeason));
    }
}

// Add experience to the garden & check for level ups
void gainGardenXP(Garden *garden, int xp) {
    garden->xp += xp;   // Add xp
    printf("Gained %d XP! Current XP: %d/%d\n", xp, garden->xp, garden->xpToNextLevel);

    // Check for level up
    if (garden->xp >= garden->xpToNextLevel) {
        garden->xp -= garden->xpToNextLevel;    // Carry over extra XP
        garden->level ++;                       // Increase level
        garden->xpToNextLevel += 50;            // Increase XP requirement for next level
        printf("Congratulations! Your garden leveled up to Level %d!\n", garden->level);
    }
}

// Display garden status
void displayGardenStatus(Garden *garden) {
    printf("Garden level: %d\n", garden->level);
    printf("XP: %d/%d\n", garden->xp, garden->xpToNextLevel);
    printf("Season: %s\n", getSeasonName(garden->currentSeason));
    printf("Weather: %s\n", getWeatherName(garden->currentWeather));
}