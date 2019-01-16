/* ..............................................
  @file Player.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Player.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Player::Player() : Object(0, 0, 150, COLOR_BLACK, '^', "player_object", "adventurer")
{
	this->maxCarry = 300;
	this->numItems = 0;
	for (int itemSlot = 0; itemSlot < MAX_INVENTORY; itemSlot++)
	{
		this->inventory[itemSlot] = NULL;
	}
	this->isMoved = false;
}

Player::~Player()
{
}

/* ..............................................
  SETTERS
  
.............................................. */

void Player::setMaxCarry(int maxCarry)
{
	this->maxCarry = maxCarry;
}

void Player::setCarryWeight(int carryWeight)
{
	this->carryWeight = carryWeight;
}

void Player::setNumItems(int numItems)
{
	this->numItems = numItems;
}

void Player::setInventory(Object *inventory[MAX_INVENTORY], int numItems)
{
	for (int itemSlot = 0; itemSlot < MAX_INVENTORY; itemSlot++)
	{
		this->inventory[itemSlot] = inventory[itemSlot];
	}
	this->numItems = numItems;
}

void Player::setInventoryItem(Object *item, int itemSlot)
{
	this->inventory[itemSlot] = item;
}

void Player::setIsMoved(bool isMoved)
{
	this->isMoved = isMoved;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Player::getMaxCarry()
{
	return this->maxCarry;
}

int Player::getCarryWeight()
{
	return this->carryWeight;
}

int Player::getNumItems()
{
	return this->numItems;
}

/* ..............................................
  @brief returns the entire player inventory
  
  @return Object** 
.............................................. */
Object **Player::getInventory()
{
	return this->inventory;
}

/* ..............................................
  @brief returns a specific inventory item
  
  @param itemSlot 
  @return Object* 
.............................................. */
Object *Player::getInventoryItem(int itemSlot)
{
	return this->inventory[itemSlot];
}

bool Player::getIsMoved()
{
	return this->isMoved;
}

/* ..............................................
  ACTIONS
  
.............................................. */

/* ..............................................
  @brief moves the Player x/y position by one space
  
  @param direction 
.............................................. */
void Player::move(char direction)
{
	if (direction == 'w')
	{
		setYPos(getYPos() - 1);
	}
	else if (direction == 's')
	{
		setYPos(getYPos() + 1);
	}
	else if (direction == 'a')
	{
		setXPos(getXPos() - 1);
	}
	else if (direction == 'd')
	{
		setXPos(getXPos() + 1);
	}
	else
	{
		cerr << "ERROR: Player.move failed; invalid direction!";
	}
	setIsMoved(true);
}

/* ..............................................
  @brief adds an Object into the player's inventory
  
  @param item 
  @return true 
  @return false 
.............................................. */
bool Player::pickUp(Object *item)
{
	if (item->getWeight() <= (this->maxCarry - this->carryWeight)) // if the object doesn't weigh too much
	{
		if (this->numItems < MAX_INVENTORY) // and there is a slot for it in the backpack
		{
			bool found = false; // find an open (NULL) slot
			int itemSlot = 0;

			while (found == false) // conduct a linear search of the backpack for the slot
			{
				if (this->inventory[itemSlot] == NULL)
				{
					found = true;																				 // when found, set to true
					this->inventory[itemSlot] = item;											 // and set the object pointer to the address of the object
					this->numItems++;																		 // add to the item counter
					this->weight += this->inventory[itemSlot]->getWeight(); // add to the weight of the player
					return true;
				}
				itemSlot++;
			}
		}
	}
	return false;
}

/* ..............................................
  @brief drops an Object from the player's inventory
  
  @param i 
  @return Object* 
.............................................. */
Object *Player::drop(int itemSlot)
{
	while (0 <= itemSlot && itemSlot < MAX_INVENTORY) // if the player inputs a valid inventory item slot
	{
		if (this->inventory[itemSlot] == NULL) // if itemSlot is an empty space in the inventory
		{
			return NULL; // return NULL
		}
		else // else
		{
			Object *temp = this->inventory[itemSlot]; // set the object in the inventory to a temporary variable
			this->inventory[itemSlot] = NULL;					// set the inventory itemSlot to empty

			this->carryWeight -= temp->getWeight(); // subtract the weight of the object from the player's carryWeight
			this->numItems--;									 // reduce the item counter
			return temp;											 // return the dropped item
		}
	}
	return NULL;
}