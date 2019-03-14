/*............................................
  @ file Pokeflute.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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
