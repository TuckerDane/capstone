/*............................................
 @file Potion.cpp
 @date 1/30/19

............................................*/
#include "Potion.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Potion::Potion()
{
	name = "Health_Potion";
	type = "potion_item";
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
	name = "Potion";
	type = "potion_item";
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
	//filler for later use if needed (triggering a buff, healing an enemy or door, etc)
}
