/*......................................
  @ file Movable.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


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
	Movable(int yPos, int xPos, string symbol);
	Movable(int yPos, int xPos, int color, int number, int choice); //y position, x position, color, healing or damage  value, healing (1) or damage (else)
	~Movable();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions(char direction);
};

#endif
