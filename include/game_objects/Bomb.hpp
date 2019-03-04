/*......................................
 @file Bomb.h
 @date 02/25/2019

......................................*/
#ifndef BOMB_HPP
#define BOMB_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Bomb : public Item
{
  public:
	//CONSTRUCTOR/DESTRUCTOR
	Bomb();
	Bomb(int yPos, int xPos);
	~Bomb();

	//SETTERS
	//GETTERS
	//ACTION
};

#endif