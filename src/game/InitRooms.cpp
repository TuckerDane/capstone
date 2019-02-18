#include "InitRooms.hpp"

Room* Game::initRoomZero(){
    Room* roomZero = new Room("rooms/puzzle_2.room");
    roomZero->setDoor(new Door(7, 17, 0, 2, 2, 1, true, COLOR_YELLOW), 0);
    roomZero->setDoor(new Door(2, 1, 0, 7, 16, 1, true, COLOR_YELLOW), 1);
    roomZero->setItem(new Immovable(7, 2), 0);
    roomZero->setItem(new Immovable(6, 3), 1);
    roomZero->setItem(new Immovable(5, 4), 2);
    roomZero->setItem(new Immovable(5, 5), 3);
    roomZero->setItem(new Movable(3, 6, "■"), 4);
    roomZero->setItem(new Immovable(4, 5), 5);
    roomZero->setItem(new Movable(5, 6, "■"), 6);
    roomZero->setItem(new Immovable(4, 7), 7);
    roomZero->setItem(new Movable(6, 7, "■"), 8);
    roomZero->setItem(new Immovable(4, 8), 9);
    roomZero->setItem(new Immovable(5, 8), 10);
    roomZero->setItem(new Movable(6, 8, "■"), 11);
    roomZero->setItem(new Immovable(5, 9), 12);
    roomZero->setItem(new Immovable(6, 10), 13);
    roomZero->setItem(new Immovable(7, 11), 14);
    roomZero->setItem(new Key(7, 10, "Yellow Key", 1, COLOR_YELLOW), 15);
    return roomZero;
}