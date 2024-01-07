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
 * @brief Generates the regions that will contain the rooms for region-based room generation
 * 
 * @param numRegions The number of regions desired
 * @note numRegions MUST BE a perfect square in the current version of this software
 * 
 * @returns Pointer to array of generated regions
*/
Room* generateRegions(int numRegions);

/**
 * @brief Takes in two rooms and tells you if they overlap (configuration is invalid)
 * 
 * @param room1 The first room
 * @param room2 The second room
 * 
 * @note Utility function
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
 * @param container The region to which a Room belongs
 * 
 * @returns A pointer to a Room object
*/
Room* generateRoom(const Room* container);

/**
 * @brief Generates rooms given array of regions and the number of regions
 * 
 * @param regions Array of regions
 * @param numRegions Number of regions
 * 
 * @returns Array of distinct non-overlapping rooms in those regions
*/
Room* generateRooms(Room* regions, int numRegions);