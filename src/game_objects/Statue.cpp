/*............................................
  @ file Statue.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


............................................*/
#include "Statue.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Statue::Statue()
{
	name = "statue";
	type = "statue";
	symbol = "I";
	color = COLOR_BLUE;
	description = "You find nothing on this statue.";
	weight = 1000;
} 

Statue::Statue(int yPos, int xPos, string description)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "statue";
	type = "statue";
	symbol = "I";
	color = COLOR_BLUE;
	this->description = description;
	weight = 1000;
}

Statue::~Statue()
{
}
/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/
//triggerItemActions. Do we want Statue objects to have an action that can be triggered?
