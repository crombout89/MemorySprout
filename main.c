#include "garden.h"
#include <stdio.h>

int main() {
    srand(time(NULL));          // Seed the random number generator
    Garden myGarden;
    initializeGarden(&myGarden);

    // Add some items to the inventory
    addItemToInventory(&myGarden.inventory, "Carrot Seed", 10);
    addItemToInventory(&myGarden.inventory, "Hoe", 1);
    addItemToInventory(&myGarden.inventory, "Greenies", 3);

    // Display the inventory
    displayInventory(&myGarden.inventory);

    // Remove items
    removeItemFromInventory(&myGarden.inventory, "Carrot Seed", 5);
    removeItemFromInventory(&myGarden.inventory, "Hoe", 1);

    // Display the inventory again
    displayInventory(&myGarden.inventory);

    return 0;
}