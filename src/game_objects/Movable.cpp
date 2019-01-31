/*............................................
 @file Movable.cpp
 @date 1/31/19

............................................*/

#include "Movable.hpp"

/*............................................
CONSTRUCTOR/DESTRUCTORS

............................................*/

Movable::Movable()
{
	this->name = "boulder";
	this->type = "movable";
	this->symbol = 'M';
	this->color = COLOR_CYAN;
	this->description = "This boulder is round-ish, maybe you can push it";
}

Movable::Movable(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	this->name = "boulder";
	this->type = "movable";
	this->symbol = 'M';
	this->color = COLOR_CYAN;
	this->description = "This boulder is round-ish, maybe you can push it";
}

Movable::~Movable()
{
	
}
/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/

void Movable::moveItem(char direction)
{
	//filler for later use  (call to heal from inventory?)
	if (direction == 'w')
	{
		setYPos(getYPos() - 1);
	}
	else if (direction == 's')
	{
		setYPos(getYPos() + 1);
	}
	else if (direction == 'a')
	{
		setXPos(getXPos() - 1);
	}
	else if (direction == 'd')
	{
		setXPos(getXPos() + 1);
	}
}