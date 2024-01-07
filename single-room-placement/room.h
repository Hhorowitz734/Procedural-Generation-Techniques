// For random numbers
#include <stdlib.h>
#include <time.h>

typedef struct Room {

    int x;
    int y;

    int width;
    int height;

} Room;

Room* generateRoom() {

    Room* room = (Room*)malloc(sizeof(Room));

    srand(time(NULL));

    room->width = (rand() % 5) * 10;
    room->height = (rand() % 5) * 10;



}