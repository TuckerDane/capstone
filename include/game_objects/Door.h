//FIXME: block commenting
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	The Door Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DOOR_HPP
#define DOOR_HPP

#include <stdlib.h>
#include "Object.h"

class Door : public Object {
	private:
		bool open;								// true is open, false is locked

	public:
		Door();									// default constructor for Door
		Door(char s, int row, int col);			// constructor for Door initializing its symbol, rowPos, and colPos
		~Door();								// deconstructor for Door
		//FIXME: get and set order
		void setSymbol(char s);					// a function which changes the door's symbol
		void setOpen(bool o);					// a function which changes the Door's status
		bool getOpen();							// returns true if the door is open
		int getWeight();						// returns the weight of the object
		string getName();						// returns the name of the Object
		void setWeight(int w);					// sets the weight of an object
};

#endif

