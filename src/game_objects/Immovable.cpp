/*............................................
 @file Immovable.cpp
 @date 1/31/19

............................................*/

#include "Immovable.h"

/*............................................
CONSTRUCTOR/DESTRUCTORS

............................................*/

Immovable::Immovable()
{
	this->name = "pillar";
	this->type = "immovable";
	this->symbol = 'O';
	this->color = COLOR_WHITE;
	this->description = "This is a pillar, looks like those used in important buildings.";
}

Immovable::Immovable(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	this->name = "pillar";
	this->type = "immovable";
	this->symbol = 'O';
	this->color = COLOR_WHITE;
	this->description = "This is a pillar, looks like those used in important buildings.";
}

Immovable::~Immovable()
{
	
}
/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/

