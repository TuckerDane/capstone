/*............................................
  @ file Snorlax.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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
