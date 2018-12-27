/* ..............................................
  @file Player.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Player.h"

/* ..............................................
  @brief Construct a new Player:: Player object
  
.............................................. */
Player::Player() : Object('^', "Tucker", 2, 2, "Player")
{
}

/* ..............................................
  @brief Construct a new Player:: Player object
  
  @param row 
  @param col 
  @param room 
  @param r 
.............................................. */
Player::Player(int row, int col, string room, int r) : Object('^', "Tucker", row, col, "Player")
{
	currentRoom = room;
	cRoom = r;
}

/* ..............................................
  @brief Destroy the Player:: Player object
  
.............................................. */
Player::~Player()
{
}

/* ..............................................
  @brief 
  
  @param s 
.............................................. */
void Player::setSymbol(char s)
{
	symbol = s;
}

/* ..............................................
  @brief 
  
  @param room 
  @param i 
.............................................. */
void Player::setPlayerRoom(string room, int i)
{
	currentRoom = room;
	cRoom = i;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Player::getPlayerRoom()
{
	return currentRoom;
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Player::getCRoom()
{
	return cRoom;
}

/* ..............................................
  @brief 
  
  @param o 
  @return true 
  @return false 
.............................................. */
bool Player::addObject(Object *o)
{
	if (o->getWeight() <= (this->maxCarry - this->weight)) // if the object doesn't weigh too much
	{
		if (this->numItems < 9) // and there is a slot for it in the backpack
		{
			bool found = false; // find an open (NULL) slot
			int index = 0;

			while (found == false) // conduct a linear search of the backpack for the slot
			{
				if (backpack[index] == NULL)
				{
					found = true;																	// when found, set to true
					backpack[index] = o;													// and set the object pointer to the address of the object
					this->numItems++;															// add to the item counter
					this->weight += backpack[index]->getWeight(); // add to the weight of the player
					return true;
				}
				index++;
			}
		}
	}
	return false;
}

/* ..............................................
  @brief 
  
.............................................. */
void Player::displayBackpack()
{
	cout << "\tYOU CAN CARRY UP TO 20 LBS" << endl;
	cout << "\tTHE FOLLOWING ARE THE ITEMS YOU HAVE IN YOUR BACKPACK: " << endl
			 << endl;
	cout << "\titem\tsymbol\tname\t\tweight\n";
	cout << "\t----\t------\t----\t\t------\n";

	for (int i = 0; i < 9; i++)
	{
		if (backpack[i] == NULL)
		{
			cout << "\t" << i + 1 << "\t\tOPEN SLOT\t" << endl;
		}
		else
		{
			cout << "\t" << i + 1 << "\t";																	 // item
			cout << backpack[i]->getSymbol() << "\t";												 // symbol
			cout << backpack[i]->getName() << " " << backpack[i]->getType(); // name
			cout << "\t" << backpack[i]->getWeight() << " lbs" << endl;			 // weight
		}
	}
	cout << endl;
	cout << "\tYOU ARE CURRENTLY CARRYING " << this->getWeight() << " LBS" << endl;
	cout << "\tPRESS E TO PICK UP ITEMS AND PUT THEM IN YOUR BACKPACK " << endl;
	cout << "\tPRESS THE CORRESPONDING NUMBER TO DROP ITEMS FROM YOUR BACKPACK " << endl
			 << endl;
}

/* ..............................................
  @brief 
  
  @param i 
  @return Object* 
.............................................. */
Object *Player::dropObject(int i)
{
	while (0 < i && i < 10) // if the player inputs a valid number
	{
		if (this->backpack[i - 1] == NULL) // if the number corresponds to an empty space in the pack
		{
			return NULL; // return NULL
		}
		else // else
		{
			Object *temp = backpack[i - 1]; // set the object in backpack to a temporary variable
			backpack[i - 1] = NULL;					// set the backpack slot to empty

			this->weight -= temp->getWeight(); // subtract the weight of the object from the player
			this->numItems--;									 // reduce the item counter
			return temp;											 // return the dropped item
		}
	}
	return NULL;
}

/* ..............................................
  @brief 
  
  @param i 
  @return string 
.............................................. */
string Player::checkObject(int i)
{
	while (0 < i && i < 10) // if the player inputs a valid number
	{
		if (this->backpack[i - 1] != NULL) // and it refers to a slot that is not null
		{
			if (this->backpack[i - 1]->getType() == "Stone") // and if the number corresponds to a stone
			{
				return this->backpack[i - 1]->getName(); // return the name of the stone (the color)
			}
			else // else
			{
				return "nocolor"; // return an invalid color
			}
		}
		else
		{
			return "nocolor";
		}
	}
	return "nocolor";
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Player::getWeight()
{
	return weight;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Player::getName()
{
	return name;
}

/* ..............................................
  @brief 
  
  @param w 
.............................................. */
void Player::setWeight(int w)
{
	weight = w;
}
