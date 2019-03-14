/*......................................
  @ file Immovable.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


......................................*/
#ifndef IMMOVABLE_HPP
#define IMMOVABLE_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Immovable : public Item
{

  public:
	//CONSTRUCTOR/DESTRUCTOR
	Immovable();
	Immovable(int yPos, int xPos);
	Immovable(int yPos, int xPos, int color);
	~Immovable();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions();
};

#endif
