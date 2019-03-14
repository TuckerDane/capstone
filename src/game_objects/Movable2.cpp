/*............................................
  @ file Movable.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019

............................................*/
#include "Movable2.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Movable2::Movable2()
{
	weight = 1000;
	name = "boulder";
	type = "movable2";
	symbol = ".";
	color = COLOR_CYAN;
	description = "This boulder is round-ish, maybe you can push it";
}

Movable2::Movable2(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 1000;
	name = "boulder";
	type = "movable2";
	symbol = ".";
	color = COLOR_CYAN;
	description = "This boulder is round-ish, maybe you can push it";
}

Movable2::Movable2(int yPos, int xPos, string symbol)
{
	this->yPos = yPos;
	this->xPos = xPos;
	weight = 1000;
	name = "block";
	type = "movable2";
	this->symbol = symbol;
	color= COLOR_CYAN;
	description = "Seems lighter than most blocks";
}

Movable2::Movable2(int yPos, int xPos, int color, int number, int choice)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "boulder";
	type = "movable2";
	symbol = "."; 
	this->color = color;
	description = "This boulder is round-ish, maybe you can push it";

	if (choice == 1) //number is healing
	{
		healing = number;
	}
	else
	{
		damage = number;
	}
}

Movable2::~Movable2()
{
}

/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/

void Movable2::triggerItemActions(char direction)
{
	devConsole.log("Item "+this->name+" moving "+string(1, direction));
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
