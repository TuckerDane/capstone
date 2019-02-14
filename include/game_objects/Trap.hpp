/*......................................
 @file Trap.h
 @date 1/30/19

......................................*/
#ifndef TRAP_HPP
#define TRAP_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Trap : public Item
{
  public:
	//CONSTRUCTOR/DESTRUCTOR
	Trap();
	Trap(int yPos, int xPos);
	~Trap();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions(char direction);
};

#endif
