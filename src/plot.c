#include "plot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a plot
void initializePlot(Plot *plot) {
    plot->moisture = 50;
    plot->fertility = 50;
    plot->soilType = SOIL_NORMAL;
    plot->isTilled = false;
    plot->plantName = NULL;
}

// Water a plot
void waterPlot(Plot *plot) {
    plot->moisture = (plot->moisture + 10 > 100) ? 100 : plot->moisture + 10;
    printf("Plot watered. Moisture is now %d.\n", plot->moisture);
}

// Fertilize a plot
void fertilizePlot(Plot *plot) {
    plot->fertility = (plot->fertility + 15 > 100) ? 100 : plot->fertility + 15;
    printf("Plot fertilized. Fertility is now %d.\n", plot->fertility);
}

// Plant a crop in the plot
void plantInPlot(Plot *plot, const char *plantName) {
    if (plot->plantName != NULL) {
        printf("Plot already has a plant: %s.\n", plot->plantName);
        return;
    }
    // Allocate memory for the plant name and copy the name
    plot->plantName = (char *)malloc(strlen(plantName) + 1);
    if (plot->plantName == NULL) {
        printf("Error: Memory allocation failed.");
        return;
    }
    strcpy(plot->plantName, plantName);
    printf("Planted %s in the plot.\n", plot->plantName);
}

// Harvest the plant
void harvestPlot(Plot *plot) {
    if (plot->plantName == NULL) {
        printf("No plant to harvest.\n");
        return;
    }
    printf("Harvested %s from the plot. \n", plot->plantName);
    free(plot->plantName);        // Free memory
    plot->plantName = NULL;
}