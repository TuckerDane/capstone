/*............................................
  @ file Bomb.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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