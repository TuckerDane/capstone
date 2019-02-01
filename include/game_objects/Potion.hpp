/*......................................
 @file Potion.h
 @date 1/30/19

......................................*/

#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"


/*.....................................
 @brief

.....................................*/

class Potion : public Item
{

public:
	//CONSTRUCTOR/DESTRUCTOR
	Potion();
	Potion(int yPos, int xPos);
	~Potion();
	
	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions(char direction);
};

#endif
