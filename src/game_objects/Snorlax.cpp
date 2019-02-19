/*............................................
 @file Snorlax.cpp
 @date 1/31/19

............................................*/
#include "Snorlax.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Snorlax::Snorlax()
{
	weight = 1000000;
	name = "Snorlax";
	type = "snorlax";
	symbol = "Ω";
	color = COLOR_WHITE;
	description = "A sleeping POKéMON blocks the way!";
}

Snorlax::Snorlax(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 1000000;
	name = "Snorlax";
	type = "snorlax";
	symbol = "Ω";
	color = COLOR_WHITE;
	description = "A sleeping POKéMON blocks the way!";
}

Snorlax::~Snorlax()
{
}

/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/
