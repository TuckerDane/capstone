/*
	Name:			Tucker Dane Walker
	Date:			09 December 2016
	Description:	The Aarow Class
*/

#ifndef AAROW_HPP
#define AAROW_HPP

#include <stdlib.h>
#include "Object.h"

class Aarow : public Object
{
private:
	int weight = 2;

public:
	Aarow();								// default constructor for Player
	Aarow(int row, int col);				// constructor for Player initializing rowPos, colPos, and room
	~Aarow();								// deconstructor for Player

	void setPosition(int row, int col);		// sets the aarow position
	int getWeight();						// returns the weight of the object
	string getName();						// returns the name of the Object
	void setWeight(int w);					// sets the weight of an object
};

#endif