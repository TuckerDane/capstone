/* ..............................................
  @file Player.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdlib.h>
#include "Object.h"
using std::cin;
using std::cout;
using std::endl;

/* ..............................................
  @brief 
  
.............................................. */
class Player : public Object
{
private:
	string currentRoom;	// the room tucker is currently occupying
	int cRoom;					 // the room tucker is in
	Object *backpack[9]; // a backpack with 10 slots in it
	int maxCarry = 20;	 // the max weight tucker can carry is 20 lbs
	int numItems;				 // the number of items the player is carrying

public:
	Player();																			// default constructor for Player
	Player(int row, int col, string room, int r); // constructor for Player initializing rowPos, colPos, and room
	~Player();																		// deconstructor for Player

	//FIXME: naming conventions
	void setSymbol(char s);									// a function which changes the player's symbol
	void setPlayerRoom(string room, int i); // a function which changes the room the player is in
	void setWeight(int w);									// sets the weight of an object

	string getPlayerRoom(); // a function which gets the room the player is in
	int getCRoom();					// gets the room tucker is in
	int getWeight();				// returns the weight of the object
	string getName();				// returns the name of the Object

	bool addObject(Object *o); // adds an object to backpack and returns true if it worked
	void displayBackpack();		 // displays the backpack and includes a message on how to use it
	Object *dropObject(int i); // drops an object from the backpack
	string checkObject(int i); // checks to see if the object to drop is a stone corresponding to a switch
};

#endif
