/*......................................
 @file Movable.hpp
 @date 1/31/19

......................................*/
#ifndef MOVABLE2_HPP
#define MOVABLE2_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Movable2 : public Item
{
  public:
	//CONSTRUCTOR/DESTRUCTOR
	Movable2();
	Movable2(int yPos, int xPos);
	Movable2(int yPos, int xPos, string symbol);
	Movable2(int yPos, int xPos, int color, int number, int choice); //y position, x position, color, healing or damage  value, healing (1) or damage (else)
	~Movable2();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions(char direction);
};

#endif
