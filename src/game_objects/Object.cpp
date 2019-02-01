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
  xPos = 0;
  yPos = 0;
  color = COLOR_BLACK;
  symbol = '?';
  type = "generic_object";
  name = "unnamed";
  description = "none";
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
  return xPos;
}

int Object::getYPos()
{
  return yPos;
}

int Object::getColor()
{
  return color;
}

char Object::getSymbol()
{
  return symbol;
}

string Object::getType()
{
  return type;
}

string Object::getName()
{
  return name;
}

string Object::getDescription()
{
  return description;
}

/* ..............................................
  ACTIONS
  
.............................................. */

int Object::setColorPair(int objectColor)
{
  if (objectColor == COLOR_RED)
  {
    return RED_ON_BLACK;
  }
  else if (objectColor == COLOR_GREEN)
  {
    return GREEN_ON_BLACK;
  }
  else if (objectColor == COLOR_YELLOW)
  {
    return YELLOW_ON_BLACK;
  }
  else if (objectColor == COLOR_BLUE)
  {
    return BLUE_ON_BLACK;
  }
  else if (objectColor == COLOR_MAGENTA)
  {
    return MAGENTA_ON_BLACK;
  }
  else if (objectColor == COLOR_CYAN)
  {
    return CYAN_ON_BLACK;
  }
  else if (objectColor == COLOR_WHITE)
  {
    return WHITE_ON_BLACK;
  }
  else
  {
    return 0;
  }
}
