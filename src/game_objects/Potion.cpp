/*............................................
  @ file Potion.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


............................................*/
#include "Potion.hpp"
#include "Player.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Potion::Potion()
{
	name = "generic potion";
	type = "potion";
	weight = 2;
	healing = 4;
	symbol = "ῦ"; 
	color = COLOR_GREEN;
	description = "Heals the player for 4 HP";
}

Potion::Potion(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "health potion";
	type = "potion";
	weight = 2;
	healing = 4;
	symbol = "ῦ";
	color = COLOR_GREEN;
	description = "Heals the player for 4 HP";
}

Potion::~Potion()
{
}

/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/

void Potion::triggerItemActions(char direction)
{
	//filler for later use if needde (triggering a buff, healing an enemy or door, etc)
}
