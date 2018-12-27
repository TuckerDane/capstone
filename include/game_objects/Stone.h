/* ..............................................
  @file Stone.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */

#ifndef STONE_HPP
#define STONE_HPP

#include <stdlib.h>
#include "Object.h"

/* ..............................................
  @brief 
  
.............................................. */
class Stone : public Object {
	private:
		string color;
		int weight = 10;

	public:
		Stone();										// default constructor for Stone
		Stone(int row, int col, string c);				// constructor for Stone initializing rowPos, colPos, and room
		~Stone();										// deconstructor for Stone
		//FIXME: get and set order
		void setStone(int row, int col, string c);		// sets up stone
		int getWeight();								// returns the weight of the object
		string getName();								// returns the name of the Object
		void setWeight(int w);							// sets the weight of an object
};

#endif