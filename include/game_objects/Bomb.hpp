/*......................................
  @ file Bomb.h
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019

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