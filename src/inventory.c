#include "inventory.h"
#include <stdio.h>
#include <string.h>

// Initialize the inventory
void initializeInventory(Inventory *inventory) {
    inventory->itemCount = 0;           // Start with an empty inventory
}

// Add an item to the inventory
void addItemToInventory(Inventory *inventory, const char *itemName, int quantity) {
    // Check if the item already exists in inventory
    for (int index = 0; index < inventory->itemCount; index++) {
        if (strcmp(inventory->items[index].name, itemName) == 0) {
            // Item exists, increase the inventory count by quantity
            inventory->items[index].quantity += quantity;
            printf("Added %d %s(s) to the inventory.\n", quantity, itemName);
            return;
        }
    }
    // Add the item if it doesn't already exist
    if (inventory->itemCount < MAX_ITEMS) {
        strcpy(inventory->items[inventory->itemCount].name, itemName);
        inventory->items[inventory->itemCount].quantity = quantity;
        inventory->itemCount++;
        printf("Added %d %s(s) to the inventory.\n", quantity, itemName);
    } else {
        printf("Inventory is full! You cannot add anymore items!\n");
    }
}

// Remove an item from the inventory
void removeItemFromInventory(Inventory *inventory, const char *itemName, int quantity) {
    for (int index = 0; index < inventory->itemCount; index++) {
        if (strcmp(inventory->items[index].name, itemName) == 0) {
            if (inventory->items[index].quantity >= quantity) {
                // Item exists in inventory, reduce the quantity
                inventory->items[index].quantity -= quantity;
                printf("Removed %d %s(s) from the inventory.\n", quantity, itemName);
                // Remove the item completely if the quantity reaches 0
                if (inventory->items[index].quantity == 0) {
                    for (int count = index; count < inventory->itemCount - 1; count++) {
                        inventory->items[count] = inventory->items[count + 1];
                    }
                    inventory->itemCount--;
                    printf("%s has been removed from the inventory.\n", itemName);
                }
            } else {
                printf("Not enough %s(s) in the inventory to remove %d.\n", itemName, quantity);
            }
            return;
        }
    }
    printf("%s is not in the inventory.\n", itemName);
}

// Display the inventory
void displayInventory(const Inventory *inventory) {
    printf("Inventory:\n");
    for (int index = 0; index < inventory->itemCount; index++) {
        printf("- %s: (%d)\n", inventory->items[index].name, inventory->items[index].quantity);
    }
    if (inventory->itemCount == 0) {
        printf("There are no items in the inventory to display.\n");
    }
}