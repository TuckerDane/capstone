#include "InitRooms.hpp"

Room* Game::initPuzzleRoom1(){
  Room* roomOne = new Room("rooms/puzzle_1.room");
//row one of teleporters
  roomOne->setTeleporter(new Teleporter(4, 4, 1, 3, 17, COLOR_BLUE), 0);   
  roomOne->setTeleporter(new Teleporter(4, 9, 1, 17, 6, COLOR_BLUE), 1);   
  roomOne->setTeleporter(new Teleporter(4, 15, 1, 17, 29, COLOR_BLUE), 2);   
  roomOne->setTeleporter(new Teleporter(4, 21, 1, 17, 17, COLOR_BLUE), 3);   
  roomOne->setTeleporter(new Teleporter(4, 27, 1, 17, 17, COLOR_BLUE), 4);   
  roomOne->setTeleporter(new Teleporter(4, 32, 1, 17, 29, COLOR_BLUE), 5);   
//row two
  roomOne->setTeleporter(new Teleporter(11, 4, 1, 3, 6, COLOR_BLUE), 6);   
  roomOne->setTeleporter(new Teleporter(11, 9, 1, 4, 29, COLOR_BLUE), 7);   
  roomOne->setTeleporter(new Teleporter(11, 15, 4, 3, 40, COLOR_GREEN), 8);   
  roomOne->setTeleporter(new Teleporter(11, 21, 4, 13, 104, COLOR_GREEN), 9);   
  roomOne->setTeleporter(new Teleporter(11, 27, 1, 10, 7, COLOR_BLUE), 10);   
  roomOne->setTeleporter(new Teleporter(11, 32, 1, 3, 17, COLOR_BLUE), 11);   
//row three
  roomOne->setTeleporter(new Teleporter(18, 4, 1, 3, 29, COLOR_BLUE), 12);   
  roomOne->setTeleporter(new Teleporter(18, 9, 1, 10, 29, COLOR_BLUE), 13);   
  roomOne->setTeleporter(new Teleporter(18, 15, 1, 10, 29, COLOR_BLUE), 14);   
  roomOne->setTeleporter(new Teleporter(18, 21, 1, 17, 6, COLOR_BLUE), 15);   
  roomOne->setTeleporter(new Teleporter(18, 27, 1, 10, 17, COLOR_BLUE), 16);   
  roomOne->setTeleporter(new Teleporter(18, 32, 1, 3, 6, COLOR_BLUE), 17);   

  return roomOne; 
}

Room* Game::initPuzzleRoom2(){
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

Room* Game::initPuzzleRoom4(){
  Room* roomFour = new Room("rooms/puzzle_4.room");
  //teleporters
  roomFour->setTeleporter(new Teleporter(11, 49, 1, 3, 6, COLOR_BLUE), 0); //logo return   
  roomFour->setTeleporter(new Teleporter(9, 117, 1, 17, 6, COLOR_BLUE), 1); //preventing user from getting trapped in pac man region
  roomFour->setTeleporter(new Teleporter(14, 126, 1, 3, 6, COLOR_BLUE), 2); //pac man - return after getting item
  roomFour->setTeleporter(new Teleporter(13, 103, 4, 13, 144, COLOR_BLUE), 3); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(14, 103, 4, 13, 144, COLOR_BLUE), 4); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(15, 103, 4, 13, 144, COLOR_BLUE), 5); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(13, 147, 4, 13, 105, COLOR_BLUE), 6); //pac man tele: right
  roomFour->setTeleporter(new Teleporter(14, 147, 4, 13, 105, COLOR_BLUE), 7); //pac man tele: right
  roomFour->setTeleporter(new Teleporter(15, 147, 4, 13, 105, COLOR_BLUE), 8); //pac man tele: right
  //door for pac man region
  roomFour->setDoor(new Door(14, 120, -1, -1, -1, 101, true, COLOR_CYAN), 0);
  //key for logo region
  roomFour->setItem(new Key(13, 36, "Inky's Key", 101, COLOR_CYAN), 0);

  return roomFour;
}
