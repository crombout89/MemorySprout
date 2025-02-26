#include "garden.h"
#include "plot.h"
#include <stdio.h>

// Initialize the garden
void initializeGarden(Garden *garden) {
    garden->level = 1;  // Start at level 1
    for (int row = 0; row < GARDEN_SIZE; row++) {
        for (int col = 0; col < GARDEN_SIZE; col++) {
            initializePlot(&garden->plots[row][col]);
        }
    }
    printf("Garden initialized with size %dx%d.\n", GARDEN_SIZE, GARDEN_SIZE);
}

// Water a specific plot in the garden
void waterGardenPlot(Garden *garden, int row, int col) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        waterPlot(&garden->plots[row][col]);
    } else {
        printf("Invalid plot coordinates (%d, %d).\n", row, col);
    }
}

// Display all the plants in the garden
void displayGardenPlants(Garden *garden) {
    printf("Plants in the garden:\n");
    for (int row = 0; row < GARDEN_SIZE; row++) {
        for (int col = 0; col < GARDEN_SIZE; col++) {
            Plot *plot = &garden->plots[row][col];
            if (plot->plantName != NULL) {
                printf("Plot (%d, %d): %s", row, col, plot->plantName);
            }
        }
    }
}

// Plant a crop in a specific garden plot
void plantInGardenPlot(Garden *garden, int row, int col, const char *plantName) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        plantInPlot(&garden->plots[row][col], plantName);
    } else {
        printf("Invalid plot coordinates (%d, %d).\n", row, col);
    }
}

// Harvest the plant from a specific plot
void harvestGardenPlot(Garden *garden, int row, int col) {
    if (row >= 0 && row < GARDEN_SIZE && col >= 0 && col < GARDEN_SIZE) {
        harvestPlot(&garden->plots[row][col]);
    } else {
        printf("Invalid plot coodinates (%d, %d).\n", row, col);
    }
}