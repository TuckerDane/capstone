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
#include "Item.h"
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

/* ..............................................
  GLOBALS
  
.............................................. */
#define MAX_INVENTORY 10

/* ..............................................
  @brief 
  
.............................................. */
class Player : public Object
{
private:
	int maxCarryWeight;							// the maximum weight the player can carry
	int currentCarryWeight;					// the current amount of weight the player is carrying
	int numItems;										// the number of items in the player's inventory
	int currentSpace;								// the current space the player is in
	Item *inventory[MAX_INVENTORY]; // an inventory capable of carrying 10 Items
	bool isMoved;										// true of the player moved, false if the player did not move
	int selectedItemIndex;

public:
	// CONSTRUCTOR/DESTRUCTORS
	Player();
	~Player();

	// SETTERS
	void setMaxCarryWeight(int maxCarryWeight);
	void setCurrentCarryWeight(int currentCarryWeight);
	void setNumItems(int numItems);
	void setCurrentSpace(int curentSpace);
	void setInventory(Item *inventory[MAX_INVENTORY], int numItems);
	void setInventoryItem(Item *item, int itemSlot);
	void setSelectedItemIndex(int itemIndex);
	void setIsMoved(bool isMoved);

	// GETTERS
	int getMaxCarryWeight();
	int getCurrentCarryWeight();
	int getNumItems();
	int getCurrentSpace();
	int getSelectedItemIndex();
	Item **getInventory();								// returns the entire player inventory
	Item *getInventoryItem(int itemSlot); // returns a specific inventory item
	bool getIsMoved();

	// ACTIONS
	void move(char direction); // moves the Player x/y position by one space
	bool pickUp(Item *item);	 // adds an Object into the player's inventory
	Item *drop(int itemSlot);	// drops an Object from the player's inventory
};

#endif
