/*............................................
 @file Bomb.cpp
 @date 2/25/19

............................................*/
#include "Bomb.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Bomb::Bomb()
{
	name = "Bomberman Bomb";
	type = "bomb";
	weight = 1;
  damage = 2;
	symbol = "Ỏ"; 
	color = COLOR_RED;
	description = "Creates an explosion in a + shape. Don't forget to duck for cover!";
}

Bomb::Bomb(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "Bomberman Bomb";
	type = "bomb";
	weight = 1;
  damage = 2;
	symbol = "Ỏ"; 
	color = COLOR_RED;
	description = "Creates an explosion in a + shape. Don't forget to duck for cover!";
}

Bomb::~Bomb()
{
}

/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/