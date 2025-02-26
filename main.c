#include "garden.h"

int main() {
    Garden myGarden;
    initializeGarden(&myGarden);

    displayGardenStatus(&myGarden);

    // Test some actions
    plantInGardenPlot(&myGarden, 5, 5, "Carrot");
    waterGardenPlot(&myGarden, 5, 5);
    harvestGardenPlot(&myGarden, 5, 5);

    // Display updated garden status
    displayGardenStatus(&myGarden);

    return 0;
}