//TODO: add main comment block
//FIXME: display output
//FIXME: smooth game loop
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include "Space.h"
#include "Object.h"
#include "Dungeon.h"

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
	Dungeon castle;
	castle.setStones();
	castle.setSwitches();
	castle.setSpaces();
	castle.setPlayer(castle.getRoom(0), 1);
	
	int clock = 500;
	bool gameWon = false;
	bool moving = true;
	while (moving == true)
	{
		initscr();
		cbreak();
		noecho();
		scrollok(stdscr, TRUE);
		nodelay(stdscr, TRUE);
		castle.getRoom(castle.getPlayer()->getCRoom() - 1)->printSpace();
		
		cout << "\tMOVE THE COLORED STONES TO THEIR CORRECT LOCATIONS TO UNLOCK THE DOOR TO ANDREW" << endl;
		cout << "\tBRING 9 AAROWS TO ANDREW AND HE SHALL SET YOU FREE, TAKE TOO LONG, AND YOU WILL DIE" << endl << endl;

		cout << "\tTIME REMAINING ON THE CLOCK:  " << clock << endl << endl;
		cout << "\tMove " << castle.getPlayer()->getName() << " around using WSAD or press X to escape" << endl << endl;
		castle.getPlayer()->displayBackpack();
		char direction = 'p';
		direction = getch();
		std::system("clear");		// i need to update this... system calls are bad

		if (direction == 'x' || direction == 'X')					// quit movement
		{
			moving = false;
		}
		else if (direction == 'e' || direction == 'E')					// if player tries to add an object
		{
			int pRoom = castle.getPlayer()->getCRoom();					// room number player is in
			int pRowPos = castle.getPlayer()->getRowPos();				// row player is on
			int pColPos = castle.getPlayer()->getColPos();				// column player is on

			// Object at the player's current location
			Object *plyrLoc = (castle.getRoom(pRoom - 1)->getSpPos(pRowPos, pColPos));

			if (plyrLoc != NULL)										// if the player's location is not NULL
			{
				if (plyrLoc->getWeight() < 20)							// and the player could potentially carry it
				{
					if (castle.getPlayer()->addObject(plyrLoc))			// and if the player does succeed in picking it up
					{
						castle.getRoom(pRoom - 1)->setSpPos(NULL, pRowPos, pColPos);	// set the object at the player's location to NULL
					}
				}
			}
		}
		else if ('0' < direction && direction < '9')					// if player tries to drop an object
		{
			int pRoom = castle.getPlayer()->getCRoom();					// room number player is in
			int pRowPos = castle.getPlayer()->getRowPos();				// row player is on
			int pColPos = castle.getPlayer()->getColPos();				// column player is on

			// Object at the player's current location
			Object *plyrLoc = (castle.getRoom(pRoom - 1)->getSpPos(pRowPos, pColPos));

			/**************************************************
			// HANDLES DROPPING AN ITEM ON THE EMPTY GROUND
			/ **************************************************/
			if (plyrLoc == NULL)														// if the player is in an open spot to drop an item
			{
				plyrLoc = castle.getPlayer()->dropObject(direction - '0');				// set plyrLoc to what's in the player's backpack slot
																						// while removing it from the backpack

				if (plyrLoc != NULL)													// if there was something in the backpack
				{
					castle.getRoom(pRoom - 1)->setSpPos(plyrLoc, pRowPos, pColPos);		// set it back on the ground!
				}
			}
			/**************************************************
			// HANDLES DROPPING A STONE ONTO A SWITCH
			/ **************************************************/
			else if (plyrLoc->getType() == "Switch")										// if the object the player is standing over is a switch
			{
				if (castle.getPlayer()->checkObject(direction - '0') == plyrLoc->getName())	// and if the object to be dropped is a stone of the corresponding color
				{
					dynamic_cast<Switch*> (plyrLoc)->setTripped(true);						// set the switch to the true position
					plyrLoc = castle.getPlayer()->dropObject(direction - '0');				// set plyrLoc to what's in the player's backpack slot
																							// while removing it from the backpack

					plyrLoc->setWeight(100);												// make the stone extremely heavy so that it can no longer be lifted!

					if (plyrLoc != NULL)													// if there was something in the backpack
					{
						castle.getRoom(pRoom - 1)->setSpPos(plyrLoc, pRowPos, pColPos);		// set it back on the ground!
					}
				}
			}

		}
		else																				// else move the player
		{
			bool moved = false;
			int i = 0;

			while (moved == false)
			{
				string room = "ROOM ";
				room += std::to_string(i+1);

				if (castle.getPlayer()->getPlayerRoom() == (room))							// move players
				{
					castle.getRoom(i)->movePlayer(direction);
					moved = true;
				}

				i++;
			}
		}
		
		if (castle.getRoom(2)->getDoor("top")->getOpen() == false)							// if the room 2 door has not yet been opened, check to see if it can be opened
		{
			// IF ALL OF THE SWITCHES HAVE BEEN TRIGGERED
			if (castle.getSwitch(0) == true && castle.getSwitch(1) == true && castle.getSwitch(2) == true && castle.getSwitch(3) == true && castle.getSwitch(4) == true)
			{
				castle.getRoom(2)->getDoor("top")->setSymbol(' ');							// set the door to the open position
				castle.getRoom(2)->getDoor("top")->setOpen(true);							// set the door to the open position
			}
		}

		if (castle.getPlayer()->getWeight() == 18)						// if the player is carrying 9 aarows
		{
			int pRoom = castle.getPlayer()->getCRoom();					// room number player is in
			int pRowPos = castle.getPlayer()->getRowPos();				// row player is on
			int pColPos = castle.getPlayer()->getColPos();				// column player is on

			// The object the player is on
			Object *plyrLoc = (castle.getRoom(pRoom - 1)->getSpPos(pRowPos, pColPos));

			if (pRoom == 13 && pRowPos == 10 && pColPos == 10)			// if the player is standing on the aarow switch
			{
			
				dynamic_cast<Switch*> (plyrLoc)->setTripped(true);		// set the switch to the true position
			}
		}

		if (castle.getASwitch() == true)								// if the aarow switch is true
		{
			gameWon = true;
			moving = false;
		}
		if (clock == 0)
		{
			moving = false;
		}
		
		clock--;
		endwin();
	}

	if (gameWon == true)																					// if you won the game, say so
	{
		cout << endl << endl << endl;
		cout << "\tCONGRATULATIONS!! ANDREW HAS SET YOU FREE" << endl << endl;
	}
	else																									// if you lost the game, say so
	{
		cout << endl << endl << endl;
		cout << "\tYOU TOOK TOO LONG OR YOU QUIT, THEREFORE: YOU DIE!!" << endl << endl;
	}

	return 0;
}
