//FIXME: block commenting
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	The Switch Class
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SWITCH_HPP
#define SWITCH_HPP

#include <stdlib.h>
#include "Object.h"

class Switch : public Object {
	private:
		string color;
		bool tripped;

	public:
		Switch();												// default constructor for Switch
		Switch(int row, int col, string c, char s);				// constructor for Switch initializing rowPos, colPos, and room
		~Switch();												// deconstructor for Switch
		//FIXME: get and set order
		void setSwitch(int row, int col, string c, char s);		// sets up Switch
		int getWeight();										// returns the weight of the object
		string getName();										// returns the name of the Object
		void setWeight(int w);									// sets the weight of an object
		void setTripped(bool t);								// trips the switch
		bool getTripped();										// returns the switch's status
};

#endif