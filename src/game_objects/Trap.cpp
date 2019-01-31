/*............................................
 @file Trap.cpp
 @date 1/30/19

............................................*/

#include "Trap.hpp"

/*............................................
CONSTRUCTOR/DESTRUCTORS

............................................*/

Trap::Trap()
{
	this->name = "Trap";
	this->type = "trap_item";
	this->weight = 2;
	this->damage = 6;
	this->symbol = 'T';
	this->color = COLOR_RED;
	this->description = "Damages the player for 6 HP";
}

Trap::Trap(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	this->name = "Trap";
	this->type = "trap_item";
	this->weight = 2;
	this->damage = 6;
	this->symbol = 'T';
	this->color = COLOR_RED;
	this->description = "Damages the player for 6 HP";
}

Trap::~Trap()
{
	
}
/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/

void Trap::moveItem(char direction)
{
	//filler for later use  (laying a trap?)
}
