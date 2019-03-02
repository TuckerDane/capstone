#include "InitRooms.hpp"
Room* Game::initPuzzleRoomX()
{
  Room* roomX = new Room("rooms/generic.room");
  return roomX;
}

Room* Game::initStartRoom()
{
    Room* room = new Room("rooms/start.room");
    room->setTeleporter(new Teleporter(5, 4, 0, 5, 9, COLOR_BLUE), 0);
    room->setTeleporter(new Teleporter(18, 15, 0, 18, 7, COLOR_BLUE), 1);
    room->setTeleporter(new Teleporter(18, 11, 0, 18, 17, COLOR_BLUE), 2);

    //teleporting to other rooms, area will go away when map layout has beenn completed	
    room->setTeleporter(new Teleporter(6, 39, 2, 3, 3, COLOR_BLUE), 3); //room 2
    room->setTeleporter(new Teleporter(6, 43, 8, 3, 3, COLOR_BLUE), 4); //room 8
    room->setTeleporter(new Teleporter(6, 47, 9, 12, 12, COLOR_BLUE), 5); //room 9
    room->setTeleporter(new Teleporter(8, 40, 1, 2, 2, COLOR_BLUE), 6); //room 1
    room->setTeleporter(new Teleporter(8, 44, 4, 2, 2, COLOR_BLUE), 7); //room 4

    //doors in the starting/tutorial room
    room->setDoor(new Door(5, 23, -1, -1, -1, 789, true, COLOR_BLUE), 0);
    room->setDoor(new Door(10, 35, -1, -1, -1, 678, true, COLOR_GREEN), 1);
    room->setItem(new Key(4, 14, "Blue Key", 789, COLOR_BLUE), 0);
    room->setItem(new Key(18, 4, "Green Key", 678, COLOR_GREEN), 1);

    //various items
    room->setItem(new Trap(5, 28), 2);
    room->setItem(new Potion(17, 19), 3);
    room->setItem(new Movable(14, 5), 4);
    room->setItem(new Movable2(13, 11), 5);
    room->setItem(new Movable2(13, 12), 6);
    return room;
}

Room* Game::initPuzzleRoom1()
{
  Room* roomOne = new Room("rooms/puzzle_1.room");
  //row one of teleporters
  roomOne->setTeleporter(new Teleporter(4, 4, 1, 4, 18, COLOR_BLUE), 0);   
  roomOne->setTeleporter(new Teleporter(4, 9, 1, 18, 7, COLOR_BLUE), 1);   
  roomOne->setTeleporter(new Teleporter(4, 15, 1, 18, 30, COLOR_BLUE), 2);   
  roomOne->setTeleporter(new Teleporter(4, 21, 1, 18, 18, COLOR_BLUE), 3);   
  roomOne->setTeleporter(new Teleporter(4, 27, 1, 18, 18, COLOR_BLUE), 4);   
  roomOne->setTeleporter(new Teleporter(4, 32, 1, 18, 30, COLOR_BLUE), 5);   
  //row two
  roomOne->setTeleporter(new Teleporter(11, 4, 1, 4, 7, COLOR_BLUE), 6);   
  roomOne->setTeleporter(new Teleporter(11, 9, 1, 5, 30, COLOR_BLUE), 7);   
  roomOne->setTeleporter(new Teleporter(11, 15, 4, 4, 40, COLOR_GREEN), 8);   
  roomOne->setTeleporter(new Teleporter(11, 21, 4, 14, 104, COLOR_GREEN), 9);   
  roomOne->setTeleporter(new Teleporter(11, 27, 1, 11, 7, COLOR_BLUE), 10);   
  roomOne->setTeleporter(new Teleporter(11, 32, 1, 4, 18, COLOR_BLUE), 11);   
  //row three
  roomOne->setTeleporter(new Teleporter(18, 4, 1, 4, 30, COLOR_BLUE), 12);   
  roomOne->setTeleporter(new Teleporter(18, 9, 1, 11, 30, COLOR_BLUE), 13);   
  roomOne->setTeleporter(new Teleporter(18, 15, 1, 11, 30, COLOR_BLUE), 14);   
  roomOne->setTeleporter(new Teleporter(18, 21, 1, 18, 7, COLOR_BLUE), 15);   
  roomOne->setTeleporter(new Teleporter(18, 27, 1, 11, 18, COLOR_BLUE), 16);   
  roomOne->setTeleporter(new Teleporter(18, 32, 1, 4, 7, COLOR_BLUE), 17);   

  return roomOne; 
}

Room* Game::initPuzzleRoom2()
{
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

Room* Game::initPuzzleRoom3()
{
    Room* roomPuzzle3 = new Room("rooms/puzzle_3.room");
    roomPuzzle3->setDoor(new Door(6, 1, 0, 2, 2, 0, false, COLOR_YELLOW), 0);   // TODO: update door destination
    roomPuzzle3->setDoor(new Door(1, 9, 0, 2, 2, 0, false, COLOR_YELLOW), 1); // TODO: update door destination
    roomPuzzle3->setDoor(new Door(13, 9, 0, 2, 2, 0, false, COLOR_YELLOW), 2); // TODO: update door destination
    roomPuzzle3->setItem(new Snorlax(6, 6), 0);
    roomPuzzle3->setItem(new Pokeball(4, 20), 2);
    
    //Door(int yPos, int xPos, int nextRoom, int nextYPos, int nextXPos, int password, bool locked, int color);
    return roomPuzzle3;
}

Room* Game::initPuzzleRoom4(){
  Room* roomFour = new Room("rooms/puzzle_4.room");
  //teleporters
  roomFour->setTeleporter(new Teleporter(11, 49, 1, 3, 6, COLOR_BLUE), 0); //logo return   
  roomFour->setTeleporter(new Teleporter(9, 117, 1, 17, 6, COLOR_BLUE), 1); //preventing user from getting trapped in pac man region
  roomFour->setTeleporter(new Teleporter(14, 126, 1, 3, 6, COLOR_BLUE), 2); //pac man - return after getting item
  roomFour->setTeleporter(new Teleporter(13, 103, 4, 13, 146, COLOR_BLACK), 3); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(14, 103, 4, 14, 146, COLOR_BLACK), 4); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(15, 103, 4, 15, 146, COLOR_BLACK), 5); //pac man tele: left
  roomFour->setTeleporter(new Teleporter(13, 147, 4, 13, 104, COLOR_BLACK), 6); //pac man tele: right
  roomFour->setTeleporter(new Teleporter(14, 147, 4, 14, 104, COLOR_BLACK), 7); //pac man tele: right
  roomFour->setTeleporter(new Teleporter(15, 147, 4, 15, 104, COLOR_BLACK), 8); //pac man tele: right
  //door for pac man region
  roomFour->setDoor(new Door(14, 120, -1, -1, -1, 101, true, COLOR_CYAN), 0);
  //key for logo region
  roomFour->setItem(new Key(13, 36, "Inky's Key", 101, COLOR_CYAN), 0);

  return roomFour;
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

Room* Game::initPuzzleRoom6(){
    Room* room = new Room("rooms/puzzle_6.room");
    room->setDoor(new Door(1, 2, 0, 2, 2, -1, false, COLOR_WHITE), 0);
    room->setItem(new Bomb(3, 2), 0);

    int blockCounter = 0;
    for(int i= 0; i < 15; i++)
    {
        for(int j= 0; j < 13; j++)
        {
          if ( (j == 0 && i == 0) || (j == 1 && i == 0) ) // if tile is where player starts or where bomb starts
          {
            blockCounter++; 
          }
          else if (j == 2)  // if 1st row
          {
            if (i >= 1 )
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
          else if (j == 3)  // if 2nd row
          {
            if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
          else if (j == 4 || j == 6 || j == 8 || j == 10 || j == 12)  // if open row
          {
            room->setItem(new Softblock(j, i+2), blockCounter++);
          }
          else if (j == 5 || j == 7 || j == 9 || j == 11) // if row with walls
          {
            if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
        }
    }
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

Room* Game::initPuzzleRoom9(){
    Room* room = new Room("rooms/puzzle_9.room");
    room->setDoor(new Door(4, 1, 9, 12, 12, 0, false, COLOR_WHITE), 0);     // DOOR LOCKED CAN BE CHANGED FOR MAPPING PURPOSES

    int blockCounter = 0;
    for(int i= 0; i < 15; i++)
    {
        for(int j= 0; j < 15; j++)
        {
            if (i == 7)
            {
                if (j != 7)
               {
                room->setItem(new Movable2(i+5, j+5, "█"), blockCounter);
                room->getItem(blockCounter++)->setColor(COLOR_GREEN);
                }
            }
            else
            {
                room->setItem(new Movable2(i+5, j+5, "█"), blockCounter);
                room->getItem(blockCounter++)->setColor(COLOR_GREEN);
            }  
        }
    }
    return room;
}