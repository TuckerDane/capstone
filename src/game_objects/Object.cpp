/* ..............................................
  @file Object.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Object.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Object::Object()
{
  this->xPos = 0;
  this->yPos = 0;
  this->weight = 0;
  this->color = COLOR_BLACK;
  this->symbol = '?';
  this->type = "generic";
  this->name = "unnamed";
}

Object::Object(int xPos, int yPos, int weight, int color, char symbol, string type, string name)
{
  this->xPos = xPos;
  this->yPos = yPos;
  this->weight = weight;
  this->color = color;
  this->symbol = symbol;
  this->type = type;
  this->name = name;
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

void Object::setWeight(int weight)
{
  this->weight = weight;
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
  this->type = setType;
}

void Object::setName(string name)
{
  this->name = name;
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

int Object::getWeight()
{
  return this->weight;
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