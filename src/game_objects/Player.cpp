/* ..............................................
  @file Player.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Player.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Player::Player() : Object(-1, -1, COLOR_BLACK, '^', "player_object", "adventurer", "none")
{
	this->numItems = 0;
	this->currentRoom = 0;
	for (int itemSlot = 0; itemSlot < MAX_INVENTORY; itemSlot++)
	{
		this->inventory[itemSlot] = NULL;
	}
	this->isMoved = false;
	setSelectedItemIndex(0);
}

Player::~Player()
{
	for (int i = 0; i < MAX_INVENTORY; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
		}
	}
}

/* ..............................................
  SETTERS
  
.............................................. */

void Player::setMaxCarryWeight(int maxCarryWeight)
{
	this->maxCarryWeight = maxCarryWeight;
}

void Player::setCurrentCarryWeight(int carryCurrentCarryWeight)
{
	this->currentCarryWeight = currentCarryWeight;
}

void Player::setNumItems(int numItems)
{
	this->numItems = numItems;
}

void Player::setCurrentRoom(int currentRoom)
{
	this->currentRoom = currentRoom;
}

void Player::setInventory(Item *inventory[MAX_INVENTORY], int numItems)
{
	for (int itemSlot = 0; itemSlot < MAX_INVENTORY; itemSlot++)
	{
		this->inventory[itemSlot] = inventory[itemSlot];
	}
	this->numItems = numItems;
}

void Player::setInventoryItem(Item *item, int itemSlot)
{
	this->inventory[itemSlot] = item;
}

void Player::setSelectedItemIndex(int itemIndex)
{
	this->selectedItemIndex = itemIndex;
}

void Player::setIsMoved(bool isMoved)
{
	this->isMoved = isMoved;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Player::getMaxCarryWeight()
{
	return this->maxCarryWeight;
}

int Player::getCurrentCarryWeight()
{
	return this->currentCarryWeight;
}

int Player::getNumItems()
{
	return this->numItems;
}

int Player::getCurrentRoom()
{
	return this->currentRoom;
}

int Player::getMaxInventory()
{
	return this->MAX_INVENTORY;
}

/* ..............................................
  @brief returns the entire player inventory
  
  @return Item** 
.............................................. */
Item **Player::getInventory()
{
	return this->inventory;
}

/* ..............................................
  @brief returns a specific inventory item
  
  @param itemSlot 
  @return Item* 
.............................................. */
Item *Player::getInventoryItem(int itemSlot)
{
	return this->inventory[itemSlot];
}

Item *Player::getSelectedItem()
{
	return this->inventory[this->selectedItemIndex];
}

int Player::getSelectedItemIndex()
{
	return this->selectedItemIndex;
}

bool Player::getIsMoved()
{
	return this->isMoved;
}

/* ..............................................
  ACTIONS
  
.............................................. */

/* ..............................................
  @brief moves the Player x/y position by one room
  
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
  @brief adds an Item into the player's inventory
  
  @param item 
  @return true 
  @return false 
.............................................. */
bool Player::pickUp(Item *item)
{
	if (item->getWeight() <= (this->maxCarryWeight - this->currentCarryWeight)) // if the Item doesn't weigh too much
	{
		if (this->numItems < MAX_INVENTORY) // and there is a slot for it in the backpack
		{
			bool found = false; // find an open (NULL) slot
			int itemSlot = 0;

			while (found == false) // conduct a linear search of the backpack for the slot
			{
				if (this->inventory[itemSlot] == NULL)
				{
					found = true;														// when found, set to true
					this->inventory[itemSlot] = item;									// and set the Item pointer to the address of the Item
					this->numItems++;													// add to the item counter
					this->currentCarryWeight += this->inventory[itemSlot]->getWeight(); // add to the current carry weight of the player
					return true;
				}
				itemSlot++;
			}
		}
	}
	return false;
}

/* ..............................................
  @brief drops an Item from the player's inventory
  
  @param i 
  @return Item* 
.............................................. */
Item *Player::drop(int itemSlot)
{
	while (0 <= itemSlot && itemSlot < MAX_INVENTORY) // if the player inputs a valid inventory item slot
	{
		if (this->inventory[itemSlot] == NULL) // if itemSlot is an empty room in the inventory
		{
			return NULL; // return NULL
		}
		else // else
		{
			Item *temp = this->inventory[itemSlot]; // set the Item in the inventory to a temporary variable
			this->inventory[itemSlot] = NULL;		// set the inventory itemSlot to empty

			this->currentCarryWeight -= temp->getWeight(); // subtract the weight of the Item from the player's carryWeight
			this->numItems--;							   // reduce the item counter
			return temp;								   // return the dropped item
		}
	}
	return NULL;
}