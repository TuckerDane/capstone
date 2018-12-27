/* ..............................................
  @file Space.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "Object.h"
#include "Player.h"
#include "Aarow.h"
#include "Door.h"
#include "Stone.h"
using std::string;

/* ..............................................
  @brief 
  
.............................................. */
class Space
{
protected:
	string spaceName;										// the name of the space
	string spaceType;										// the type of space
	int spaceNum;											// the number associated with the space
	int spSizeRow;											// the size of the row
	int spSizeCol;											// the size of the column
	Object*** space;										// a dynamically allocated 2d matrix of pointers to objects
	Player *player;											// a pointer to a player object

	Door leftDoor;											// doors
	Door rightDoor;
	Door topDoor;
	Door bottomDoor;

	Space* top;												// pointers to spaces
	Space* bottom;
	Space* left;
	Space* right;

public:
	Space();															// a constructor that initializes a 10x10 space with NULL values
	Space(int sizeRow, int sizeCol);									// a constructor that initializes an sizeRow x siezeCol space with NULL values
	~Space();															// a destructor for Space

	virtual void setSpSize(int sRow, int sCol);									// sets the size of "space[][]" to "sRow x sCol"
	virtual void setSpPos(Object *o, int row, int col);							// sets the value of a position in "space[][]" at "row","col" to the address of an object
	virtual void setDoors(bool leftD, bool rightD, bool topD, bool bottomD);	// a function which sets the doors for the Space
	virtual void setSpacePtrs(Space* t, Space* b, Space* l, Space* r);			// a function which sets the pointers (top, bottom, left and right) for the space
	virtual void setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num) = 0;

	virtual void setObjectPos(Object *o) = 0;									// pure virtual function allowing the setting of a specific object

	virtual Door* getDoor(string d);											// gets the indicated door

	virtual int	getSpSizeRow();													// returns "spSizeRow"
	virtual int	getSpSizeCol();													// returns "spSizeCol"
	virtual string getSpaceName();												// returns the name of the space
	virtual string getSpaceType();												// returns the type of space
	virtual Object* getSpPos(int row, int col);									// returns a pointer to what is at the position stored in the space at x, y
	virtual void printSpace();													// prints the space
	virtual bool movePlayer(char dir);											// a function which moves the player within the spacew
	virtual bool enterDoorway(char dir);										// handles player moving through a door
	virtual int getSpaceNum();													// returns the space number

};


#endif                                 
