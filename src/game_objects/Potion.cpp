/*............................................
 @file Potion.cpp
 @date 1/30/19

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
	symbol = 'P';
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
	symbol = 'P';
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
