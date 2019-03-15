/* ..............................................
  @ file Update.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#include "Update.hpp"

/* ..............................................
  SETTERS
  
.............................................. */

void Game::setIsComplete(bool isComplete)
{
    this->isComplete = isComplete;
}

void Game::setPlanted(bool planted)
{
    this->planted = planted;
}

void Game::setRoom(Room *room, int roomIndex)
{
    this->rooms[roomIndex] = room;
}

void Game::setItemNarrative(string narrative)
{
    this->itemNarrative = narrative;
    devConsole.log(itemNarrative);
}

void Game::setWorldNarrative(string narrative)
{
    this->worldNarrative = narrative;
    devConsole.log(worldNarrative);
}

void Game::setCurrentWindow(WINDOW *window)
{
    this->currentWindow = window;
}

void Game::setBombY(int bombY)
{
    this->bombY = bombY;
}

void Game::setBombX(int bombX)
{
    this->bombX = bombX;
}

/* ..............................................
  GETTERS
  
.............................................. */

bool Game::getIsComplete()
{
    return this->isComplete;
}

bool Game::getPlanted()
{
    return this->planted;
}

int Game::getBombY()
{
    return this->bombY;
}

int Game::getBombX()
{
    return this->bombX;
}

bool Game::isEnemyMoveAllowed(int y, int x)
{
   int testch;

    /* return true if the oom is okay to move into */
    testch = mvwinch(this->worldWindow, y, x);
    
    if (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY))
    {
        return true;
    }
    return false;  
}

bool Game::isMoveAllowed(int y, int x)
{
    int testch;

    /* return true if the oom is okay to move into */
    testch = mvwinch(this->worldWindow, y, x);
    // if the space contains an item that you can walk on
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (items[i]->getYPos() == y && items[i]->getXPos() == x && items[i]->getType() != "immovable" && items[i]->getType() != "softblock" && items[i]->getType() != "snorlax"
													   && items[i]->getType() != "profoak" && items[i]->getType() != "statue")
            {
                return true;
            }
            else if (items[i]->getYPos() == y && items[i]->getXPos() == x && (items[i]->getType() == "immovable" || items[i]->getType() == "softblock" || items[i]->getType() == "snorlax"
														 || items[i]->getType() == "profoak" || items[i]->getType() == "statue"))
            {
                displayItemDescriptionToNarrativeWindow(items[i]);
            }
        }
    }
    // if the space is empty
    if (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY) || ((testch & A_CHARTEXT) == TELEPORTER))
    {
        return true;
    }
    return false;
}

bool Game::isItemMoveAllowed(int y, int x, char direction, Object* object)
{
    int testch;

    /* return true if the oom is okay to move into */
    testch = mvwinch(this->worldWindow, y, x);

    // if the space contains an item that you can walk on
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            // if an item is in the expected position
            if (items[i]->getYPos() == y && items[i]->getXPos() == x)
            {
                // and it is of type moveable 2
                if(items[i]->getType() == "movable2")
                {
                    // recurse
                    if (direction == 'w')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos() - 1, items[i]->getXPos(), direction, items[i])) //item can be moved
                        {   
                            resolveMovingItem(direction, items[i], object);
                            return true;
                        }
                    }
                    else if (direction == 's')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos() + 1, items[i]->getXPos(), direction, items[i])) //item can be moved
                        {
                            resolveMovingItem(direction, items[i], object);
                            return true;
                        }
                    }
                    else if (direction == 'a')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos(), items[i]->getXPos() - 1, direction, items[i])) //item can be moved
                        {
                            resolveMovingItem(direction, items[i], object);
                            return true;
                        }                       
                    }
                    else if (direction == 'd')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos(), items[i]->getXPos() + 1, direction, items[i])) //item can be moved
                        {
                            resolveMovingItem(direction, items[i], object);
                            return true;
                        }                       
                    }
                }
                else
                {
                    return false;
                }
                
            }
        }       
    }
    // if the space is empty
    if (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY))
    {
        return true;
    }
    return false;
}

Room *Game::getRoom(int roomIndex)
{
    return this->rooms[roomIndex];
}

string Game::getItemNarrative()
{
    return this->itemNarrative;
}

string Game::getWorldNarrative()
{
    return this->worldNarrative;
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
    updatePlayer();
    updateEnemies();
}

void Game::updatePlayer()
{
    player.setIsMoved(false);
    Door **doors = rooms[player.getCurrentRoom()]->getDoors();
    Teleporter **teleporters =  rooms[player.getCurrentRoom()]->getTeleporters();
    if (getPlanted() == true)
        animateBomb(doors, teleporters);
    switch (player.getPlayerInput())
    {
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
                    setItemNarrative(player.getInventoryItem(player.getSelectedItemIndex())->getDescription());
                }
                else
                {
                    setItemNarrative("an empty item slot");
                }
            }
            else //--------------------------- Player movement in worldWindow
            {
                player.setSymbol("^");
                if (player.getYPos() > 0)
                {
                    if (isMoveAllowed(player.getYPos() - 1, player.getXPos())) //empty space
                    {
                        player.move('w');
                        resolveDoorMovement();
                        resolveItemAction('w');
          		        resolveTeleporterMovement();
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
                    setItemNarrative(player.getInventoryItem(player.getSelectedItemIndex())->getDescription());
                }
                else
                {
                    setItemNarrative("an empty item slot");
                }
            }
            else //-------------------------Player Movement in worldWindow
            {
                player.setSymbol("v");
                if (player.getYPos() < LINES - 1)
                {
                    if (isMoveAllowed(player.getYPos() + 1, player.getXPos())) //empty space
                    {
                        player.move('s');
                        resolveDoorMovement();
                        resolveItemAction('s');
                        resolveTeleporterMovement();
                    }
                }
            }
            break;
        case KEY_LEFT:
        case 'a':
        case 'A':
            player.setSymbol("<");
            if (player.getXPos() > 0)
            {
                if (isMoveAllowed(player.getYPos(), player.getXPos() - 1)) //empty space
                {
                    player.move('a');
		    if(player.getCurrentRoom() == 7 || player.getCurrentRoom() == 10) //gravity. Move sideways then down if possible
		    {
			if(isMoveAllowed(player.getYPos() + 1, player.getXPos()))
			   player.move('s');
		    }
                    resolveDoorMovement();
                    resolveItemAction('a');
                    resolveTeleporterMovement();
                }
            }
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            player.setSymbol(">");
            if (player.getXPos() < COLS - 1)
            {
                if (isMoveAllowed(player.getYPos(), player.getXPos() + 1)) //empty space
                {
                    player.move('d');
		    if(player.getCurrentRoom() == 7 || player.getCurrentRoom() == 10) //gravity. Move sideways then down if possible
		    {
			if(isMoveAllowed(player.getYPos() + 1, player.getXPos()))
			   player.move('s');
		    }
                    resolveDoorMovement();
                    resolveItemAction('d');
		            resolveTeleporterMovement();
                }
            }
            break;
        case 'i':
        case 'I':
            if (getCurrentWindow() == worldWindow)
            {
                setCurrentWindow(inventoryWindow);
                if (player.getSelectedItem() == NULL)
                {
                    setItemNarrative("This is an empty slot!");
                }
                else
                {
                    setItemNarrative(player.getSelectedItem()->getDescription());
                }
            }
            else if (getCurrentWindow() == inventoryWindow)
            {
                setCurrentWindow(worldWindow);
            }
            break;
        case '`':
        case '~':
            if (getCurrentWindow() != developerWindow)
            {
                setCurrentWindow(developerWindow);
            }
            else
            {
                setCurrentWindow(worldWindow);
            }
            break;
        case 'e':
        case 'E':
            if (currentWindow == worldWindow)
            {
                if (player.getEquippedItem() == NULL)
                {
                    setItemNarrative("you do not have an item selected to use");
                }
                else if (player.getEquippedItem()->getType() == "key")
                {
                    useKey();
                }
                else if (player.getEquippedItem()->getType() == "potion")
                {
                    usePotion(player.getEquippedItem());
                }
                else if (player.getEquippedItem()->getType() == "poke_flute")
                {
                    resolveSnorlax();
                }
                else if (player.getEquippedItem()->getType() == "poke_ball")
                {
                    usePokeball();
                }
                else if (player.getEquippedItem()->getType() == "bomb")
                {
                    if (player.getCurrentRoom() == 6)
                       plantBomb(player.getYPos(), player.getXPos(), doors, teleporters);
                    else
                        setItemNarrative("This isn't safe to use here.");                    
                }
                else if (player.getEquippedItem()->getType() == "snorlax")
                {
                    giveProfOakSnorlax();
                }
            }
            else if (currentWindow == inventoryWindow)
            {
                if (player.getSelectedItemIndex() > -1)
                {
                    player.setEquippedItemIndex(player.getSelectedItemIndex());
                }
            }
            break;
        case 'p':
        case 'P':
            pickUpItem();
            break;
	case 'r':
	case 'R':
	    readItem();
	    if(player.getCurrentRoom() == 13)
	    {
		combineCubeParts();
	    } 
	    break;
        case ';':
        case ':':
            dropItem();
            break;
        case 'q':
        case 'Q':
        {
            setWorldNarrative("Would you like to quit? Press Y to confirm or N to return to <Adventure Game>.");
            renderNarrative();
            unsigned int confirm = 'a';
            while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
            {
                confirm = getch();
                if (confirm == 'y' || confirm == 'Y')
                {
                    setWorldNarrative("You Quit the Game");
                    setIsComplete(true);
                }
            }
            break;
        }
    }
    if (player.getHP() < 1)
    {
        setWorldNarrative("GAME OVER: You Died");
        isComplete = true;
    }
}

void Game::updateEnemies()
{
    Enemy **enemies = rooms[player.getCurrentRoom()]->getEnemies();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxEnemies(); i++)
    {
        if (enemies[i] != NULL)
        {
            enemies[i]->setIsMoved(false);
            switch (enemies[i]->processMove())
            {
            case KEY_UP:
            case 'w':
            case 'W':
                enemies[i]->setSymbol("^");
                // if the enemy moves into the player, deal damage
                if (enemies[i]->getYPos() - 1 == player.getYPos() && enemies[i]->getXPos() == player.getXPos())
                {
                    player.damageHP(enemies[i]->getDamage());
                }
                // move the enemy
                if ((enemies[i]->getYPos() > 0) && isEnemyMoveAllowed(enemies[i]->getYPos() - 1, enemies[i]->getXPos()))
                {
                    enemies[i]->move('w');
                }
                break;
            case KEY_DOWN:
            case 's':
            case 'S':
                enemies[i]->setSymbol("v");
                // if the enemy moves into the player, deal damage
                if (enemies[i]->getYPos() + 1 == player.getYPos() && enemies[i]->getXPos() == player.getXPos())
                {
                    player.damageHP(enemies[i]->getDamage());
                }
                // move the enemy
                if ((enemies[i]->getYPos() < LINES - 1) && isEnemyMoveAllowed(enemies[i]->getYPos() + 1, enemies[i]->getXPos()))
                {
                    enemies[i]->move('s');
                }
                break;
            case KEY_LEFT:
            case 'a':
            case 'A':
                enemies[i]->setSymbol("<");
                // if the enemy moves into the player, deal damage
                if (enemies[i]->getYPos() == player.getYPos() && enemies[i]->getXPos() - 1 == player.getXPos())
                {
                    player.damageHP(enemies[i]->getDamage());
                }
                // move the enemy
                if ((enemies[i]->getXPos() > 0) && isEnemyMoveAllowed(enemies[i]->getYPos(), enemies[i]->getXPos() - 1))
                {
                    enemies[i]->move('a');
                }
                break;
            case KEY_RIGHT:
            case 'd':
            case 'D':
                enemies[i]->setSymbol(">");
                // if the enemy moves into the player, deal damage
                if (enemies[i]->getYPos() == player.getYPos() && enemies[i]->getXPos() + 1 == player.getXPos())
                {
                    player.damageHP(enemies[i]->getDamage());
                }
                // move the enemy
                if ((enemies[i]->getXPos() < COLS - 1) && isEnemyMoveAllowed(enemies[i]->getYPos(), enemies[i]->getXPos() + 1))
                {
                    enemies[i]->move('d');
                }
                break;
            }
        }
    }
}

void Game::resolveDoorMovement()
{
    // for possible doors in room
    Door **doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
    {
        if (doors[i] != NULL)
        {
            if (player.getXPos() == doors[i]->getXPos() && player.getYPos() == doors[i]->getYPos() && doors[i]->getNextRoom() != -1)
            {
                priorRoomIndex = i;
                player.setCurrentRoom(doors[i]->getNextRoom());
                player.setYPos(doors[i]->getNextYPos());
                player.setXPos(doors[i]->getNextXPos());
                currentRoomIndex = player.getCurrentRoom();
            }
        }
    }
}

void Game::resolveTeleporterMovement()
{  
    Teleporter **teleporters = rooms[player.getCurrentRoom()]->getTeleporters();
    for (int i = 0; i < 64; i++)
    {
        if (teleporters[i] != NULL)
        {
            if(player.getXPos() == teleporters[i]->getXPos() && player.getYPos() == teleporters[i]->getYPos() && teleporters[i]->getNextRoom() != -1)
            {
                priorRoomIndex = i;
                player.setCurrentRoom(teleporters[i]->getNextRoom());
                player.setYPos(teleporters[i]->getNextYPos());
                player.setXPos(teleporters[i]->getNextXPos());
                currentRoomIndex = player.getCurrentRoom();
            }
        }
    }
}

void Game::useKey()
{
    bool keyIsUsed = false;
    Door *firstDoor;
    // go through all of the doors in the room the player's in
    Door **doors = rooms[player.getCurrentRoom()]->getDoors();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
    {
        // if the door exists
        Door *door = doors[i];
        if (door != NULL)
        {
            // and if the player is facing to the door
            if (player.getSymbol() == "^")
            { //door location  ==  modified player location
                if (((doors[i]->getYPos()) == player.getYPos() - 1) && doors[i]->getXPos() == player.getXPos())
                {
                    // use the key on the door
                    keyIsUsed = player.getEquippedItem()->use(door);
                    firstDoor = door;
                }
            }
            else if (player.getSymbol() == "v")
            {
                if (((doors[i]->getYPos()) == player.getYPos() + 1) && doors[i]->getXPos() == player.getXPos())
                {
                    // use the key on the door
                    keyIsUsed = player.getEquippedItem()->use(door);
                    firstDoor = door;
                }
            }
            else if (player.getSymbol() == "<")
            {
                if (((doors[i]->getYPos()) == player.getYPos()) && doors[i]->getXPos() == player.getXPos() - 1)
                {
                    // use the key on the door
                    keyIsUsed = player.getEquippedItem()->use(door);
                    firstDoor = door;
                }
            }
            else //player.getSymbol() == ">"
            {
                if (((doors[i]->getYPos()) == player.getYPos()) && doors[i]->getXPos() == player.getXPos() + 1)
                {
                    // use the key on the door
                    keyIsUsed = player.getEquippedItem()->use(door);
                    firstDoor = door;
                }
            }
        }
    }

    if (keyIsUsed)
    {
        setItemNarrative("you used the " + player.getEquippedItem()->getName());
        if (firstDoor->getNextRoom() != -1)
            useKeyOnOppositeDoor(firstDoor);
    }
    else
    {
        setItemNarrative("the " + player.getEquippedItem()->getName() + " does not work here...");
    }
}

void Game::useKeyOnOppositeDoor(Door *firstDoor)
{
    // go through all of the doors in the room the player's in
    Door **doors = rooms[firstDoor->getNextRoom()]->getDoors();
    for (int i = 0; i < rooms[firstDoor->getNextRoom()]->getMaxDoors(); i++)
    {
        if (doors[i] != NULL)
        {
            if (player.getSymbol() == "^")
            { //new door location		where player is
                if (((doors[i]->getYPos() - 1) == firstDoor->getNextYPos()) && doors[i]->getXPos() == firstDoor->getNextXPos())
                    player.getEquippedItem()->use(doors[i]);
            }
            else if (player.getSymbol() == "v")
            {
                if (((doors[i]->getYPos() + 1) == firstDoor->getNextYPos()) && doors[i]->getXPos() == firstDoor->getNextXPos())
                    player.getEquippedItem()->use(doors[i]);
            }
            else if (player.getSymbol() == "<")
            {
                if (((doors[i]->getXPos() - 1) == firstDoor->getNextXPos()) && doors[i]->getYPos() == firstDoor->getNextYPos())
                    player.getEquippedItem()->use(doors[i]);
            }
            else //player.getSymbol() == ">"
            {

                if (((doors[i]->getXPos() + 1) == firstDoor->getNextXPos()) && doors[i]->getYPos() == firstDoor->getNextYPos())
                    player.getEquippedItem()->use(doors[i]);
            }
        }
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

void Game::usePotion(Item *item)
{
    if (player.getHP() < player.getMaxHP())
    {
        player.healHP(item->getHealing());
        setItemNarrative("You healed " + item->getHealing());
    }
    else
        setItemNarrative("You feel great! Why would you want to heal?");
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

void Game::resolveSnorlax()
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getSymbol() == "^")
            {
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
				    if (items[i]->getYPos() == 6 && items[i]->getXPos() == 6 && (items[i]->getType() == "snorlax") ) // if Snorlax is in starting position
                    {
                        items[i]->setYPos(5);
                        items[i]->setXPos(7);
                        items[i]->setDescription("The Pokédex says: Very lazy. Just eats and sleeps.");
                        setItemNarrative("You played the Poké Flute. SNORLAX woke up!");
                    }
				}
			}
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
		            if (items[i]->getYPos() == 6 && items[i]->getXPos() == 6 && (items[i]->getType() == "snorlax") ) // if Snorlax is in starting position
                    {
                        items[i]->setYPos(5);
                        items[i]->setXPos(7);
                        items[i]->setDescription("The Pokédex says: Very lazy. Just eats and sleeps.");
                        setItemNarrative("You played the Poké Flute. SNORLAX woke up!");
                    }
				}
			}
			else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
                    if (items[i]->getYPos() == 6 && items[i]->getXPos() == 6 && (items[i]->getType() == "snorlax") ) // if Snorlax is in starting position
                    {
                        items[i]->setYPos(5);
                        items[i]->setXPos(7);
                        items[i]->setDescription("The Pokédex says: Very lazy. Just eats and sleeps.");
                        setItemNarrative("You played the Poké Flute. SNORLAX woke up!");
                    }
				}
			}
			else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
                    if (items[i]->getYPos() == 6 && items[i]->getXPos() == 6 && (items[i]->getType() == "snorlax") ) // if Snorlax is in starting position
                    {
                        items[i]->setYPos(5);
                        items[i]->setXPos(7);
                        items[i]->setDescription("The Pokédex says: Very lazy. Just eats and sleeps.");
                        setItemNarrative("You played the Poké Flute. SNORLAX woke up!");
                    }
				}
			}
        }
    }
}

void Game::usePokeball()
{
    bool snorlaxMoved = false;
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getSymbol() == "^")
            {
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
                    if (items[i]->getYPos() == 5 && items[i]->getXPos() == 7 && (items[i]->getType() == "snorlax") ) // if Snorlax is in second position
                    {
                        snorlaxMoved = true;
                        items[i]->setWeight(1);
                        bool pickedUp = player.pickUp(items[i]);
                        if (pickedUp)
                        {
                            items[i] = NULL;
                        }
                        dropItem();
                        setItemNarrative("You threw a Pokéball...    You caught SNORLAX!     SNORLAX was added to you inventory.");
                    }
                }
            }
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
				    if (items[i]->getYPos() == 5 && items[i]->getXPos() == 7 && (items[i]->getType() == "snorlax") ) // if Snorlax is in second position
                    {
                        snorlaxMoved = true;
                        items[i]->setWeight(1);
                        bool pickedUp = player.pickUp(items[i]);
                        if (pickedUp)
                        {
                            items[i] = NULL;
                        }
                        dropItem();
                        setItemNarrative("You threw a Pokéball...    You caught SNORLAX!     SNORLAX was added to you inventory.");
                    }
				}
			}
			else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
				    if (items[i]->getYPos() == 5 && items[i]->getXPos() == 7 && (items[i]->getType() == "snorlax") ) // if Snorlax is in second position
                    {
                        snorlaxMoved = true;
                        items[i]->setWeight(1);
                        bool pickedUp = player.pickUp(items[i]);
                        if (pickedUp)
                        {
                            items[i] = NULL;
                        }
                        dropItem();
                        setItemNarrative("You threw a Pokéball...    You caught SNORLAX!     SNORLAX was added to you inventory.");
                    }
				}
			}
			else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
				    if (items[i]->getYPos() == 5 && items[i]->getXPos() == 7 && (items[i]->getType() == "snorlax") ) // if Snorlax is in second position
                    {
                        snorlaxMoved = true;
                        items[i]->setWeight(1);
                        bool pickedUp = player.pickUp(items[i]);
                        if (pickedUp)
                        {
                            items[i] = NULL;
                        }
                        dropItem();
                        setItemNarrative("You threw a Pokéball...    You caught SNORLAX!     SNORLAX was added to you inventory.");
                    }
				}
			}
        }
    }
    if (snorlaxMoved == false)
    {
        setItemNarrative("That wasn't a good throw.");
    }
}

void Game::resolveMovingItem(char direction, Item* item, Object* object) //moving an item
{
    if (direction == 'w')
    {
        item->triggerItemActions('w');
    }
    if (direction == 's')
    {
        item->triggerItemActions('s');
    }
    if (direction == 'a')
    {
        item->triggerItemActions('a');
    }
    if (direction == 'd')
    {
        item->triggerItemActions('d');
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
                if (items[i]->getType() == "potion")
                {
                    resolveHealing();
                }
                else if (items[i]->getType() == "trap")
                {
                    resolveDamage();
                }
                else if (items[i]->getType() == "movable" || items[i]->getType() == "movable2")
                {
                    if (direction == 'w')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos() - 1, items[i]->getXPos(), direction, items[i])) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction, items[i], &player);
                        }
                        else
                        {
                            player.setYPos(player.getYPos() + 1); //item cannot be move, move the player back
                        }
                    }
                    if (direction == 's')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos() + 1, items[i]->getXPos(), direction, items[i])) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction, items[i], &player);
                        }
                        else
                        {
                            player.setYPos(player.getYPos() - 1); //item cannot be move, move the player back
                        }
                    }
                    if (direction == 'a')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos(), items[i]->getXPos() - 1, direction, items[i])) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction, items[i], &player);
                        }
                        else
                        {
                            player.setXPos(player.getXPos() + 1); //item cannot be move, move the player back
                        }
                    }
                    if (direction == 'd')
                    {
                        if (isItemMoveAllowed(items[i]->getYPos(), items[i]->getXPos() + 1, direction, items[i])) //item can be moved
                        {
                            resolveDamage();
                            resolveHealing();
                            resolveMovingItem(direction, items[i], &player);
                        }
                        else
                        {
                            player.setXPos(player.getXPos() - 1); //item cannot be move, move the player back
                        }
                    }
                }
                else if (items[i]->getType() == "softblock")
                {
                    break;
                }
                else if (items[i]->getType() == "immovable")
                    break;
            }
        }
    }
}

void Game::pickUpItem()
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    bool pickedUpItem = false;
    bool isAnItem = false;
    Item *theItem;
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getSymbol() == "^")
            {
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
                    isAnItem = true;
                    theItem = items[i];
                    pickedUpItem = player.pickUp(theItem);
                    if (pickedUpItem)
                    {
                        items[i] = NULL;
                    }
                }
            }
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos())
                {
                    isAnItem = true;
                    theItem = items[i];
                    pickedUpItem = player.pickUp(theItem);
                    if (pickedUpItem)
                    {
                        items[i] = NULL;
                    }
                }
            }

            else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
                    isAnItem = true;
                    theItem = items[i];
                    pickedUpItem = player.pickUp(theItem);
                    if (pickedUpItem)
                    {
                        items[i] = NULL;
                    }
                }
            }
            else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos())
                {
                    isAnItem = true;
                    theItem = items[i];
                    pickedUpItem = player.pickUp(theItem);
                    if (pickedUpItem)
                    {
                        items[i] = NULL;
                    }
                }
            }
        }
    }
    if (pickedUpItem)
    {
        setItemNarrative("You picked up the " + theItem->getName());
        theItem->setXPos(-1);
        theItem->setYPos(-1);
	if(theItem->getType() == "cubepart")
	{
	    player.increaseNumCubeParts();
	}
    }
    else if (!isAnItem)
    {
        setItemNarrative("There is nothing there to pick up");
    }
    else
    {
        setItemNarrative("You could not pick up the " + theItem->getName());
    }
}

void Game::dropItem()
{
    Item *droppedItem;
    Item **items = rooms[player.getCurrentRoom()]->getItems(); //get the items in the room
    int itemIndex = 0;                                         //index for item array
    bool itemHasBeenDropped = false;
    while ((itemHasBeenDropped == false))
    {
        if (items[itemIndex] != NULL) //if there is an item
        {
            if (items[itemIndex]->getYPos() == player.getYPos() && items[itemIndex]->getXPos() == player.getXPos()) //make sure it is not under the player
            {
                setItemNarrative("Item is already here. You cannot drop another here");
                break;
            }
        }
        else //items[i] == NULL and can be dropped
        {
            droppedItem = player.drop(player.getSelectedItemIndex()); //get the item that has been dropped
            if (droppedItem == NULL)                                  //dropping a null
            {
                setItemNarrative("You are unable to drop an empty slot in your bag.");
                break;
            }
            droppedItem->setXPos(player.getXPos());
            droppedItem->setYPos(player.getYPos());
            items[itemIndex] = droppedItem;
	    if(droppedItem->getType() == "cubepart")
	    {
		player.decreaseNumCubeParts();
	    }
            itemHasBeenDropped = true;
        }
        itemIndex++;
    }
    if (itemHasBeenDropped == true)
    {
        setItemNarrative("You have dropped " + droppedItem->getName());
    }
}

void Game::displayItemDescriptionToNarrativeWindow(Item *item){
    string narr = item->getDescription();
    setItemNarrative(narr);
}

void Game::readItem()
{
    Item** items = rooms[player.getCurrentRoom()]->getItems();

    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (player.getSymbol() == "^")
            {
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && (items[i]->getType() == "statue" || items[i]->getType() == "profoak"))
                {
		            setItemNarrative(items[i]->getDescription());
                }
            }
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && (items[i]->getType() == "statue" || items[i]->getType() == "profoak"))
                {
		            setItemNarrative(items[i]->getDescription());
                }
            }

            else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && (items[i]->getType() == "statue" || items[i]->getType() == "profoak"))
                {
		            setItemNarrative(items[i]->getDescription());
                }
            }
            else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && (items[i]->getType() == "statue" || items[i]->getType() == "profoak"))
                {
		            setItemNarrative(items[i]->getDescription());
                }
            }
        }
    }
}

void Game::resolveBomb()
{
    Item** items = rooms[player.getCurrentRoom()]->getItems();
    for(int i=0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            // delete softblocks surrounding bomb
            if ( ((getBombY()-1) == items[i]->getYPos()) && (getBombX() == items[i]->getXPos()) && (items[i]->getType() == "softblock") ) // if softblock is above
            {
                delete items[i];
                items[i] = NULL;
            }
            else if ( ((getBombY()+1) == items[i]->getYPos()) && (getBombX() == items[i]->getXPos()) && (items[i]->getType() == "softblock") ) // if softblock is below
            {
                delete items[i];
                items[i] = NULL;
            }
            else if ( (getBombY() == items[i]->getYPos()) && ((getBombX()-1) == items[i]->getXPos()) && (items[i]->getType() == "softblock") ) // if softblock is to left
            {
                delete items[i];
                items[i] = NULL;
            }
            else if ( (getBombY() == items[i]->getYPos()) && ((getBombX()+1) == items[i]->getXPos()) && (items[i]->getType() == "softblock") ) // if softblock is to right
            {
                delete items[i];
                items[i] = NULL;
            }
        }
    }
}

void Game::giveProfOakSnorlax()
{
    Item **inventory = player.getInventory();
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    bool hasSnorlax = false;
    for (int i = 0; i < player.getMaxInventory(); i++)
    {
        if (inventory[i] != NULL)
        {
            if (inventory[i]->getType() == "snorlax")
            {
                hasSnorlax = true;
                inventory[i]->setName("Magikarp");
                inventory[i]->setDescription("Famous for being very unreliable. Thanks a lot Professor Oak.");
                inventory[i]->setSymbol("ᶬ");
            }
        }
    }

    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL && hasSnorlax == true)
        {
            if (player.getSymbol() == "^")
            {
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && items[i]->getType() == "profoak")
                {
                    items[i]->setDescription("How is my old Pokémon? Well, it seems to like you a lot.");
                    setItemNarrative("Professor Oak gave you a Magikarp...laaame.");
                    
				}
			}
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && items[i]->getType() == "profoak")
                {
                    items[i]->setDescription("How is my old Pokémon? Well, it seems to like you a lot.");
                    setItemNarrative("Professor Oak gave you a Magikarp...laaame.");
                    
				}
			}
			else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && items[i]->getType() == "profoak")
                {
                    items[i]->setDescription("How is my old Pokémon? Well, it seems to like you a lot.");
                    setItemNarrative("Professor Oak gave you a Magikarp...laaame.");
                    
				}
			}
			else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && items[i]->getType() == "profoak")
                {
                    items[i]->setDescription("How is my old Pokémon? Well, it seems to like you a lot.");
                    setItemNarrative("Professor Oak gave you a Magikarp...laaame.");
				}
			}
        }
    }
    
    if (hasSnorlax == true)
    {
        for (int i = 0; i < player.getMaxInventory(); i++)
        {
            if (inventory[i] != NULL)
            {
                if (inventory[i]->getType() == "snorlax")
                {
                    inventory[i]->setName("Magikarp");
                    inventory[i]->setDescription("Famous for being very unreliable. Thanks a lot Professor Oak.");
                    inventory[i]->setSymbol("ᶬ");
                }
            }
        }
    }
}

void Game::plantBomb(int y, int x, Door **doors, Teleporter **teleporters)
{
    if (getPlanted() == true)
    {
        setItemNarrative("There is already a bomb waiting to explode!");
    }
    else
    {    
        Item **items = rooms[player.getCurrentRoom()]->getItems(); //get the items in the room
        int itemIndex = rooms[player.getCurrentRoom()]->getItemsSize(); //index for item array
        bool bombHasBeenDropped = false;
        while ((bombHasBeenDropped == false))
        {
            if (items[itemIndex] != NULL) //if there is an item
            {
                if (items[itemIndex]->getYPos() == y && items[itemIndex]->getXPos() == x) //make sure it is not under the player
                {
                    setItemNarrative("Item is already here. You cannot drop another here");
                    break;
                }
                itemIndex++;
            }
            else //items[i] == NULL and can be planted
            {
                rooms[player.getCurrentRoom()]->setItem(new Bomb(y, x), ++itemIndex);
                bombHasBeenDropped = true;
            }
        }
        if (bombHasBeenDropped == true)
        {
            // lock doors and keep teleports from letting player leave room
            for(int i=0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
            {
                if (doors[i] != NULL)
                {
                    doors[i]->setNextRoom(6);
                    doors[i]->setNextYPos(2);
                    doors[i]->setNextXPos(12);
                }
            }
            for(int i=0; i < rooms[player.getCurrentRoom()]->getMaxTeleporters(); i++)
            {
                if(teleporters[i] != NULL)
                {
                    teleporters[i]->setNextRoom(6);
                    teleporters[i]->setNextYPos(2);
                    teleporters[i]->setNextXPos(12);
                }
            }
            setPlanted(true);
            setBombY(y);
            setBombX(x);
            setItemNarrative("You have planted a bomb. Run!");
            begin_time = clock();
        }
    }
}

void Game::animateBomb(Door **doors, Teleporter **teleporters)
{
    int bombIndex;  // figure out which item is bomb
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if(items[i]->getType() == "bomb")
            {
                bombIndex = i;
            }
        }
    }

    elapsedSeconds = ((double)(clock () - begin_time)) /  CLOCKS_PER_SEC;
    if (elapsedSeconds <= 0.75)
    {
        items[bombIndex]->setSymbol("❸");
    }
    else if (elapsedSeconds > 0.75 && elapsedSeconds <= 1.5)
    {
        items[bombIndex]->setSymbol("❷");
    }
    else if (elapsedSeconds > 1.5 && elapsedSeconds <= 2.25)
    {
        items[bombIndex]->setSymbol("❶");
    }
    else if (elapsedSeconds > 2.25)
    {
        resolveBomb();
        setPlanted(false);
        delete items[bombIndex];
        items[bombIndex] = NULL;
    }

    if (hasBeenDamaged == false && (elapsedSeconds > 2.25 && elapsedSeconds <= 3))
    {
        // if player is within range of bomb, apply 3 damage
        if (player.getYPos() == getBombY() && player.getXPos() == getBombX())   // player is on bomb
        {
            player.damageHP(3);
            hasBeenDamaged = true;
            setItemNarrative("Ouch, better be more careful.");
        }
        else if (player.getYPos() == getBombY() && player.getXPos() == getBombX()-1)  // player is on immediate left of bomb
        {
            player.damageHP(3);
            hasBeenDamaged = true;
            setItemNarrative("Ouch, better be more careful.");
        }
        else if (player.getYPos() == getBombY() && player.getXPos() == getBombX()+1)  // player is on immediate right of bomb
        {
            player.damageHP(3);
            hasBeenDamaged = true;
            setItemNarrative("Ouch, better be more careful.");
        }
        else if (player.getYPos() == getBombY()-1 && player.getXPos() == getBombX())  // player is immediately above bomb
        {
            player.damageHP(3);
            hasBeenDamaged = true;
            setItemNarrative("Ouch, better be more careful.");
        }
        else if (player.getYPos() == getBombY()+1 && player.getXPos() == getBombX())  // player is immediately below bomb
        {
            player.damageHP(3);
            hasBeenDamaged = true;
            setItemNarrative("Ouch, better be more careful.");
        }
        setPlanted(false);        
        delete items[bombIndex];
        items[bombIndex] = NULL;

        // reset doors and teleporters
        for(int i=0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
        {
            if (doors[i] != NULL)
            {
                doors[i]->setNextRoom(3);
                doors[i]->setNextYPos(6);
                doors[i]->setNextXPos(2);
            }
        }
        for(int i=0; i < rooms[player.getCurrentRoom()]->getMaxTeleporters(); i++)
        {
            if(teleporters[i] != NULL)
            {
                teleporters[i]->setNextRoom(11);
                teleporters[i]->setNextYPos(13);
                teleporters[i]->setNextXPos(78);
            }
        }
    }
    else if (hasBeenDamaged == true && (elapsedSeconds < 2.25 || elapsedSeconds > 3))
    {
        hasBeenDamaged = false;
    } 
}

void Game::combineCubeParts()
{
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for(int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
	if(items[i] != NULL)
	{
	    if(player.getSymbol() == "^")
	    {
		if(items[i]->getYPos() == player.getYPos() - 1 && items[i]->getXPos() == player.getXPos() && items[i]->getType() == "statue")
		{
		    if(player.getNumCubeParts() == 5)
		    {
                setItemNarrative("");
  		        setWorldNarrative("You combine all of the Pandora's Cube pieces. You step back through a portal back into your own room and go down and get breakfast.");
		        isComplete = true; 
		    }
		    else if(player.getNumCubeParts() < 5 && player.getNumCubeParts() > -1)
		    {
 		       setItemNarrative("You appear to still be missing pieces. The repair station suggest you need 5.");
		    }
		}
	    }
	    else if(player.getSymbol() == "v")
	    {
		if(items[i]->getYPos() == player.getYPos() + 1 && items[i]->getXPos() == player.getXPos() && items[i]->getType() == "statue")
		{
		    if(player.getNumCubeParts() == 5)
		    {
                setItemNarrative("");
  		        setWorldNarrative("You combine all of the Pandora's Cube pieces. You step back through a portal back into your own room and go down and get breakfast.");
		        isComplete = true; 
		    }
		    else if(player.getNumCubeParts() < 5 && player.getNumCubeParts() > -1)
		    {
 		       setItemNarrative("You appear to still be missing pieces. The repair station suggest you need 5.");
		    }
		}
	    }
	    if(player.getSymbol() == "<")
	    {
		if(items[i]->getYPos() == player.getYPos() && items[i]->getXPos() == player.getXPos() - 1 && items[i]->getType() == "statue")
		{
		    if(player.getNumCubeParts() == 5)
		    {
                setItemNarrative("");
  		        setWorldNarrative("You combine all of the Pandora's Cube pieces. You step back through a portal back into your own room and go down and get breakfast.");
		        isComplete = true; 
		    }
		    else if(player.getNumCubeParts() < 5 && player.getNumCubeParts() > -1)
		    {
 		       setItemNarrative("You appear to still be missing pieces. The repair station suggest you need 5.");
		    }
		}
	    }
	    else //(player.getSymbol() == ">")
	    {
		if(items[i]->getYPos() == player.getYPos() && items[i]->getXPos() == player.getXPos() + 1 && items[i]->getType() == "statue")
		{
		    if(player.getNumCubeParts() == 5)
		    {
                setItemNarrative("");
  		        setWorldNarrative("You combine all of the Pandora's Cube pieces. You step back through a portal back into your own room and go down and get breakfast.");
		        isComplete = true; 
		    }
		    else if(player.getNumCubeParts() < 5 && player.getNumCubeParts() > -1)
		    {
 		       setItemNarrative("You appear to still be missing pieces. The repair station suggest you need 5.");
		    }
		}
	    }
	}
    }
}

void Game::checkForNarrativeUpdate()
{
	if (priorRoomIndex != currentRoomIndex)
	{
		updateRoomNarrative(currentRoomIndex);
	}
}

void Game::updateRoomNarrative(int roomIndex)
{
    if (roomIndex == 1) // pokemon gym
    {
        setWorldNarrative("Welcome to Room 1.");
    }
    else if (roomIndex == 2)    // zelda blocks
    {
        setWorldNarrative("Welcome to Room 2.");
    }
    else if (roomIndex == 3)    // snorlax
    {
        setWorldNarrative("Welcome to Route 12. It appears that there is a very large and very lazy looking Pokemon over there…");
    }
    else if (roomIndex == 4)    // pacman
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 5) // life or death blocks
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 6)    // bomberman
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 7 || roomIndex == 10)    //mario
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 8) // ?
    {
        setWorldNarrative("Which room am I?");
    }
    else if (roomIndex == 9) // Rodent's Revenge
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 11)   // end room
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 12)   // invisible maze
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 13)   //repair
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 14)   // trophy
    {
        setWorldNarrative("");
    }
    else if (roomIndex == 15) // ?
    {
        setWorldNarrative("Who am I?");
    }
    else if (roomIndex == 16) // ?
    {
        setWorldNarrative("Who am I?");
    }



}