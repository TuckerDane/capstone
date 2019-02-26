#include "InitRooms.hpp"

Room* Game::initStartRoom(){
    Room* room = new Room("rooms/start.room");
    room->setDoor(new Door(5, 1, 2, 3, 3, -1, false, COLOR_WHITE), 0);
    room->setDoor(new Door(15, 1, 8, 3, 3, -1, false, COLOR_WHITE), 1);
    return room;
}

Room* Game::initPuzzleRoom2(){
    Room* room = new Room("rooms/puzzle_2.room");
    room->setDoor(new Door(7, 17, 5, 10, 20, 1, true, COLOR_YELLOW), 0);
    room->setItem(new Immovable(7, 2), 0);
    room->getItem(0)->setWeight(1000);
    room->setItem(new Immovable(6, 3), 1);
    room->getItem(1)->setWeight(1000);
    room->setItem(new Immovable(5, 4), 2);
    room->getItem(2)->setWeight(1000);
    room->setItem(new Immovable(5, 5), 3);
    room->getItem(3)->setWeight(1000);
    room->setItem(new Movable(3, 6, "■"), 4);
    room->getItem(4)->setColor(COLOR_WHITE);
    room->setItem(new Immovable(4, 5), 5);
    room->getItem(5)->setWeight(1000);
    room->setItem(new Movable(5, 6, "■"), 6);
    room->getItem(6)->setColor(COLOR_WHITE);
    room->setItem(new Immovable(4, 7), 7);
    room->getItem(7)->setWeight(1000);
    room->setItem(new Movable(6, 7, "■"), 8);
    room->getItem(8)->setColor(COLOR_WHITE);
    room->setItem(new Immovable(4, 8), 9);
    room->getItem(9)->setWeight(1000);
    room->setItem(new Immovable(5, 8), 10);
    room->getItem(10)->setWeight(1000);
    room->setItem(new Movable(6, 8, "■"), 11);
    room->getItem(11)->setColor(COLOR_WHITE);
    room->setItem(new Immovable(5, 9), 12);
    room->getItem(12)->setWeight(1000);
    room->setItem(new Immovable(6, 10), 13);
    room->getItem(13)->setWeight(1000);
    room->setItem(new Immovable(7, 11), 14);
    room->getItem(14)->setWeight(1000);
    room->setItem(new Key(7, 10, "Yellow Key", 1, COLOR_YELLOW), 15);
    room->setItem(new Key(7, 3, "Magenta Key", 3, COLOR_MAGENTA), 16);
    return room;
}

Room* Game::initPuzzleRoom5(){
    Room* room = new Room("rooms/puzzle_5.room");
    room->setDoor(new Door(10, 19, 2, 7, 16, 1, true, COLOR_YELLOW), 0);
    room->setDoor(new Door(14, 93, -1, 7, 16, 2, true, COLOR_RED), 1);
    room->setDoor(new Door(10, 23, -1, -1, -1, 3, true, COLOR_MAGENTA), 2);
    room->setDoor(new Door(6, 41, -1, -1, -1, 4, true, COLOR_CYAN), 3);
    room->setItem(new Movable(7, 23, "■"), 0);
    room->getItem(0)->setColor(COLOR_GREEN);
    room->getItem(0)->setHealing(1);
    room->setItem(new Movable(13, 23, "■"), 1);
    room->getItem(1)->setColor(COLOR_RED);
    room->getItem(1)->setDamage(1);
    room->setItem(new Key(10, 33, "Cyan Key", 4, COLOR_CYAN), 2);
    return room;
}

Room* Game::initPuzzleRoom8() {
    Room* room = new Room("rooms/puzzle_8.room");
    room->setItem(new Movable2(4, 6, "o"), 0);
    room->setItem(new Movable2(4, 8, "o"), 1);
    room->setItem(new Movable2(4, 10, "o"), 2);
    room->setItem(new Movable2(4, 12, "o"), 3);
    room->setItem(new Movable2(4, 14, "o"), 4);
    room->setItem(new Movable(6, 5, "●"), 5);
    room->setItem(new Movable(6, 7, "●"), 6);
    room->setItem(new Movable(6, 9, "●"), 7);
    room->setItem(new Movable(6, 11, "●"), 8);
    room->setItem(new Movable(6, 13, "●"), 9);
    return room;
}