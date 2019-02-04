/* ..............................................
  @file Update.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Update.hpp"

/* ..............................................
  SETTERS
  
.............................................. */

void Game::setIsComplete(bool isComplete)
{
    this->isComplete = isComplete;
}

void Game::setRoom(Room *room, int roomIndex)
{
    this->rooms[roomIndex] = room;
}

void Game::setNarrative(string narrative)
{
    this->narrative = narrative;
    devConsole.log(narrative);
}

void Game::setCurrentWindow(WINDOW *window)
{
    this->currentWindow = window;
}

/* ..............................................
  GETTERS
  
.............................................. */

bool Game::getIsComplete()
{
    return this->isComplete;
}

bool Game::isMoveAllowed(int y, int x)
{
    int testch;

    /* return true if the oom is okay to move into */
    testch = mvwinch(this->worldWindow, y, x);
    return (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY));
}

bool Game::isNotAWall(int y, int x) //not a wall or a door
{
    int testch = mvwinch(this->worldWindow, y, x);
    return (((testch & A_CHARTEXT) != WALL1) && ((testch & A_CHARTEXT) != WALL2) && ((testch & A_CHARTEXT) != WALL3) &&
            ((testch & A_CHARTEXT) != WALL4) && ((testch & A_CHARTEXT) != WALL5) && ((testch & A_CHARTEXT) != DOOR)); //if it is a wall, return false
}

unsigned int Game::getUserInput()
{
    return this->userInput;
}

Room *Game::getRoom(int roomIndex)
{
    return this->rooms[roomIndex];
}

string Game::getNarrative()
{
    return this->narrative;
}

WINDOW *Game::getCurrentWindow()
{
    return this->currentWindow;
}

/* ..............................................
  ACTIONS
  
.............................................. */
void Game::update()
{
    player.setIsMoved(false);
    switch (this->userInput)
    {
    case 'j':
    case 'J':
	{
            if (player.getSelectedItemIndex() > -1)
            {
                player.setEquippedItemIndex(player.getSelectedItemIndex());
            }
            break;
	}
    case KEY_UP:
    case 'w': 
    case 'W':
        if (this->getCurrentWindow() == this->inventoryWindow) //Inventory Management
        {
            if (player.getSelectedItemIndex() != 0)
            {
                player.setSelectedItemIndex(player.getSelectedItemIndex() - 1);
            }
            if (player.getInventoryItem(player.getSelectedItemIndex()) != NULL)
            {
                narrative = player.getInventoryItem(player.getSelectedItemIndex())->getDescription();
            }
            else
            {
                narrative = "an empty item slot";
            }
        }
        else //--------------------------- Player movement in worldWindow
        {
            player.setSymbol('^');
            if (player.getYPos() > 0)
            {
                if (isMoveAllowed(player.getYPos() - 1, player.getXPos())) //empty space
                {
                    player.move('w');
                    resolveDoorMovement();
                }
                else if (isNotAWall(player.getYPos() - 1, player.getXPos()))
                {
                    player.move('w');
                    resolveItemAction('w');
                }
            }
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        if (this->getCurrentWindow() == this->inventoryWindow) //inventory management
        {
            if (player.getSelectedItemIndex() != player.getMaxInventory() - 1)
            {
                player.setSelectedItemIndex(player.getSelectedItemIndex() + 1);
            }
            if (player.getInventoryItem(player.getSelectedItemIndex()) != NULL)
            {
                narrative = player.getInventoryItem(player.getSelectedItemIndex())->getDescription();
            }
            else
            {
                narrative = "an empty item slot";
            }
        }
        else //-------------------------Player Movement in worldWindow
        {
            player.setSymbol('v');
            if (player.getYPos() < LINES - 1)
            {
                if (isMoveAllowed(player.getYPos() + 1, player.getXPos())) //empty space
                {
                    player.move('s');
                    resolveDoorMovement();
                }
                else if (isNotAWall(player.getYPos() + 1, player.getXPos()))
                {
                    player.move('s');
                    resolveItemAction('s');
                }
            }
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        player.setSymbol('<');
        if (player.getXPos() > 0)
        {
            if (isMoveAllowed(player.getYPos(), player.getXPos() - 1)) //empty space
            {
                player.move('a');
                resolveDoorMovement();
            }
            else if (isNotAWall(player.getYPos(), player.getXPos() - 1))
            {
                player.move('a');
                resolveItemAction('a');
            }
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        player.setSymbol('>');
        if (player.getXPos() < COLS - 1)
        {
            if (isMoveAllowed(player.getYPos(), player.getXPos() + 1)) //empty space
            {
                player.move('d');
                resolveDoorMovement();
            }
            else if (isNotAWall(player.getYPos(), player.getXPos() + 1))
            {
                player.move('d');
                resolveItemAction('d');
            }
        }
        break;
    case 'i':
    case 'I':
        if (getCurrentWindow() == worldWindow)
        {
            setCurrentWindow(inventoryWindow);
            setNarrative("switched to inventory window!");
        }
        else if (getCurrentWindow() == inventoryWindow)
        {
            setCurrentWindow(worldWindow);
            setNarrative("switched to world window!");
        }
        break;
    case '`':
    case '~':
        if (getCurrentWindow() != developerWindow)
        {
            setCurrentWindow(developerWindow);
            setNarrative("switched to developer window!");
        }
        else
        {
            setCurrentWindow(worldWindow);
        }
        break;
    case 'e':
    case 'E':
        if (player.getSelectedItem() == NULL)
        {
            setNarrative("you do not have an item selected to use");
        }
        else if (player.getSelectedItem()->getType() == "key")
        {
                useKey();
        }
	else if(player.getSelectedItem()->getType() == "potion")
	{
		usePotion(player.getSelectedItem());
	}
        break;
    case 'p':
    case 'P':
	pickUpItem();
	break;
    case ';':
    case ':':
	dropItem();
	break;
    case 'q':
    case 'Q':
    {
	 string temp = getNarrative();
        setNarrative("Would you like to quit? Press Y to confirm or any other key to return to <Adventure Game>.");
        renderNarrative();
        unsigned int confirm = getch();
        if (confirm == 'y' || confirm == 'Y')
        {
            setIsComplete(true);
        }
        else
        {
            setNarrative(temp);
        }
	break;
    }
    }
}

void Game::resolveDoorMovement()
{
    // for possible doors in room
    Door **doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i = 0; i < 4; i++)
    {
        if (doors[i] != NULL)
        {
            if (player.getXPos() == doors[i]->getXPos() && player.getYPos() == doors[i]->getYPos() && doors[i]->getNextRoom() != -1)
            {
                player.setCurrentRoom(doors[i]->getNextRoom());
                player.setYPos(doors[i]->getNextYPos());
                player.setXPos(doors[i]->getNextXPos());
            }
        }
    }
}

void Game::useKey()
{
    bool keyIsUsed = false;

    // go through all of the doors in the room the player's in
    Door **doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
    {
        // if the door exists
        Door *door = doors[i];
        if (door != NULL)
        {
            // and if the player is next to the door
            if (abs(door->getYPos() - player.getYPos()) + abs(door->getXPos() - player.getXPos()) == 1)
            {
                // use the key on the door
                keyIsUsed = player.getSelectedItem()->use(door);
            }
        }
    }

    if (keyIsUsed)
    {
        setNarrative("you used the " + player.getSelectedItem()->getName());
    }
    else
    {
        setNarrative("the " + player.getSelectedItem()->getName() + " does not work here...");
    }
}

void Game::resolveHealing() //player walks on a potion
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getXPos() == items[i]->getXPos() && player.getYPos() == items[i]->getYPos()) //if x and y value match
            {
                if (player.getHP() < player.getMaxHP())
                {
                    player.healHP(items[i]->getHealing());
                }
                else
                    break;
            }
        }
    }
}

void Game::usePotion(Item* item)
{
        if (player.getHP() < player.getMaxHP())
        {
              player.healHP(item->getHealing());
	      setNarrative("You healed " + item->getHealing());
        }
	else
	      setNarrative("You feel great! Why would you want to heal?");
	
}

void Game::resolveDamage() //player walks on a trap
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getXPos() == items[i]->getXPos() && player.getYPos() == items[i]->getYPos()) //if x and y value match
            {
                player.damageHP(items[i]->getDamage());
            }
        }
    }
}

void Game::resolveMovingItem(char direction) //moving an item
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (direction == 'w')
            {
                if ((player.getYPos() == items[i]->getYPos()) && (player.getXPos() == items[i]->getXPos()))
                    items[i]->triggerItemActions('w');
            }
            if (direction == 's')
            {
                if ((player.getYPos() == items[i]->getYPos()) && (player.getXPos() == items[i]->getXPos()))
                    items[i]->triggerItemActions('s');
            }
            if (direction == 'a')
            {
                if ((player.getXPos() == items[i]->getXPos()) && (player.getYPos() == items[i]->getYPos()))
                    items[i]->triggerItemActions('a');
            }
            if (direction == 'd')
            {
                if ((player.getXPos() == items[i]->getXPos()) && (player.getYPos() == items[i]->getYPos()))
                    items[i]->triggerItemActions('d');
            }
        }
    }
}

void Game::resolveItemAction(char direction)
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getXPos() == items[i]->getXPos() && player.getYPos() == items[i]->getYPos()) //if x and y value match
            {
                //get the symbol, then resolve the action of the corresponding symbol
                if (items[i]->getSymbol() == 'P')
                    resolveHealing();
                else if (items[i]->getSymbol() == 'T')
                    resolveDamage();
                else if (items[i]->getSymbol() == 'M')
                {
                    if (direction == 'w')
                    {
                        if (isMoveAllowed(player.getYPos() - 1, player.getXPos())) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing(); //TODO: resolutionStep() or leave it?
                            resolveMovingItem(direction);
                        }
                        else
                            player.setYPos(player.getYPos() + 1); //item cannot be move, move the player back
                    }
                    if (direction == 's')
                    {
                        if (isMoveAllowed(player.getYPos() + 1, player.getXPos())) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction);
                        }
                        else
                            player.setYPos(player.getYPos() - 1); //item cannot be move, move the player back
                    }
                    if (direction == 'a')
                    {
                        if (isMoveAllowed(player.getYPos(), player.getXPos() - 1)) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction);
                        }
                        else
                            player.setXPos(player.getXPos() + 1); //item cannot be move, move the player back
                    }
                    if (direction == 'd')
                    {
                        if (isMoveAllowed(player.getYPos(), player.getXPos() + 1)) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction);
                        }
                        else
                            player.setXPos(player.getXPos() - 1); //item cannot be move, move the player back
                    }
                }
                else if (items[i]->getSymbol() == 'O')
                    break;
            }
        }
    }
}

void Game::pickUpItem() //player walks on a potion
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    bool pickedUpItem;
    Item* theItem;
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if(player.getSymbol() == '^')
	    {
		if(((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
		{
		     theItem = items[i];
		     pickedUpItem = player.pickUp(theItem);
		} 
	    }

	    else if(player.getSymbol() == 'v')   
	    {
		if(((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
		{
		     theItem = items[i];
		     pickedUpItem = player.pickUp(theItem);
		} 
	    }

	    else if(player.getSymbol() == '<')   
	    {
		if(((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
		{
		     theItem = items[i];
		     pickedUpItem = player.pickUp(theItem);
		} 
	    }

	    else
	    {
		if(((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
		{
		     theItem = items[i];
		     pickedUpItem = player.pickUp(theItem);
		} 
	    }
	
	    if (pickedUpItem) 
            {
            	setNarrative("You picked up the " + theItem->getName());
		theItem->setXPos(-1);
		theItem->setYPos(-1);
	    }
        }
    }
}

void Game::dropItem()
{
	Item* droppedItem = player.drop(player.getSelectedItemIndex());  //get the item that has been dropped
	Item** items = rooms[player.getCurrentRoom()]->getItems();		//get the items in the room
	int itemIndex = 0;							//index for item array
	bool itemHasBeenDropped = false;
	
	while ((itemHasBeenDropped == false)) //&& (itemIndex < rooms[player.getCurrentRoom()]->getMaxItems()))
	{
		if(items[itemIndex] != NULL) 
		{
			if(items[itemIndex]->getYPos() == player.getYPos() && items[itemIndex]->getXPos() == player.getXPos())
			{
				setNarrative("Item is already here. You cannot drop another here");
				break;
			}
		}
		else //items[i] == NULL
		{
			droppedItem->setXPos(player.getXPos());
			droppedItem->setYPos(player.getYPos());
			items[itemIndex] = droppedItem;
			itemHasBeenDropped = true;
		}
		itemIndex++;
	}
	if(itemHasBeenDropped == true)
	{
		setNarrative("You have dropped " + droppedItem->getName());
	}
	else
		setNarrative("You are unable to drop the item here");
}










