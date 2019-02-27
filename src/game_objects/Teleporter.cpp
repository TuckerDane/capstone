/* ..............................................
  @file Teleporter.cpp
  @brief 
  @date 2019-02-20
  
  
.............................................. */
#include "Teleporter.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Teleporter::Teleporter() : Object(-1, -1, COLOR_BLACK, "H", "teleporter_object", "teleporter", "A teleporter. Where will it go?")
{
    nextRoom = -1;
    nextYPos = -1;
    nextXPos = -1;
} 

Teleporter::Teleporter(int yPos, int xPos, int nextRoom, int nextYPos, int nextXPos, int color) : Object()
{
    this->yPos = yPos;
    this->xPos = xPos;
    this->nextRoom = nextRoom;
    this->nextYPos = nextYPos;
    this->nextXPos = nextXPos;
    this->color = color;
    this->symbol = "H";
}

Teleporter::~Teleporter()
{
}

/* ..............................................
  SETTERS
  
.............................................. */
void Teleporter::setNextRoom(int nextRoom)
{
    this->nextRoom = nextRoom;
}

void Teleporter::setNextYPos(int nextYPos)
{
    this->nextYPos = nextYPos;
}

void Teleporter::setNextXPos(int nextXPos)
{
    this->nextXPos = nextXPos;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Teleporter::getNextRoom()
{
    return nextRoom;
}

int Teleporter::getNextYPos()
{
    return nextYPos;
}

int Teleporter::getNextXPos()
{
    return nextXPos;
}
