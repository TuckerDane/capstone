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
    // if the space contains an item that you can walk on
    Item **items = rooms[player.getCurrentRoom()]->getItems();
    for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
    {
        if (items[i] != NULL)
        {
            if (items[i]->getYPos() == y && items[i]->getXPos() == x && items[i]->getType() != "immovable" && items[i]->getType() != "softblock" && items[i]->getType() != "snorlax")
            {
                return true;
            }
            else if (items[i]->getYPos() == y && items[i]->getXPos() == x && (items[i]->getType() == "immovable" || items[i]->getType() == "softblock" || items[i]->getType() == "snorlax") )
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
    updatePlayer();
    updateEnemies();
}

void Game::updatePlayer()
{
    player.setIsMoved(false);
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
                    narrative = player.getInventoryItem(player.getSelectedItemIndex())->getDescription();
                }
                else
                {
                    narrative = "an empty item slot";
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
                    narrative = player.getInventoryItem(player.getSelectedItemIndex())->getDescription();
                }
                else
                {
                    narrative = "an empty item slot";
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
                    setNarrative("you do not have an item selected to use");
                }
                else if (player.getEquippedItem()->getType() == "key")
                {
                    useKey();
                }
                else if (player.getEquippedItem()->getType() == "potion")
                {
                    usePotion(player.getEquippedItem());
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
	    break;
        case ';':
        case ':':
            dropItem();
            break;
        case 'q':
        case 'Q':
        {
            string temp = getNarrative();
            setNarrative("Would you like to quit? Press Y to confirm or N to return to <Adventure Game>.");
            renderNarrative();
            unsigned int confirm = 'a';
            while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N')
            {
                confirm = getch();
                if (confirm == 'y' || confirm == 'Y')
                {
                    setNarrative("You Quit the Game");
                    setIsComplete(true);
                }
            }
            break;
        }
    }
    if (player.getHP() < 1)
    {
        setNarrative("GAME OVER: You Died");
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
                if ((enemies[i]->getYPos() > 0) && isMoveAllowed(enemies[i]->getYPos() - 1, enemies[i]->getXPos()))
                {
                    enemies[i]->move('w');
                }
                break;
            case KEY_DOWN:
            case 's':
            case 'S':
                enemies[i]->setSymbol("v");
                if ((enemies[i]->getYPos() < LINES - 1) && isMoveAllowed(enemies[i]->getYPos() + 1, enemies[i]->getXPos()))
                {
                    enemies[i]->move('s');
                }
                break;
            case KEY_LEFT:
            case 'a':
            case 'A':
                enemies[i]->setSymbol("<");
                if ((enemies[i]->getXPos() > 0) && isMoveAllowed(enemies[i]->getYPos(), enemies[i]->getXPos() - 1))
                {
                    enemies[i]->move('a');
                }
                break;
            case KEY_RIGHT:
            case 'd':
            case 'D':
                enemies[i]->setSymbol(">");
                if ((enemies[i]->getXPos() < COLS - 1) && isMoveAllowed(enemies[i]->getYPos(), enemies[i]->getXPos() + 1))
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
                player.setCurrentRoom(doors[i]->getNextRoom());
                player.setYPos(doors[i]->getNextYPos());
                player.setXPos(doors[i]->getNextXPos());
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
		player.setCurrentRoom(teleporters[i]->getNextRoom());
		player.setYPos(teleporters[i]->getNextYPos());
		player.setXPos(teleporters[i]->getNextXPos());
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
        setNarrative("you used the " + player.getEquippedItem()->getName());
        if (firstDoor->getNextRoom() != -1)
            useKeyOnOppositeDoor(firstDoor);
    }
    else
    {
        setNarrative("the " + player.getEquippedItem()->getName() + " does not work here...");
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
        setNarrative("You picked up the " + theItem->getName());
        theItem->setXPos(-1);
        theItem->setYPos(-1);
    }
    else if (!isAnItem)
    {
        setNarrative("There is nothing there to pick up");
    }
    else
    {
        setNarrative("You could not pick up the " + theItem->getName());
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
                setNarrative("Item is already here. You cannot drop another here");
                break;
            }
        }
        else //items[i] == NULL and can be dropped
        {
            droppedItem = player.drop(player.getSelectedItemIndex()); //get the item that has been dropped
            if (droppedItem == NULL)                                  //dropping a null
            {
                setNarrative("You are unable to drop an empty slot in your bag.");
                break;
            }
            droppedItem->setXPos(player.getXPos());
            droppedItem->setYPos(player.getYPos());
            items[itemIndex] = droppedItem;
            itemHasBeenDropped = true;
        }
        itemIndex++;
    }
    if (itemHasBeenDropped == true)
    {
        setNarrative("You have dropped " + droppedItem->getName());
    }
}

void Game::displayItemDescriptionToNarrativeWindow(Item *item){
    string previousNarrative = getNarrative();
    int lineLength = previousNarrative.size();
    if (lineLength <= 83)
    {
        setNarrative(item->getDescription() + " " + previousNarrative);
        renderNarrative();
    }
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
                if (((player.getYPos() - 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && items[i]->getType() == "statue")
                {
		            setNarrative(items[i]->getDescription());
                }
            }
            else if (player.getSymbol() == "v")
            {
                if (((player.getYPos() + 1) == items[i]->getYPos()) && player.getXPos() == items[i]->getXPos() && items[i]->getType() == "statue")
                {
		            setNarrative(items[i]->getDescription());
                }
            }

            else if (player.getSymbol() == "<")
            {
                if (((player.getXPos() - 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && items[i]->getType() == "statue")
                {
		            setNarrative(items[i]->getDescription());
                }
            }
            else // player.getSymbol() == ">"
            {
                if (((player.getXPos() + 1) == items[i]->getXPos()) && player.getYPos() == items[i]->getYPos() && items[i]->getType() == "statue")
                {
		            setNarrative(items[i]->getDescription());
                }
            }
        }
    }
}
