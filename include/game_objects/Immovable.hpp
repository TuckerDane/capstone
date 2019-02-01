/*......................................
 @file Immovable.hpp
 @date 1/31/19

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
	~Immovable();

	//SETTERS
	//GETTERS
	//ACTION
	void triggerItemActions();
};

#endif
