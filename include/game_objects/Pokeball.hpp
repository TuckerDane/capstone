/*......................................
 @file Pokeball.hpp
 @date 02/19/2019

......................................*/
#ifndef POKEBALL_HPP
#define POKEBALL_HPP

#include "Item.hpp"

/*.....................................
 @brief

.....................................*/

class Pokeball : public Item
{
  public:
	//CONSTRUCTOR/DESTRUCTOR
	Pokeball();
	Pokeball(int yPos, int xPos);
	~Pokeball();

	//SETTERS
	//GETTERS
	//ACTION

};

#endif