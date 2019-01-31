/* ..............................................
  @file Object.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Object.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Object::Object()
{
  this->xPos = 0;
  this->yPos = 0;
  this->color = COLOR_BLACK;
  this->symbol = '?';
  this->type = "generic_object";
  this->name = "unnamed";
  this->description = "none";
}

Object::Object(int xPos, int yPos, int color, char symbol, string type, string name, string description)
{
  this->xPos = xPos;
  this->yPos = yPos;
  this->color = color;
  this->symbol = symbol;
  this->type = type;
  this->name = name;
  this->description = description;
}

Object::~Object()
{
}

/* ..............................................
  SETTERS 
  
.............................................. */

void Object::setXPos(int xPos)
{
  this->xPos = xPos;
}

void Object::setYPos(int yPos)
{
  this->yPos = yPos;
}

void Object::setColor(int color)
{
  this->color = color;
}

void Object::setSymbol(char symbol)
{
  this->symbol = symbol;
}

void Object::setType(string type)
{
  this->type = type;
}

void Object::setName(string name)
{
  this->name = name;
}

void Object::setDescription(string description)
{
  this->description = description;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Object::getXPos()
{
  return this->xPos;
}

int Object::getYPos()
{
  return this->yPos;
}

int Object::getColor()
{
  return this->color;
}

char Object::getSymbol()
{
  return this->symbol;
}

string Object::getType()
{
  return this->type;
}

string Object::getName()
{
  return this->name;
}

string Object::getDescription()
{
  return this->description;
}

/* ..............................................
  ACTIONS
  
.............................................. */

int Object::setColorPair(int objectColor){
  if (objectColor == 1)
  {
    return 1;
  }
  else if (objectColor == 2)
  {
    return 15;
  }
  else if (objectColor == 3)
  {
    return 23;
  }
  else if (objectColor == 4)
  {
    return 30;
  }
  else if (objectColor == 5)
  {
    return 37;
  }
  else if (objectColor == 6)
  {
    return 44;
  }
  else if (objectColor == 7)
  {
    return 51;
  }
  else
  {
    return 0; 
  }
}
