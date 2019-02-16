/* ..............................................
  @file Door.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#include "Door.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Door::Door() : Object(-1, -1, COLOR_BLACK, "#", "door_object", "door", "Door: an opening between adjacent rooms")
{
    nextRoom = -1;
    nextYPos = -1;
    nextXPos = -1;
    password = -1;
    locked = false;
} 

Door::Door(int yPos, int xPos, int nextRoom, int nextYPos, int nextXPos, int password, bool locked, int color) : Object()
{
    this->yPos = yPos;
    this->xPos = xPos;
    this->nextRoom = nextRoom;
    this->nextYPos = nextYPos;
    this->nextXPos = nextXPos;
    this->password = password;
    this->locked = locked;
    this->color = color;
    if (locked)
    {
        this->symbol = "#";
    }
    else
    {
        this->symbol = " ";
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

void Door::setNextYPos(int nextYPos)
{
    this->nextYPos = nextYPos;
}

void Door::setNextXPos(int nextXPos)
{
    this->nextXPos = nextXPos;
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
    return nextRoom;
}

int Door::getNextYPos()
{
    return nextYPos;
}

int Door::getNextXPos()
{
    return nextXPos;
}

int Door::getPassword()
{
    return password;
}

bool Door::getLocked()
{
    return locked;
}