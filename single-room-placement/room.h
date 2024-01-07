// For random numbers
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

#define WINDOW_WIDTH 800  
#define WINDOW_HEIGHT 800 

typedef struct Room {

    int x;
    int y;

    int width;
    int height;

    Color color;

} Room;

/**
 * @brief Takes in two rooms and tells you if they overlap (configuration is invalid)
 * 
 * @param room1 The first room
 * @param room2 The second room
 * 
 * @returns 1 if the rooms overlap, 0 otherwise
*/
int doOverlap(Room* room1, Room* room2);

/**
 * @brief Displays a room given its pointer
*/
void displayRoom(Room* room);

/**
 * @brief Generates a Room object at random
 * 
 * @returns A pointer to a Room object
*/
Room* generateRoom();