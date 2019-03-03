/*............................................
 @file Softblock.cpp
 @date 1/31/19

............................................*/
#include "Softblock.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Softblock::Softblock()
{
	name = "Soft Block";
	type = "softblock";
	symbol = "█";
	color = COLOR_WHITE;
	description = "This block looks pretty solid, but I bet it can still be blown to smithereens.";
} 

Softblock::Softblock(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "Soft Block";
	type = "softblock";
	symbol = "█";
	color = COLOR_WHITE;
	description = "This block looks pretty solid, but I bet it can still be blown to smithereens.";
}

Softblock::~Softblock()
{
}
/*............................................
  GETTERS

............................................*/

/*............................................
  ACTIONS

............................................*/