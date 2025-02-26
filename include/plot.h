#ifndef PLOT_H
#define PLOT_H

#include <stdbool.h>

// Soil Type enum
typedef enum {
    SOIL_NORMAL,
    SOIL_SANDY,
    SOIL_CLAY,
    SOIL_LOAMY
} SoilType;

// Plot struct
typedef struct {
    int moisture;           // Moisture level (0-100)
    int fertility;          // Fertility level (0-100)
    SoilType soilType;      // Soil Type
    bool isTilled;          // Whether the plot is tilled
    char *plantName;        // Name of the plant in the plot (NULL if empty)
} Plot;

// Function declarations for plot-related logic
void initializePlot(Plot *plot);
void waterPlot(Plot *plot);
void fertilizePlot(Plot *plot);
void plantInPlot(Plot *plot, const char *plantName);
void harvestPlot(Plot *plot);

#endif    // PLOT_H