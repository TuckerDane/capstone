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
	numItems = 0;
	currentRoom = 0;
	for (int itemSlot = 0; itemSlot < MAX_INVENTORY; itemSlot++)
	{
		inventory[itemSlot] = NULL;
	}
	isMoved = false;
	setSelectedItemIndex(0);
	setEquippedItemIndex(0);
	hp = 10;
	maxHP = 10;
	currentCarryWeight = 0;
	maxCarryWeight = 10;
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

void Player::setEquippedItemIndex(int itemIndex)
{
	this->equippedItemIndex = itemIndex;
}

void Player::setIsMoved(bool isMoved)
{
	this->isMoved = isMoved;
}

void Player::setHP(int newHP)
{
	this->hp = newHP;
}

void Player::setMaxHP(int newMaxHP)
{
	this->maxHP = newMaxHP;
}
/* ..............................................
  GETTERS
  
.............................................. */

int Player::getMaxCarryWeight()
{
	return maxCarryWeight;
}

int Player::getCurrentCarryWeight()
{
	return currentCarryWeight;
}

int Player::getNumItems()
{
	return numItems;
}

int Player::getCurrentRoom()
{
	return currentRoom;
}

int Player::getMaxInventory()
{
	return MAX_INVENTORY;
}

int Player::getHP()
{
	return hp;
}

int Player::getMaxHP()
{
	return maxHP;
}

/* ..............................................
  @brief returns the entire player inventory
  
  @return Item** 
.............................................. */
Item **Player::getInventory()
{
	return inventory;
}

/* ..............................................
  @brief returns a specific inventory item
  
  @param itemSlot 
  @return Item* 
.............................................. */
Item *Player::getInventoryItem(int itemSlot)
{
	return inventory[itemSlot];
}

Item *Player::getSelectedItem()
{
	return inventory[selectedItemIndex];
}

int Player::getSelectedItemIndex()
{
	return selectedItemIndex;
}

int Player::getEquippedItemIndex()
{
	return equippedItemIndex;
}

bool Player::getIsMoved()
{
	return isMoved;
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
    if (item->getWeight() <= (maxCarryWeight - currentCarryWeight))
    {	 
	   if (numItems < MAX_INVENTORY) // if the Item weight will not encumber the player and there is an empty slot in the backpack
  	   {
		bool found = false; // find an open (NULL) slot
		int itemSlot = 0;
		while (found == false) // conduct a linear search of the backpack for the slot
		{
			if (inventory[itemSlot] == NULL)
			{
				found = true;											// when found, set to true
				inventory[itemSlot] = item;								// and set the Item pointer to the address of the Item
				numItems++;				// add to the item counter
				currentCarryWeight +=  inventory[itemSlot]->getWeight();  // add to the current carry weight of the player
				return true;
			}
			itemSlot++;
		}
           }  

    }
    //else
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
		if (inventory[itemSlot] == NULL) // if itemSlot is an empty room in the inventory
		{
			return NULL; // return NULL
		}
		else // else
		{
			Item *temp = inventory[itemSlot]; // set the Item in the inventory to a temporary variable
			inventory[itemSlot] = NULL;		  // set the inventory itemSlot to empty

			currentCarryWeight -= temp->getWeight(); // subtract the weight of the Item from the player's carryWeight
			numItems--;								 // reduce the item counter
			return temp;							 // return the dropped item
		}
	}
	return NULL;
}

/* ..............................................
  @brief damages the player
  
  @param change in HP
.............................................. */

void Player::damageHP(int hpChange)
{
	hp -= hpChange;
}

/* ..............................................
  @brief damages the player
  
  @param change in HP
.............................................. */

void Player::healHP(int hpChange)
{
	hp += hpChange;
	if (hp > maxHP)
	{
		hp = maxHP;
	}
}
