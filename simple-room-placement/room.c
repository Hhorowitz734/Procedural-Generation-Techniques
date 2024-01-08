
#include "room.h"
#include <math.h>

int doOverlap(Room* room1, Room* room2) {

    if (room1 == NULL || room2 == NULL) { return 1; }

    if (room1->x >= room2->x + room2->width || room2->x >= room1->x + room1->width) { return 0; }
    if (room1->y >= room2->y + room2->height || room2->y >= room1->y + room1->height) { return 0; }

    return 1;

} // Use this function to generate within a region

void displayRoom(Room* room) {
    if (room == NULL) return;

    int fontSize = 10; 
    Font font = GetFontDefault();

    int numCharsWidth = room->width / fontSize;
    int numCharsHeight = room->height / fontSize;

    for (int i = 0; i < numCharsWidth; i++) {
        for (int j = 0; j < numCharsHeight; j++) {
            int posX = room->x + i * fontSize;
            int posY = room->y + j * fontSize;

            DrawTextEx(font, "#", (Vector2){ posX, posY }, fontSize, 1, room->color);
        }
    }
}

Room* generateRoom(const Room* container) {

    Room* newRoom = (Room*)malloc(sizeof(Room));


    int baseSize = 10;
    int randomFactor = (rand() % 15) + 3;

    newRoom->width = baseSize * randomFactor;
    newRoom->height = baseSize * randomFactor;

    newRoom->x = container->x + (rand() % (container->width - newRoom->width));
    newRoom->y = container->y + (rand() % (container->height - newRoom->height));

    newRoom->color.r = rand() % 255;
    newRoom->color.g = rand() % 255;
    newRoom->color.b = rand() % 255;
    newRoom->color.a = 255;

    return newRoom;

}


Room* generateRegions(int numRegions) {
    Room *regions = malloc(numRegions * sizeof(Room));
    
    if (regions == NULL) { return NULL; }

    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();

    int cols = sqrt(numRegions);

    int regionWidth = screenWidth / cols;
    int regionHeight = screenHeight / cols;

    int extraWidth = screenWidth % cols; 
    int extraHeight = screenHeight % cols; 

    int regionX = 0, regionY = 0;

    for (int i = 0; i < numRegions; i++) {
        regions[i].x = regionX;
        regions[i].y = regionY;
        regions[i].width = regionWidth + (extraWidth > 0 ? 1 : 0);
        regions[i].height = regionHeight + (extraHeight > 0 ? 1 : 0);

        if (extraWidth > 0) {
            extraWidth--;
        }

        regionX += regions[i].width;

        if (regionX >= screenWidth) {
            regionX = 0;
            regionY += regions[i].height;

            if (extraHeight > 0) {
                extraHeight--;
            }
        }
    }

    return regions;
}


Room* generateRooms(Room* regions, int numRegions) {
    Room* rooms = (Room*)malloc(numRegions * 2 * sizeof(Room));

    for (int i = 0; i < numRegions; i++) {
        rooms[2 * i] = *generateRoom(&regions[i]);
        do {
            rooms[2 * i + 1] = *generateRoom(&regions[i]); }
        while (doOverlap(&rooms[2 * i], &rooms[2 * i + 1]) == 1);
    }

    return rooms;
}
