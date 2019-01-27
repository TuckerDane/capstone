/* ..............................................
  @file Door.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#include "Door.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Door::Door() : Object(-1, -1, COLOR_BLACK, '#', "door_object", "door", "Door: an opening between adjacent rooms")
{
    this->nextRoom = -1;
    this->nextDoor = -1;
    this->password = -1;
    this->locked = false;
}

Door::Door(int yPos, int xPos, int nextRoom, int nextDoor, int password, bool locked, int color) : Object()
{
    this->yPos = yPos;
    this->xPos = xPos;
    this->nextRoom = nextRoom;
    this->nextDoor = nextDoor;
    this->password = password;
    this->locked = locked;
    this->color = color;
    if (locked)
    {
        this->symbol = '#';
    }
    else
    {
        this->symbol = ' ';
    }
}

Door::~Door()
{
}

/* ..............................................
  SETTERS
  
.............................................. */
void Door::setNextRoom(int nextRoom)
{
    this->nextRoom = nextRoom;
}

void Door::setNextDoor(int nextDoor)
{
    this->nextDoor = nextDoor;
}

void Door::setPassword(int password)
{
    this->password = password;
}

void Door::setLocked(bool locked)
{
    this->locked = locked;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Door::getNextRoom()
{
    return this->nextRoom;
}

int Door::getNextDoor()
{
    return this->nextDoor;
}

int Door::getPassword()
{
    return this->password;
}

bool Door::getLocked()
{
    return this->locked;
}