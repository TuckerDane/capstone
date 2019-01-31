/*............................................
 @file Potion.cpp
 @date 1/30/19

............................................*/

#include "Potion.h"

/*............................................
CONSTRUCTOR/DESTRUCTORS

............................................*/

Potion::Potion()
{
	this->name = "Health_Potion";
	this->type = "potion_item";
	this->weight = 2;
	this->healing = 4;
	this->symbol = 'P';
	this->color = COLOR_GREEN;
	this->description = "Heals the player for 4 HP";
}

Potion::Potion(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	this->name = "Health_Potion";
	this->type = "potion_item";
	this->weight = 2;
	this->healing = 4;
	this->symbol = 'P';
	this->color = COLOR_GREEN;
	this->description = "Heals the player for 4 HP";
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

void Potion::moveItem(char direction)
{
	//filler for later use  (call to heal from inventory?)
}
