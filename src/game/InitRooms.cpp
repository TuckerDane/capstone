/* ..............................................
  @ file InitRooms.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */

#include "InitRooms.hpp"


Room* Game::initPuzzleRoomX()
{
  Room* roomX = new Room("rooms/generic.room");
  return roomX;
}

Room* Game::initStartRoom()
{
    Room* room = new Room("rooms/start.room");
    room->setTeleporter(new Teleporter(8, 6, 0, 8, 9, COLOR_BLUE), 0);
    room->setTeleporter(new Teleporter(8, 8, 0, 8, 5, COLOR_BLUE), 1);
    room->setTeleporter(new Teleporter(18, 15, 0, 18, 7, COLOR_BLUE), 2);
    room->setTeleporter(new Teleporter(18, 11, 0, 18, 17, COLOR_BLUE), 3);

    //TODO: teleporting to other rooms, area will go away when map layout has beenn completed	
    room->setTeleporter(new Teleporter(6, 39, 0, 2, 2, COLOR_BLUE), 4); //room 0: starting room
    room->setTeleporter(new Teleporter(6, 42, 1, 2, 2, COLOR_BLUE), 5); //room 1: pokemon gym
    room->setTeleporter(new Teleporter(6, 45, 2, 2, 2, COLOR_BLUE), 6); //room 2: Zelda blocks
    room->setTeleporter(new Teleporter(6, 48, 3, 6, 9, COLOR_BLUE), 7); //room 3: Snorlax
    room->setTeleporter(new Teleporter(8, 39, 4, 2, 2, COLOR_GREEN), 8); //room 4: pac man left side
    room->setTeleporter(new Teleporter(8, 42, 4, 14, 107, COLOR_GREEN), 9); //room 4: pac man right side
    room->setTeleporter(new Teleporter(8, 45, 5, 10, 21, COLOR_BLUE), 10); //room 5: life or death blocks
    room->setTeleporter(new Teleporter(8, 48, 6, 2, 12, COLOR_RED), 11); //room 6: bomber man (still in dev)
    room->setTeleporter(new Teleporter(10, 39, 7, 25, 2, COLOR_BLUE), 12); //room 7: Mario part 1
    room->setTeleporter(new Teleporter(10, 42, 8, 3, 3, COLOR_YELLOW), 13); //room 8: TBD
    room->setTeleporter(new Teleporter(10, 45, 9, 12, 12, COLOR_BLUE), 14); //room 9: Rodent's Revenge
    room->setTeleporter(new Teleporter(10, 48, 10, 3, 3, COLOR_BLUE), 15); //room 10: mario part 2
    room->setTeleporter(new Teleporter(12, 39, 11, 13, 78, COLOR_BLUE), 16); //room 11: end room
    room->setTeleporter(new Teleporter(12, 42, 12, 5, 2, COLOR_BLUE), 17); //room 12: invisible maze
    room->setTeleporter(new Teleporter(12, 45, 13, 9, 59, COLOR_BLUE), 18); //room 13: repair
    room->setTeleporter(new Teleporter(12, 48, 14, 8, 11, COLOR_BLUE), 19); //room 14: trophy

    //doors in the starting/tutorial room
    room->setDoor(new Door(5, 23, -1, -1, -1, 789, true, COLOR_BLUE), 0);
    room->setDoor(new Door(10, 35, -1, -1, -1, 678, true, COLOR_GREEN), 1); //TODO: replace nextroom, next x and next y with below
    room->setDoor(new Door(10, 67, 2, 2, 2, 678, true, COLOR_GREEN), 2); //TODO: delete this door

    //items
    room->setItem(new Key(4, 14, "Blue Key", 789, COLOR_BLUE), 0);
    room->setItem(new Key(18, 4, "Green Key", 678, COLOR_GREEN), 1);
    room->setItem(new Trap(5, 28), 2);
    room->setItem(new Movable(14, 5), 3);
    room->getItem(3)->setHealing(2);
    room->setItem(new Movable2(13, 11), 4);
    room->setItem(new Movable2(13, 12), 5);
    room->setItem(new Statue(3, 13, "Hint: Keys can be used to open specific locked doors."), 6);
    room->setItem(new Statue(8, 2, "Hint: Teleporters can teleport you places. "), 7);
    room->setItem(new Statue(7, 19, "Hint: Watch out for traps. They cause damage. Some items can heal you."), 8);
    room->setItem(new Statue(13, 21, "Some objects block movement, some can be moved."), 9);
    room->setItem(new Statue(2, 6, "You stare at your bed. Should you make it or go get food? You smell bacon. Yeah, food seems like the way to go!"), 10);
    room->setItem(new Statue(5, 2, "It is a bummmer your Pandora's cube broke. At least you still have a Playstation."), 11);
    room->setItem(new CubeParts(6, 2), 12);

    //enemies
    room->setEnemy(new Enemy(5, 10), 0);
    room->setEnemy(new Enemy(15, 10), 1);

    return room;
}

Room* Game::initPuzzleRoom1()
{
  Room* room = new Room("rooms/puzzle_1.room");
  room->setDoor(new Door(1, 5, 3, 12, 9, 0, false, COLOR_YELLOW), 0);
  
  room->setItem(new Potion(5, 15), 0);

  //row one of teleporters
  room->setTeleporter(new Teleporter(4, 6, 1, 15, 2, COLOR_BLUE), 0);   
  room->setTeleporter(new Teleporter(4, 18, 16, 9, 10, COLOR_BLUE), 1);   
  room->setTeleporter(new Teleporter(4, 30, 1, 15, 13, COLOR_BLUE), 2);   
  room->setTeleporter(new Teleporter(4, 41, 16, 2, 7, COLOR_BLUE), 3);   
  //row two
  room->setTeleporter(new Teleporter(11, 4, 1, 22, 25, COLOR_BLUE), 4);   
  room->setTeleporter(new Teleporter(11, 9, 16, 8, 4, COLOR_BLUE), 5);   
  room->setTeleporter(new Teleporter(11, 15, 4, 2, 2, COLOR_BLUE), 6); //pac man 1  
  room->setTeleporter(new Teleporter(11, 21, 1, 2, 2, COLOR_BLUE), 7);   
  room->setTeleporter(new Teleporter(11, 30, 1, 2, 2, COLOR_BLUE), 8);   
  room->setTeleporter(new Teleporter(11, 41, 1, 8, 2, COLOR_BLUE), 9);   
  //row three
  room->setTeleporter(new Teleporter(18, 6, 1, 22, 13, COLOR_BLUE), 10);   
  room->setTeleporter(new Teleporter(18, 15, 1, 8, 25, COLOR_BLUE), 11);   
  room->setTeleporter(new Teleporter(18, 21, 16, 3, 2, COLOR_BLUE), 12);   
  room->setTeleporter(new Teleporter(18, 27, 1, 8, 36, COLOR_BLUE), 13);   
  room->setTeleporter(new Teleporter(18, 32, 15, 2, 3, COLOR_BLUE), 14);   
  room->setTeleporter(new Teleporter(18, 38, 4, 14, 146, COLOR_BLUE), 15); //pac man 2  
  room->setTeleporter(new Teleporter(18, 44, 1, 2, 2, COLOR_BLUE), 16);   

  //row four
  room->setTeleporter(new Teleporter(25, 4, 16, 5, 4, COLOR_BLUE), 17);   
  room->setTeleporter(new Teleporter(25, 9, 1, 2, 2, COLOR_BLUE), 18);   
  room->setTeleporter(new Teleporter(25, 18, 1, 15, 25, COLOR_BLUE), 19);   
  room->setTeleporter(new Teleporter(25, 27, 1, 15, 13, COLOR_BLUE), 20);   
  room->setTeleporter(new Teleporter(25, 32, 16, 5, 11, COLOR_BLUE), 21);   
  room->setTeleporter(new Teleporter(25, 41, 1, 2, 36, COLOR_BLUE), 22);   

  return room; 
}

Room* Game::initPuzzleRoom2()
{
    Room* room = new Room("rooms/puzzle_2.room");
    room->setDoor(new Door(7, 17, 5, 10, 20, 1, true, COLOR_YELLOW), 0);
    room->setDoor(new Door(2, 1, 0, 10, 66, 678, true, COLOR_GREEN), 1);
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
    Room* room = new Room("rooms/puzzle_3.room");
    room->setDoor(new Door(6, 1, 6, 2, 12, 0, false, COLOR_YELLOW), 0);   // bomberman room
    room->setDoor(new Door(1, 9, 5, 13, 93, 0, false, COLOR_RED), 1); // life or death blocks
    room->setDoor(new Door(13, 9, 1, 2, 5, 0, false, COLOR_YELLOW), 2); // teleport room
    room->setItem(new Snorlax(6, 6), 0);
    room->setItem(new Pokeball(4, 20), 1);
    
    return room;
}

Room* Game::initPuzzleRoom4(){
  Room* room = new Room("rooms/puzzle_4.room");
  //teleporters
  room->setTeleporter(new Teleporter(11, 49, 1, 3, 6, COLOR_BLUE), 0); //logo return   
  room->setTeleporter(new Teleporter(9, 117, 12, 5, 2, COLOR_BLUE), 1); //invisible maze
  room->setTeleporter(new Teleporter(14, 126, 1, 3, 6, COLOR_BLUE), 2); //pac man - return after getting item
  room->setTeleporter(new Teleporter(13, 103, 4, 13, 146, COLOR_BLACK), 3); //pac man tele: left
  room->setTeleporter(new Teleporter(14, 103, 4, 14, 146, COLOR_BLACK), 4); //pac man tele: left
  room->setTeleporter(new Teleporter(15, 103, 4, 15, 146, COLOR_BLACK), 5); //pac man tele: left
  room->setTeleporter(new Teleporter(13, 147, 4, 13, 104, COLOR_BLACK), 6); //pac man tele: right
  room->setTeleporter(new Teleporter(14, 147, 4, 14, 104, COLOR_BLACK), 7); //pac man tele: right
  room->setTeleporter(new Teleporter(15, 147, 4, 15, 104, COLOR_BLACK), 8); //pac man tele: right
  //door for pac man region
  room->setDoor(new Door(14, 120, -1, -1, -1, 101, true, COLOR_CYAN), 0);
  //key for logo region
  room->setItem(new Key(13, 36, "Inky's Key", 101, COLOR_CYAN), 0);

  //pokeflute for room3 solution
  room->setItem(new Pokeflute(14, 123), 1);

  return room;
}

Room* Game::initPuzzleRoom5(){
    Room* room = new Room("rooms/puzzle_5.room");
    room->setDoor(new Door(10, 19, 2, 7, 16, 1, true, COLOR_YELLOW), 0);
    room->setDoor(new Door(14, 93, 3, 2, 9 , 789, true, COLOR_BLUE), 1);
    room->setDoor(new Door(10, 23, -1, -1, -1, 3, true, COLOR_MAGENTA), 2);
    room->setDoor(new Door(6, 41, -1, -1, -1, 4, true, COLOR_CYAN), 3);
    room->setItem(new Movable(7, 23, "■"), 0);
    room->getItem(0)->setColor(COLOR_GREEN);
    room->getItem(0)->setHealing(1);
    room->setItem(new Movable(13, 23, "■"), 1);
    room->getItem(1)->setColor(COLOR_RED);
    room->getItem(1)->setDamage(1);
    room->setItem(new Key(10, 33, "Cyan Key", 4, COLOR_CYAN), 2);
    room->setItem(new CubeParts(10, 45), 3);

    room->setEnemy(new Enemy(10, 35), 0);
    room->setEnemy(new Enemy(11, 36), 1);
    room->setEnemy(new Enemy(11, 37), 2);
    room->setEnemy(new Enemy(9, 38), 3);
    room->setEnemy(new Enemy(11, 39), 4);
    room->setEnemy(new Enemy(10, 40), 5);
    room->setEnemy(new Enemy(9, 41), 6);

    return room;
}

Room* Game::initPuzzleRoom6()
{
    Room* room = new Room("rooms/puzzle_6.room");    
    room->setDoor(new Door(2, 13, 3, 6, 2, -1, false, COLOR_WHITE), 0);
    room->setItem(new Bomb(2, 10), 0);
    room->setTeleporter(new Teleporter(8, 2, 11, 13, 78, COLOR_YELLOW), 0); //room 11
    int blockCounter = 1;
    for(int i= 0; i < 11; i++)
    {
        for(int j= 0; j < 9; j++)
        {
          if ( (j == 0 && i == 10) || (j == 0 && i == 8) ) // if tile is where player starts or where bomb starts
          {
            blockCounter++; 
          }
          else if (j == 2)  // if 1st row
          {
            if (i < 8)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
          else if (j == 3)  // if 2nd row
          {
            if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
          else if (j == 4 || j == 6)  // if open row
          {
            room->setItem(new Softblock(j, i+2), blockCounter++);
          }
          else if (j == 5 || j == 7) // if row with walls
          {
            if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);  
            }
          }
          else if (j == 8) // else if last row
          {
            if ( (i+2) != 2)
            {
              room->setItem(new Softblock(j, i+2), blockCounter++);
            }
          }
        }
    }
    return room;
}

Room* Game::initPuzzleRoom7()
{
    Room* room =  new Room("rooms/puzzle_7.room");
    //set traps
    room->setItem(new Trap(27, 102), 0);
    room->getItem(0)->setDamage(20);
    room->setItem(new Trap(27, 103), 1);
    room->getItem(1)->setDamage(20);
    room->setItem(new Trap(27, 104), 2);
    room->getItem(2)->setDamage(20);
    room->setItem(new Trap(27, 105), 3);
    room->getItem(3)->setDamage(20);
    //set teleporters
    room->setTeleporter(new Teleporter(25, 147, 10, 25, 2, COLOR_BLUE), 0); 
    room->setTeleporter(new Teleporter(24, 147, 10, 24, 2, COLOR_BLUE), 1); 
    room->setTeleporter(new Teleporter(23, 147, 10, 23, 2, COLOR_BLUE), 2); 
    room->setTeleporter(new Teleporter(22, 147, 10, 22, 2, COLOR_BLUE), 3); 
    room->setTeleporter(new Teleporter(21, 147, 10, 21, 2, COLOR_BLUE), 4); 
    room->setTeleporter(new Teleporter(20, 147, 10, 20, 2, COLOR_BLUE), 5); 
    room->setTeleporter(new Teleporter(19, 147, 10, 19, 2, COLOR_BLUE), 6); 
    room->setTeleporter(new Teleporter(18, 147, 10, 18, 2, COLOR_BLUE), 7); 
    room->setTeleporter(new Teleporter(17, 147, 10, 17, 2, COLOR_BLUE), 8); 
    room->setTeleporter(new Teleporter(16, 147, 10, 16, 2, COLOR_BLUE), 9); 
    room->setTeleporter(new Teleporter(15, 147, 10, 15, 2, COLOR_BLUE), 10); 
    room->setTeleporter(new Teleporter(14, 147, 10, 14, 2, COLOR_BLUE), 11); 
    room->setTeleporter(new Teleporter(13, 147, 10, 13, 2, COLOR_BLUE), 12); 
    room->setTeleporter(new Teleporter(12, 147, 10, 12, 2, COLOR_BLUE), 13); 
    room->setTeleporter(new Teleporter(11, 147, 10, 11, 2, COLOR_BLUE), 14); 
    room->setTeleporter(new Teleporter(10, 147, 10, 10, 2, COLOR_BLUE), 15); 
    room->setTeleporter(new Teleporter(9, 147, 10, 9, 2, COLOR_BLUE), 16); 
    room->setTeleporter(new Teleporter(8, 147, 10, 8, 2, COLOR_BLUE), 17); 
    room->setTeleporter(new Teleporter(7, 147, 10, 7, 2, COLOR_BLUE), 18); 
    room->setTeleporter(new Teleporter(6, 147, 10, 6, 2, COLOR_BLUE), 19); 
    room->setTeleporter(new Teleporter(5, 147, 10, 5, 2, COLOR_BLUE), 20); 
    room->setTeleporter(new Teleporter(4, 147, 10, 4, 2, COLOR_BLUE), 21); 
    room->setTeleporter(new Teleporter(3, 147, 10, 3, 2, COLOR_BLUE), 22); 
    room->setTeleporter(new Teleporter(2, 147, 10, 2, 2, COLOR_BLUE), 23); 

    return room;
}

Room* Game::initPuzzleRoom8() {
    Room* room = new Room("rooms/puzzle_8.room");
//    room->setItem(new Movable2(4, 6, "o"), 0);
//    room->setItem(new Movable2(4, 8, "o"), 1);
//    room->setItem(new Movable2(4, 10, "o"), 2);
//    room->setItem(new Movable2(4, 12, "o"), 3);
//    room->setItem(new Movable2(4, 14, "o"), 4);
//    room->setItem(new Movable(6, 5, "●"), 5);
//    room->setItem(new Movable(6, 7, "●"), 6);
//    room->setItem(new Movable(6, 9, "●"), 7);
//    room->setItem(new Movable(6, 11, "●"), 8);
//    room->setItem(new Movable(6, 13, "●"), 9);
//    room->setDoor(new Door(1, 13, 9, 21, 11, 0, false, COLOR_WHITE), 0);
//    room->setDoor(new Door(6, 30, 7, 25, 2, 0, false, COLOR_WHITE), 1);
    return room;
}

Room* Game::initPuzzleRoom9(){
    Room* room = new Room("rooms/puzzle_9.room");
    room->setDoor(new Door(7, 1, 9, 12, 12, 0, false, COLOR_WHITE), 0);     
    room->setDoor(new Door(7, 23, 11, 14, 61, 9121998, true, COLOR_WHITE), 1);    //leads to previous room
    room->setDoor(new Door(16, 1, 9, 12, 12, 0, false, COLOR_WHITE), 2); 
    room->setDoor(new Door(16, 23, 7, 25, 12, 0, false, COLOR_WHITE), 3);   //leads to mario part 1
    room->setDoor(new Door(1, 11, 9, 12, 12, 0, false, COLOR_WHITE), 4);
    room->setDoor(new Door(22, 11, 9, 12, 12, 0, false, COLOR_WHITE), 5);     
    room->setEnemy(new Enemy(2, 2), 0); //top left
    room->setEnemy(new Enemy(20, 16), 1); //bottom right
    room->setEnemy(new Enemy(18, 2), 2);  //bottom left
    room->setEnemy(new Enemy(2, 20), 3); //top right
    
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

    room->setItem(new Key(20, 21, "white key", 9121998, COLOR_WHITE), 225);
    return room;
}

Room* Game::initPuzzleRoom10()
{
    Room* room = new Room("rooms/puzzle_10.room");

    room->setItem(new Trap(27, 52), 0);
    room->getItem(0)->setDamage(20);
    room->setItem(new Trap(27, 53), 1);
    room->getItem(1)->setDamage(20);
    room->setItem(new Trap(27, 54), 2);
    room->getItem(2)->setDamage(20);
    room->setItem(new Trap(27, 55), 3);
    room->getItem(3)->setDamage(20);
    room->setItem(new Trap(27, 56), 4);
    room->getItem(4)->setDamage(20);
    room->setItem(new Trap(27, 57), 5);
    room->getItem(5)->setDamage(20);

    //teleporters to go back to room 7
    room->setTeleporter(new Teleporter(2, 2, 7, 2, 147, COLOR_BLUE), 0); 
    room->setTeleporter(new Teleporter(3, 2, 7, 3, 147, COLOR_BLUE), 1); 
    room->setTeleporter(new Teleporter(4, 2, 7, 4, 147, COLOR_BLUE), 2); 
    room->setTeleporter(new Teleporter(5, 2, 7, 5, 147, COLOR_BLUE), 3); 
    room->setTeleporter(new Teleporter(6, 2, 7, 6, 147, COLOR_BLUE), 4); 
    room->setTeleporter(new Teleporter(7, 2, 7, 7, 147, COLOR_BLUE), 5); 
    room->setTeleporter(new Teleporter(8, 2, 7, 8, 147, COLOR_BLUE), 6); 
    room->setTeleporter(new Teleporter(9, 2, 7, 9, 147, COLOR_BLUE), 7); 
    room->setTeleporter(new Teleporter(10, 2, 7, 10, 147, COLOR_BLUE), 8); 
    room->setTeleporter(new Teleporter(11, 2, 7, 11, 147, COLOR_BLUE), 9); 
    room->setTeleporter(new Teleporter(12, 2, 7, 12, 147, COLOR_BLUE), 10); 
    room->setTeleporter(new Teleporter(13, 2, 7, 13, 147, COLOR_BLUE), 11); 
    room->setTeleporter(new Teleporter(14, 2, 7, 14, 147, COLOR_BLUE), 12); 
    room->setTeleporter(new Teleporter(15, 2, 7, 15, 147, COLOR_BLUE), 13); 
    room->setTeleporter(new Teleporter(16, 2, 7, 16, 147, COLOR_BLUE), 14); 
    room->setTeleporter(new Teleporter(17, 2, 7, 17, 147, COLOR_BLUE), 15); 
    room->setTeleporter(new Teleporter(18, 2, 7, 18, 147, COLOR_BLUE), 16); 
    room->setTeleporter(new Teleporter(19, 2, 7, 19, 147, COLOR_BLUE), 17); 
    room->setTeleporter(new Teleporter(20, 2, 7, 20, 147, COLOR_BLUE), 18); 
    room->setTeleporter(new Teleporter(21, 2, 7, 21, 147, COLOR_BLUE), 19); 
    room->setTeleporter(new Teleporter(22, 2, 7, 22, 147, COLOR_BLUE), 20); 
    room->setTeleporter(new Teleporter(23, 2, 7, 23, 147, COLOR_BLUE), 21); 
    room->setTeleporter(new Teleporter(24, 2, 7, 24, 147, COLOR_BLUE), 22); 
    room->setTeleporter(new Teleporter(25, 2, 7, 25, 147, COLOR_BLUE), 23); 

    //flag teleporters to finish the room
    room->setTeleporter(new Teleporter(24, 143, 13, 14, 58, COLOR_BLUE), 24); 
    room->setTeleporter(new Teleporter(23, 143, 13, 14, 58, COLOR_BLUE), 25); 
    room->setTeleporter(new Teleporter(22, 143, 13, 14, 58, COLOR_BLUE), 26); 
    room->setTeleporter(new Teleporter(21, 143, 13, 14, 58, COLOR_BLUE), 27); 
    room->setTeleporter(new Teleporter(20, 143, 13, 14, 58, COLOR_BLUE), 28); 
    room->setTeleporter(new Teleporter(19, 143, 13, 14, 58, COLOR_BLUE), 29); 
    room->setTeleporter(new Teleporter(18, 143, 13, 14, 58, COLOR_BLUE), 31); 
    room->setTeleporter(new Teleporter(17, 143, 13, 14, 58, COLOR_BLUE), 32); 
    room->setTeleporter(new Teleporter(16, 143, 13, 14, 58, COLOR_BLUE), 33); 
    room->setTeleporter(new Teleporter(15, 143, 13, 14, 58, COLOR_BLUE), 34); 

    room->setTeleporter(new Teleporter(14, 143, 13, 14, 58, COLOR_BLUE), 35); 
    room->setTeleporter(new Teleporter(13, 143, 13, 14, 58, COLOR_BLUE), 36); 
    room->setTeleporter(new Teleporter(12, 143, 13, 14, 58, COLOR_BLUE), 37); 
    room->setTeleporter(new Teleporter(11, 143, 13, 14, 58, COLOR_BLUE), 38); 
    room->setTeleporter(new Teleporter(24, 145, 13, 14, 58, COLOR_BLUE), 39); 
    room->setTeleporter(new Teleporter(23, 145, 13, 14, 58, COLOR_BLUE), 40); 
    room->setTeleporter(new Teleporter(22, 145, 13, 14, 58, COLOR_BLUE), 41); 
    room->setTeleporter(new Teleporter(21, 145, 13, 14, 58, COLOR_BLUE), 42); 
    room->setTeleporter(new Teleporter(20, 145, 13, 14, 58, COLOR_BLUE), 43); 
    room->setTeleporter(new Teleporter(19, 145, 13, 14, 58, COLOR_BLUE), 44); 

    room->setTeleporter(new Teleporter(18, 145, 13, 14, 58, COLOR_BLUE), 45); 
    room->setTeleporter(new Teleporter(17, 145, 13, 14, 58, COLOR_BLUE), 46); 
    room->setTeleporter(new Teleporter(16, 145, 13, 14, 58, COLOR_BLUE), 47); 
    room->setTeleporter(new Teleporter(15, 145, 13, 14, 58, COLOR_BLUE), 48); 
    room->setTeleporter(new Teleporter(14, 145, 13, 14, 58, COLOR_BLUE), 49); 
    room->setTeleporter(new Teleporter(13, 145, 13, 14, 58, COLOR_BLUE), 50); 
    room->setTeleporter(new Teleporter(12, 145, 13, 14, 58, COLOR_BLUE), 51); 
    room->setTeleporter(new Teleporter(11, 145, 13, 14, 58, COLOR_BLUE), 52); 
    room->setTeleporter(new Teleporter(10, 145, 13, 14, 58, COLOR_BLUE), 53); 
    room->setTeleporter(new Teleporter(9, 145, 13, 14, 58, COLOR_BLUE), 54); 

    room->setTeleporter(new Teleporter(8, 145, 13, 14, 58, COLOR_BLUE), 55); 
    room->setTeleporter(new Teleporter(7, 145, 13, 14, 58, COLOR_BLUE), 56); 
    room->setTeleporter(new Teleporter(6, 145, 13, 14, 58, COLOR_BLUE), 57); 
    room->setTeleporter(new Teleporter(5, 145, 13, 14, 58, COLOR_BLUE), 58); 
    room->setTeleporter(new Teleporter(10, 142, 13, 14, 58, COLOR_BLUE), 59); 
    room->setTeleporter(new Teleporter(9, 141, 13, 14, 58, COLOR_BLUE), 60); 
    room->setTeleporter(new Teleporter(8, 140, 13, 14, 58, COLOR_BLUE), 61); 
    room->setTeleporter(new Teleporter(7, 139, 13, 14, 58, COLOR_BLUE), 62); 
    room->setTeleporter(new Teleporter(6, 138, 13, 14, 58, COLOR_BLUE), 63); 
    room->setTeleporter(new Teleporter(5, 138, 13, 14, 58, COLOR_BLUE), 64); 

    room->setTeleporter(new Teleporter(5, 139, 13, 14, 58, COLOR_BLUE), 65); 
    room->setTeleporter(new Teleporter(5, 140, 13, 14, 58, COLOR_BLUE), 66); 
    room->setTeleporter(new Teleporter(5, 141, 13, 14, 58, COLOR_BLUE), 67); 
    room->setTeleporter(new Teleporter(5, 142, 13, 14, 58, COLOR_BLUE), 68); 
    room->setTeleporter(new Teleporter(5, 143, 13, 14, 58, COLOR_BLUE), 69); 
    room->setTeleporter(new Teleporter(5, 144, 13, 14, 58, COLOR_BLUE), 70); 
    return room;
}

Room* Game::initPuzzleRoom11()
{
  Room* room = new Room("rooms/puzzle_11.room");
  room->setTeleporter(new Teleporter(12, 78, 6, 2, 12, COLOR_WHITE), 0);
  room->setDoor(new Door(14, 60, 9, 2, 23, 9121998, true, COLOR_WHITE), 0); //to rodents/locked and needs key from rodents to open
  room->setTeleporter(new Teleporter(15, 61, 9, 12, 12, COLOR_BLUE), 1); //if aabovee door is used tele to middle of RRevenge

  //Trap COLUMN 1 (reading from left to right)
  room->setItem(new Trap(13, 63), 0);
  room->getItem(0)->setDamage(0);
  room->getItem(0)->setWeight(1000);

  room->setItem(new Trap(14, 63), 1);
  room->getItem(1)->setDamage(1);
  room->getItem(1)->setWeight(1000);

  room->setItem(new Trap(15, 63), 2);
  room->getItem(2)->setDamage(3);
  room->getItem(2)->setWeight(1000);

  //Trap COLUMN 2 (reading from left to right)
  room->setItem(new Trap(13, 65), 3);   //Top
  room->getItem(3)->setDamage(3);
  room->getItem(3)->setWeight(1000);

  room->setItem(new Trap(14, 65), 4);   //Left
  room->getItem(4)->setDamage(1);
  room->getItem(4)->setWeight(1000);

  room->setItem(new Trap(15, 65), 5);   //Middle
  room->getItem(5)->setDamage(0);
  room->getItem(5)->setWeight(1000);

  //Trap COLUMN 3 (reading from left to right)
  room->setItem(new Trap(13, 67), 6);
  room->getItem(6)->setDamage(1);
  room->getItem(6)->setWeight(1000);

  room->setItem(new Trap(14, 67), 7);
  room->getItem(7)->setDamage(0);
  room->getItem(7)->setWeight(1000);

  room->setItem(new Trap(15, 67), 8);
  room->getItem(8)->setDamage(3);
  room->getItem(8)->setWeight(1000);

  //Trap COLUMN 4 (reading from left to right)
  room->setItem(new Trap(13, 69), 9);
  room->getItem(9)->setDamage(3);
  room->getItem(9)->setWeight(1000);

  room->setItem(new Trap(14, 69), 10);
  room->getItem(10)->setDamage(0);
  room->getItem(10)->setWeight(1000);

  room->setItem(new Trap(15, 69), 11);
  room->getItem(11)->setDamage(1);
  room->getItem(11)->setWeight(1000);

  //Trap COLUMN 5 (reading from left to right)
  room->setItem(new Trap(13, 71), 12);
  room->getItem(12)->setDamage(0);
  room->getItem(12)->setWeight(1000);

  room->setItem(new Trap(14, 71), 13);
  room->getItem(13)->setDamage(3);
  room->getItem(13)->setWeight(1000);

  room->setItem(new Trap(15, 71), 14);
  room->getItem(14)->setDamage(1);
  room->getItem(14)->setWeight(1000);

  //Trap COLUMN 6 (reading from left to right)
  room->setItem(new Trap(13, 73), 15);
  room->getItem(15)->setDamage(1);
  room->getItem(15)->setWeight(1000);

  room->setItem(new Trap(14, 73), 16);
  room->getItem(16)->setDamage(0);
  room->getItem(16)->setWeight(1000);

  room->setItem(new Trap(15, 73), 17);
  room->getItem(17)->setDamage(3);
  room->getItem(17)->setWeight(1000);

  //Trap COLUMN 7 (reading from left to right)
  room->setItem(new Trap(13, 75), 18);
  room->getItem(18)->setDamage(3);
  room->getItem(18)->setWeight(1000);

  room->setItem(new Trap(14, 75), 19);
  room->getItem(19)->setDamage(0);
  room->getItem(19)->setWeight(1000);

  room->setItem(new Trap(15, 75), 20);
  room->getItem(20)->setDamage(1);
  room->getItem(20)->setWeight(1000);

  //Trap COLUMN 8 (reading from left to right)
  room->setItem(new Trap(13, 77), 21);
  room->getItem(21)->setDamage(0);
  room->getItem(21)->setWeight(1000);

  room->setItem(new Trap(14, 77), 22);
  room->getItem(22)->setDamage(0);
  room->getItem(22)->setWeight(1000);

  room->setItem(new Trap(15, 77), 23);
  room->getItem(23)->setDamage(0);
  room->getItem(23)->setWeight(1000);


  return room;
}

Room* Game::initPuzzleRoom12()
{
  Room* room = new Room("rooms/puzzle_12.room");
  room->setDoor(new Door(5, 28, 1, 2, 2, 0, false, COLOR_WHITE), 0); // to room1
  
  //set maze "walls"

  //row1
  room->setItem(new Immovable(2, 3), 0);
  room->setItem(new Immovable(2, 7), 1);
  room->setItem(new Immovable(2, 8), 2);
  room->setItem(new Immovable(2, 9), 3);
  room->setItem(new Immovable(2, 10), 4);
  room->setItem(new Immovable(2, 11), 5);

  //row2
  room->setItem(new Immovable(3, 3), 6);
  room->setItem(new Immovable(3, 5), 7);
  room->setItem(new Immovable(3, 11), 8);
  room->setItem(new Immovable(3, 17), 9);
  room->setItem(new Immovable(3, 18), 10);
  room->setItem(new Immovable(3, 19), 11);
  room->setItem(new Immovable(3, 23), 12);
  room->setItem(new Immovable(3, 24), 13);
  room->setItem(new Immovable(3, 25), 14);
  room->setItem(new Immovable(3, 26), 15);
  room->setItem(new Immovable(3, 27), 16);

  //row3
  room->setItem(new Immovable(4, 2), 17);
  room->setItem(new Immovable(4, 3), 18);
  room->setItem(new Immovable(4, 5), 19);
  room->setItem(new Immovable(4, 5), 20);
  room->setItem(new Immovable(4, 6), 21);
  room->setItem(new Immovable(4, 7), 22);
  room->setItem(new Immovable(4, 8), 23);
  room->setItem(new Immovable(4, 9), 24);
  room->setItem(new Immovable(4, 11), 25);
  room->setItem(new Immovable(4, 17), 26);
  room->setItem(new Immovable(4, 19), 27);
  room->setItem(new Immovable(4, 23), 28);

  //row4
  room->setItem(new Immovable(5, 5), 29);
  room->setItem(new Immovable(5, 9), 30);
  room->setItem(new Immovable(5, 11), 31);
  room->setItem(new Immovable(5, 12), 32);
  room->setItem(new Immovable(5, 13), 33);
  room->setItem(new Immovable(5, 14), 34);
  room->setItem(new Immovable(5, 15), 35);
  room->setItem(new Immovable(5, 16), 36);
  room->setItem(new Immovable(5, 17), 37);
  room->setItem(new Immovable(5, 19), 38);
  room->setItem(new Immovable(5, 23), 39);
  room->setItem(new Immovable(5, 25), 40);

  //row5
  room->setItem(new Immovable(6, 2), 41);
  room->setItem(new Immovable(6, 3), 42);
  room->setItem(new Immovable(6, 5), 43);
  room->setItem(new Immovable(6, 9), 44);
  room->setItem(new Immovable(6, 19), 45);
  room->setItem(new Immovable(6, 23), 46);
  room->setItem(new Immovable(6, 19), 47);
  room->setItem(new Immovable(6, 25), 48);
  room->setItem(new Immovable(6, 26), 49);
  room->setItem(new Immovable(6, 27), 50);

  //row6
  room->setItem(new Immovable(7, 3), 51);
  room->setItem(new Immovable(7, 5), 52);
  room->setItem(new Immovable(7, 9), 53);
  room->setItem(new Immovable(7, 10), 54);
  room->setItem(new Immovable(7, 11), 55);
  room->setItem(new Immovable(7, 12), 56);
  room->setItem(new Immovable(7, 13), 57);
  room->setItem(new Immovable(7, 14), 58);
  room->setItem(new Immovable(7, 15), 59);
  room->setItem(new Immovable(7, 16), 60);
  room->setItem(new Immovable(7, 17), 61);
  room->setItem(new Immovable(7, 19), 62);
  room->setItem(new Immovable(7, 20), 63);
  room->setItem(new Immovable(7, 21), 64);
  room->setItem(new Immovable(7, 22), 65);
  room->setItem(new Immovable(7, 23), 66);
  room->setItem(new Immovable(7, 25), 67);

  //row7
  room->setItem(new Immovable(8, 3), 68);
  room->setItem(new Immovable(8, 5), 69);
  room->setItem(new Immovable(8, 17), 70);
  
  // for loop for attributes
  for(int i=0; i <= 70; i++)
  {
    room->getItem(i)->setWeight(1000);
    room->getItem(i)->setColor(COLOR_BLACK);
  }

  return room;
}

Room* Game::initPuzzleRoom13()
{
    Room* room = new Room("rooms/repair_13.room");
    room->setTeleporter(new Teleporter(9, 71, 14, 8, 11, COLOR_BLUE), 0); // trophy room
    room->setItem(new Profoak(4, 58), 0);
    room->setItem(new Statue(9, 58, "Repair Station: Used to repair the Pandora's Cube."), 1);

    return room;
}

Room* Game::initPuzzleRoom14()
{
    Room* room = new Room("rooms/trophy.room");
    room->setItem(new Statue(5, 5, "Pokemon, Snorlax Encounter"), 0);
    room->setItem(new Statue(5, 7, "Legend of Zelda: Link to the Past, Block Puzzle"), 1);
    room->setItem(new Statue(5, 9, "Pokemon, Saffron Gym"), 2);
    room->setItem(new Statue(5, 11, "Pac-Man"), 3);
    room->setItem(new Statue(5, 13, "Rodent's Revenge"), 4);

    return room;
}

Room* Game::initEndRoom()
{
    Room* room = new Room("rooms/trophy.room");
    room->setItem(new Statue(5, 5, "Pokemon, Snorlax Encounter"), 0);
    room->setItem(new Statue(5, 7, "Legend of Zelda: Link to the Past, Block Puzzle"), 1);
    room->setItem(new Statue(5, 9, "Pokemon, Saffron Gym"), 2);
    room->setItem(new Statue(5, 11, "Pac-Man"), 3);
    room->setItem(new Statue(5, 13, "Rodent's Revenge"), 4);

    return room;
}

Room* Game::initExtraRoom1()
{
    Room* room = new Room("rooms/extra_1.room");
    room->setItem(new Movable2(4, 4, "●"), 0);
    room->setItem(new Movable2(6, 5, "●"), 1);
    room->setItem(new Movable2(4, 7, "●"), 2);
    room->setItem(new Movable2(2, 8, "●"), 3);
    room->setItem(new Movable2(4, 10, "●"), 4);

    room->setItem(new Movable2(6, 11, "●"), 5);
    room->setItem(new Movable2(4, 13, "●"), 6);
    room->setItem(new Movable2(2, 14, "●"), 7);
    room->setItem(new Movable2(4, 16, "●"), 8);
    room->setItem(new Movable2(6, 17, "●"), 9);

    room->setItem(new Movable2(4, 19, "●"), 10);
    room->setItem(new Movable2(2, 20, "●"), 11);
    room->setItem(new Movable2(4, 22, "●"), 12);
    room->setItem(new Movable2(6, 23, "●"), 13);
    room->setItem(new Movable2(5, 25, "●"), 14);

    room->setItem(new Movable2(4, 25, "●"), 15);
    room->setItem(new Movable2(4, 27, "●"), 16);
    room->setItem(new Movable2(3, 24, "●"), 17);
    room->setItem(new Movable2(3, 26, "●"), 18);
    room->setItem(new CubeParts(2, 25), 19);
  
    room->setTeleporter(new Teleporter(2, 26, 1, 5, 18, COLOR_BLUE), 0); 
    return room;
}

Room* Game::initExtraRoom2()
{
    Room* room = new Room("rooms/extra_2.room");
    room->setTeleporter(new Teleporter(2, 2, 1, 2, 2, COLOR_BLUE), 0);
    room->setTeleporter(new Teleporter(2, 12, 1, 2, 13, COLOR_BLUE), 1);
    room->setTeleporter(new Teleporter(5, 2, 1, 15, 36, COLOR_BLUE), 2);
    room->setTeleporter(new Teleporter(6, 12, 1, 8, 13, COLOR_BLUE), 3);
    room->setTeleporter(new Teleporter(9, 2, 1, 2, 36, COLOR_BLUE), 4);
    room->setTeleporter(new Teleporter(9, 7, 1, 22, 2, COLOR_BLUE), 5);
    room->setTeleporter(new Teleporter(9, 12, 1, 2, 2, COLOR_BLUE), 6);
 
    //middle hallway
    room->setItem(new Trap(3, 7), 0);
    room->getItem(0)->setWeight(1000);

    room->setItem(new Trap(4, 7), 1);
    room->getItem(1)->setWeight(1000);

    room->setItem(new Trap(5, 7), 2);
    room->getItem(2)->setWeight(1000);

    room->setItem(new Trap(6, 7), 3);
    room->getItem(3)->setWeight(1000);

    room->setItem(new Trap(7, 7), 4);
    room->getItem(4)->setWeight(1000);

    room->setItem(new Trap(8, 7), 5);
    room->getItem(5)->setWeight(1000);

    //side rooms
    room->setItem(new Potion(2, 11), 6);
    room->getItem(6)->setWeight(1000);

    room->setItem(new Potion(5, 3), 7);
    room->getItem(7)->setWeight(1000);

    room->setItem(new Potion(9, 11), 8);
    room->getItem(8)->setWeight(1000);

    room->setItem(new Trap(2, 3), 9);
    room->getItem(9)->setDamage(2);
    room->getItem(9)->setWeight(1000);

    room->setItem(new Trap(5, 12), 10);
    room->getItem(10)->setDamage(2);
    room->getItem(10)->setWeight(1000);

    room->setItem(new Trap(8, 2), 11);
    room->getItem(11)->setDamage(2);
    room->getItem(11)->setWeight(1000);

    room->setItem(new CubeParts(3, 4), 12);
    room->setItem(new CubeParts(8, 10), 13);

    return room;
}
