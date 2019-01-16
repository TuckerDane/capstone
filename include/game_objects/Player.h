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
using std::cerr;

/* ..............................................
  GLOBALS
  
.............................................. */
#define MAX_INVENTORY	10

/* ..............................................
  @brief 
  
.............................................. */
class Player : public Object
{
private:
	int maxCarry;	 											// the maximum weight the player can carry
	int carryWeight;										// the current amount of weight the player is carrying
	int numItems;				 								// the number of items in the player's inventory
	Object* inventory[MAX_INVENTORY]; 	// an inventory capable of carrying 10 Objects
	bool isMoved;												// true of the player moved, false if the player did not move

public:
	// CONSTRUCTOR/DESTRUCTORS
	Player();
	~Player();

	// SETTERS
	void setMaxCarry(int maxCarry);
	void setCarryWeight(int carryWeight);
	void setNumItems(int numItems);
	void setInventory(Object** inventory, int numItems);
	void setInventoryItem(Object* item, int itemSlot);
	void setIsMoved(bool isMoved);

	// GETTERS
	int getMaxCarry();
	int getCarryWeight();
	int getNumItems();
	Object** getInventory();									// returns the entire player inventory
	Object* getInventoryItem(int itemSlot);		// returns a specific inventory item
	bool getIsMoved();

	// ACTIONS
	void move(char direction);	// moves the Player x/y position by one space
	bool pickUp(Object* item);	// adds an Object into the player's inventory
	Object *drop(int itemSlot);	// drops an Object from the player's inventory
};

#endif
