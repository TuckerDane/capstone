/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	The Dungeon
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <iostream>
#include "Object.h"
#include "Player.h"
#include "Door.h"
#include "Space.h"
#include "Room.h"
#include "GreatRoom.h"
#include "vHallWay.h"
#include "hHallWay.h"

using std::string;

class Dungeon
{
private:
	//PLAYER OBJECT
	Player tucker;

	//STONE OBJECTS
	Stone white;
	Stone red;
	Stone yellow;
	Stone green;
	Stone blue;

	//SWITCH OBJECTS
	Switch switches[5];
	Switch aarowSwitch[1];

	//ROOM OBJECTS
	Room room1;
	vHallWay room2;
	GreatRoom room3;
	hHallWay room4;
	Room room5;
	vHallWay room6;
	Room room7;
	hHallWay room8;
	Room room9;
	vHallWay room10;
	Room room11;
	vHallWay room12;
	GreatRoom room13;

	Space *sPtr[13];

public:
	Dungeon();									// default constructor
	~Dungeon();									// destructor

	void setStones();
	void setSwitches();
	void setSpaces();
	void setPlayer(Space *startingRoom, int i);	// sets the player

	bool getSwitch(int num);					// returns a switch value
	bool getASwitch();							// returns aarow switch value

	Player* getPlayer();
	Space* getRoom(int i);
};


#endif                                 
