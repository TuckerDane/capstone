/*............................................
 @file Pokeflute.cpp
 @date 1/31/19

............................................*/
#include "Pokeflute.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Pokeflute::Pokeflute()
{
	weight = 1;
	name = "Poké Flute";
	type = "poke_flute";
	symbol = "ʃ";
	color = COLOR_YELLOW;
	description = "Plays a pleasant melody that rouses Pokémon from sleep.";
}

Pokeflute::Pokeflute(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 1;
	name = "Poké Flute";
	type = "poke_flute";
	symbol = "ʃ";
	color = COLOR_YELLOW;
	description = "Plays a pleasant melody that rouses Pokémon from sleep.";
}

Pokeflute::~Pokeflute()
{
}

/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/
