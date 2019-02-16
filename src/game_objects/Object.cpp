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
  symbol = "?";
  type = "generic_object";
  name = "unnamed";
  description = "none";
}

Object::Object(int xPos, int yPos, int color, string symbol, string type, string name, string description)
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

void Object::setSymbol(string symbol)
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

string Object::getSymbol()
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

int Object::setColorPair(int objectColor, int backgroundColor)
{
  if (objectColor == COLOR_RED)
  {
    if (backgroundColor == COLOR_BLACK)
      return RED_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return RED_ON_BLUE;
    else
      return 0;    
  }
  else if (objectColor == COLOR_GREEN)
  {
    if (backgroundColor == COLOR_BLACK)
      return GREEN_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return GREEN_ON_BLUE;
    else
      return 0;
  }
  else if (objectColor == COLOR_YELLOW)
  {
    if (backgroundColor == COLOR_BLACK)
      return YELLOW_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return YELLOW_ON_BLUE;
    else
      return 0;
  }
  else if (objectColor == COLOR_BLUE)
  {
    if (backgroundColor == COLOR_BLACK)
      return BLUE_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)  // TODO: Figure out what to do in this case
      return BLUE_ON_BLACK;
    else
      return 0;
  }
  else if (objectColor == COLOR_MAGENTA)
  {
    if (backgroundColor == COLOR_BLACK)
      return MAGENTA_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return MAGENTA_ON_BLUE;
    else
      return 0;
  }
  else if (objectColor == COLOR_CYAN)
  {
    if (backgroundColor == COLOR_BLACK)
      return CYAN_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return CYAN_ON_BLUE;
    else
      return 0;
  }
  else if (objectColor == COLOR_WHITE)
  {
    if (backgroundColor == COLOR_BLACK)
      return WHITE_ON_BLACK;
    else if(backgroundColor == COLOR_BLUE)
      return WHITE_ON_BLUE;
    else
      return 0;
  }
  else
  {
    return 0;
  }
}
