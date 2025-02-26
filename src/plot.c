#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
  printf("Plot watered. Moisutre is now %d.\n", plot->moisture);
}

// Fertilize a plot
void fertilizePlot(Plot *plot) {
  plot->fertility = (plot->fertility + 15 > 100) ? 100 : plot->fertility + 15;
  printf("Plot fertilized. Fertility is now %d.", plot->fertility);
}