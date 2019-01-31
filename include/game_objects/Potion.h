/*......................................
 @file Potion.h
 @date 1/30/19

......................................*/

#ifndef POTION_HPP
#define POTION_HPP

#include "Item.h"


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
	void itemAction();
};

#endif
