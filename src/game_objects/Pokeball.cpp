/*............................................
 @file Pokeball.cpp
 @date 1/31/19

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
