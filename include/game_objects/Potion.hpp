/*......................................
  @ file Potion.h
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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
