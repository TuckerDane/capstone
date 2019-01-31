/*......................................
 @file Movable.hpp
 @date 1/31/19

......................................*/

#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Item.hpp"


/*.....................................
 @brief

.....................................*/

class Movable : public Item
{

public:
	//CONSTRUCTOR/DESTRUCTOR
	Movable();
	Movable(int yPos, int xPos);
	~Movable();
	
	//SETTERS
	//GETTERS
	//ACTION
	void moveItem(char direction);
};

#endif
