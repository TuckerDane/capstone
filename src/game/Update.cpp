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
    case KEY_UP:
    case 'w':
    case 'W':
        if (this->getCurrentWindow() == this->inventoryWindow)       //Inventory Management
        {
            if(player.getSelectedItemIndex() != 0)
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
        else                                        //--------------------------- Player movement in worldWindow
        {
            player.setSymbol('^');
            if(player.getYPos() > 0)
            {
	        if(isMoveAllowed(player.getYPos() - 1, player.getXPos()))  //empty space
                {
                    player.move('w');
                    resolveDoorMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos() - 1, player.getXPos()) & A_CHARTEXT) == POTION)
                {
                    player.move('w');
		    resolvePotionMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos() - 1, player.getXPos()) & A_CHARTEXT) == TRAP)
                {
                    player.move('w');
		    resolveTrapMovement();
                }
                else if(((mvwinch(this->worldWindow, player.getYPos() - 1, player.getXPos()) & A_CHARTEXT) == MOVABLE) && isMoveAllowed(player.getYPos() - 2, player.getXPos()))
                {
		    resolveMovingItem('w');   //move item
                    player.move('w');         //move player
                }
	    }
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        if (this->getCurrentWindow() == this->inventoryWindow)  //inventory management
        {
            if(player.getSelectedItemIndex() != player.getMaxInventory() -1)
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
        else					//-------------------------Player Movement in worldWindow
        {
            player.setSymbol('v');
            if(player.getYPos() < LINES - 1)
            {
	        if(isMoveAllowed(player.getYPos() + 1, player.getXPos()))  //empty space
                {
                    player.move('s');
                    resolveDoorMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos() + 1, player.getXPos()) & A_CHARTEXT) == POTION)
                {
                    player.move('s');
		    resolvePotionMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos() + 1, player.getXPos()) & A_CHARTEXT) == TRAP)
                {
                    player.move('s');
		    resolveTrapMovement();
                }
                else if(((mvwinch(this->worldWindow, player.getYPos() + 1, player.getXPos()) & A_CHARTEXT) == MOVABLE) && isMoveAllowed(player.getYPos() + 2, player.getXPos()))
                {
		    resolveMovingItem('s');   //move item
                    player.move('s');         //move player
                }
	    }
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        player.setSymbol('<');
        if(player.getXPos() > 0)
        {
	        if(isMoveAllowed(player.getYPos(), player.getXPos() - 1))  //empty space
                {
                    player.move('a');
                    resolveDoorMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() - 1) & A_CHARTEXT) == POTION)
                {
                    player.move('a');
		    resolvePotionMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() - 1) & A_CHARTEXT) == TRAP)
                {
                    player.move('a');
		    resolveTrapMovement();
                }
                else if(((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() - 1) & A_CHARTEXT) == MOVABLE) && isMoveAllowed(player.getYPos(), player.getXPos() - 2))
                {
		    resolveMovingItem('a');   //move item
                    player.move('a');         //move player
                }
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        player.setSymbol('>');
        if(player.getXPos() < COLS - 1)
        {
	        if(isMoveAllowed(player.getYPos(), player.getXPos() + 1))  //empty space
                {
                    player.move('d');
                    resolveDoorMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() + 1) & A_CHARTEXT) == POTION)
                {
                    player.move('d');
		    resolvePotionMovement();
                }
                else if((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() + 1) & A_CHARTEXT) == TRAP)
                {
                    player.move('d');
		    resolveTrapMovement();
                }
                else if(((mvwinch(this->worldWindow, player.getYPos(), player.getXPos() + 1) & A_CHARTEXT) == MOVABLE) && isMoveAllowed(player.getYPos(), player.getXPos() + 2))
                {
		    resolveMovingItem('d');   //move item
                    player.move('d');         //move player
                }
        }
        break;
    case 'i':
    case 'I':
        if (this->getCurrentWindow() == this->worldWindow)
        {
            this->setCurrentWindow(this->inventoryWindow);
            this->setNarrative("switched to inventory window!");
        }
        else if (this->getCurrentWindow() == this->inventoryWindow)
        {
            this->setCurrentWindow(this->worldWindow);
            this->setNarrative("switched to world window!    ");
        }
        break;
    case '`':
    case '~':
        if (this->getCurrentWindow() != this->developerWindow)
        {
            this->setCurrentWindow(this->developerWindow);
            this->setNarrative("switched to developer window!");
        }
        else
        {
            this->setCurrentWindow(this->worldWindow);
        }
        break;
    case 'e':
    case 'E':
        if(player.getSelectedItem() == NULL)
        {
            narrative = "you do not have an item selected to use";
        }
        else
        {
            if(player.getSelectedItem()->getType() == "key")
            {
                useKey();                  
            }
        }
        break;
    case 'q':
    case 'Q':
        string temp = getNarrative();
        this->setNarrative("Would you like to quit? Press Y to confirm or any other key to return to <Adventure Game>.");
        renderNarrative();
        unsigned int confirm = getch();
        if(confirm == 'y' || confirm == 'Y')
        {
            setIsComplete(true);
            break;
        }
        else
        {
            this->setNarrative(temp);
            break;
        }           
    }
}

void Game::resolveDoorMovement()
{
    // for possible doors in room
    Door** doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i=0; i<4; i++)
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
    Door** doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i=0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
    {
        // if the door exists
        Door* door = doors[i];
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
        narrative = "you used the " + player.getSelectedItem()->getName();
    }
    else
    {
        narrative = "the " + player.getSelectedItem()->getName() + " does not work here...";
    } 
}

void Game::resolvePotionMovement()  //player walks on a potion
{
	Item **items = rooms[player.getCurrentRoom()]->getItems();
	for(int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
	{
		if(items[i] != NULL)
		{
			if (player.getXPos() == items[i]->getXPos() && player.getYPos() == items[i]->getYPos()) //if x and y value match
			{
				if(player.getHP() < player.getMaxHP())
				{
					player.healHP(items[i]->getHealing());
				}
				else
					break;
			}
		}		
	}
}

void Game::resolveTrapMovement()  //player walks on a trap
{
	Item **items = rooms[player.getCurrentRoom()]->getItems();
	for(int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
	{
		if(items[i] != NULL)
		{
			if (player.getXPos() == items[i]->getXPos() && player.getYPos() == items[i]->getYPos()) //if x and y value match
			{
				player.damageHP(items[i]->getDamage());
			}
		}		
	}
}

void Game::resolveMovingItem(char direction)  //moving an item
{
	Item **items = rooms[player.getCurrentRoom()]->getItems();
	for(int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
	{
		if(items[i] != NULL)
		{
			if(direction == 'w')
			{
				if((player.getYPos() - 1 == items[i]->getYPos()) && (player.getXPos() == items[i]->getXPos()))
					items[i]->moveItem('w');
			}
			if(direction == 's')
			{
				if((player.getYPos() + 1 == items[i]->getYPos()) && (player.getXPos() == items[i]->getXPos()))
					items[i]->moveItem('s');
			}
			if(direction == 'a')
			{
				if((player.getXPos() - 1 == items[i]->getXPos()) && (player.getYPos() == items[i]->getYPos()))
					items[i]->moveItem('a');
			}
			if(direction == 'd')
			{
				if((player.getXPos() + 1 == items[i]->getXPos()) && (player.getYPos() == items[i]->getYPos()))
					items[i]->moveItem('d');
			}
		}
	}
}
