/*............................................
  @ file Profoak.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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
