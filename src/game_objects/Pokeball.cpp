/*............................................
  @ file Pokeball.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


............................................*/
#include "Pokeball.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Pokeball::Pokeball()
{
	weight = 1;
	name = "Poké Ball";
	type = "poke_ball";
	symbol = "ɵ";
	color = COLOR_RED;
	description = "A Ball thrown at wild Pokémon to catch them.";
}

Pokeball::Pokeball(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 1;
	name = "Poké Ball";
	type = "poke_ball";
	symbol = "ɵ";
	color = COLOR_RED;
	description = "A Ball thrown at wild Pokémon to catch them.";
}

Pokeball::~Pokeball()
{
}

/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/
