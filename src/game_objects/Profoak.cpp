/*............................................
 @file Profoak.cpp
 @date 1/31/19

............................................*/
#include "Profoak.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Profoak::Profoak()
{
	weight = 150;
	name = "Professor Oak";
	type = "profoak";
	symbol = "☺";
	color = COLOR_YELLOW;
	description = "Professor Oak: If you bring me a pokémon, I'll give you something truly special.";
}

Profoak::Profoak(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 150;
	name = "Professor Oak";
	type = "profoak";
	symbol = "☺";
	color = COLOR_YELLOW;
	description = "Professor Oak: If you bring me a pokémon, I'll give you something truly special.";
}

Profoak::~Profoak()
{
}

/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/
