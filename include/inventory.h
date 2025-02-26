#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX_ITEMS 50            // Maximum number of unique items the inventory can hold

typedef struct {
    char name[30];              // The name of the item (e.g. "Carrot Seed", "Hoe", etc.
    int quantity;                // The quantity of a unque item
} InventoryItem;

typedef struct {
    InventoryItem items[MAX_ITEMS];    // Array of Inventory items
    int itemCount;                     // Number of unique items in the inventory
} Inventory;

// Function prototypes
void initializeInventory(Inventory *inventory);
void addItemToInventory(Inventory *inventory, const char *itemName, int quantity);
void removeItemFromInventory(Inventory *inventory, const char *itemName, int quantity);
void displayInventory(const Inventory *inventory);

#endif    // INVENTORY_H