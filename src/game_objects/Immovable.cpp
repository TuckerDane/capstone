/*............................................
  @ file Immovable.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


............................................*/
#include "Immovable.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Immovable::Immovable()
{
	name = "pillar";
	type = "immovable";
	symbol = "■";
	color = COLOR_WHITE;
	description = "This is a pillar, looks like those used in important buildings.";
} 

Immovable::Immovable(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "pillar";
	type = "immovable";
	symbol = "■";
	color = COLOR_WHITE;
	description = "This is a pillar, looks like those used in important buildings.";
}

Immovable::Immovable(int yPos, int xPos, int color)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "pillar";
	type = "immovable";
	symbol = "█";
	color = (this->color);
	description = "This is a pillar, looks like those used in important buildings.";
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
//triggerItemActions. Do we want immovable objects to have an action that can be triggered?