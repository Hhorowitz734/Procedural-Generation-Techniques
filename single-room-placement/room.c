
#include "room.h"

int doOverlap(Room* room1, Room* room2) {

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

Room* generateRoom() {
    Room* room = (Room*)malloc(sizeof(Room));

    room->width = ((rand() % 20) + 1) * 10 ;
    room->height = ((rand() % 20) + 1) * 10;

    room->x = rand() % (WINDOW_WIDTH - room->width);
    room->y = rand() % (WINDOW_HEIGHT - room->height);

    room->color.r = rand() % 255;
    room->color.g = rand() % 255;
    room->color.b = rand() % 255;
    room->color.a = 255;

    return room;
}