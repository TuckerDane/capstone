/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	The Stone Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STONE_HPP
#define STONE_HPP

#include <stdlib.h>
#include "Object.h"

class Stone : public Object
{
private:
	string color;
	int weight = 10;

public:
	Stone();										// default constructor for Stone
	Stone(int row, int col, string c);				// constructor for Stone initializing rowPos, colPos, and room
	~Stone();										// deconstructor for Stone

	void setStone(int row, int col, string c);		// sets up stone
	int getWeight();								// returns the weight of the object
	string getName();								// returns the name of the Object
	void setWeight(int w);							// sets the weight of an object
};

#endif