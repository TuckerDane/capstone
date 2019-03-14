/*......................................
  @ file Statue.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019


......................................*/
#ifndef STATUE_HPP
#define STATUE_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Statue : public Item
{

  public:
	//CONSTRUCTOR/DESTRUCTOR
	Statue();
	Statue(int yPos, int xPos, string description);
	~Statue();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions();
};

#endif
