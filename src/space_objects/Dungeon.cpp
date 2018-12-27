/* ..............................................
  @file Dungeon.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Dungeon.h"

/* ..............................................
  @brief Construct a new Dungeon:: Dungeon object
  
.............................................. */
Dungeon::Dungeon()
{

}

/* ..............................................
  @brief Destroy the Dungeon:: Dungeon object
  
.............................................. */
Dungeon::~Dungeon()
{

}

/* ..............................................
  @brief 
  
.............................................. */
void Dungeon::setStones()
{
	white.setStone(5, 5, "white");
	red.setStone(2, 8, "red");
	yellow.setStone(5, 5, "yellow");
	green.setStone(5, 5, "green");
	blue.setStone(2, 2, "blue");
}

/* ..............................................
  @brief 
  
.............................................. */
void Dungeon::setSwitches()
{
	switches[0].setSwitch(10, 10, "white", 'W');
	switches[1].setSwitch(2, 2, "red", 'R');
	switches[2].setSwitch(2, 18, "yellow", 'Y');
	switches[3].setSwitch(18, 18, "green", 'G');
	switches[4].setSwitch(18, 2, "blue", 'B');
	aarowSwitch[0].setSwitch(10, 10, "aarow", 'A');
}

/* ..............................................
  @brief 
  
.............................................. */
void Dungeon::setSpaces()
{
	// SET POINTERS TO ROOMS
	sPtr[0] = &room1;
	sPtr[1] = &room2;
	sPtr[2] = &room3;
	sPtr[3] = &room4;
	sPtr[4] = &room5;
	sPtr[5] = &room6;
	sPtr[6] = &room7;
	sPtr[7] = &room8;
	sPtr[8] = &room9;
	sPtr[9] = &room10;
	sPtr[10] = &room11;
	sPtr[11] = &room12;
	sPtr[12] = &room13;

	// INITIALIZE ROOMS
	room3.setSwitches(switches, 5);
	room3.getDoor("top")->setOpen(false);
	room3.getDoor("top")->setSymbol('#');
	room13.setSwitches(aarowSwitch, 1);

	sPtr[0]->setSpace("ROOM 1", &tucker, NULL, NULL, sPtr[1], NULL, &white, 1);
	sPtr[1]->setSpace("ROOM 2", &tucker, NULL, NULL, sPtr[2], sPtr[0], NULL, 2);
	sPtr[2]->setSpace("ROOM 3", &tucker, sPtr[7], sPtr[3], sPtr[11], sPtr[1], switches, 3);
	sPtr[3]->setSpace("ROOM 4", &tucker, sPtr[2], sPtr[4], NULL, NULL, NULL, 4);
	sPtr[4]->setSpace("ROOM 5", &tucker, sPtr[3], NULL, NULL, sPtr[5], &red, 5);
	sPtr[5]->setSpace("ROOM 6", &tucker, NULL, NULL, sPtr[4], sPtr[6], NULL, 6);
	sPtr[6]->setSpace("ROOM 7", &tucker, NULL, NULL, sPtr[5], NULL, &yellow, 7);
	sPtr[7]->setSpace("ROOM 8", &tucker, sPtr[8], sPtr[2], NULL, NULL, NULL, 8);
	sPtr[8]->setSpace("ROOM 9", &tucker, NULL, sPtr[7], NULL, sPtr[9], &blue, 9);
	sPtr[9]->setSpace("ROOM 10", &tucker, NULL, NULL, sPtr[8], sPtr[10], NULL, 10);
	sPtr[10]->setSpace("ROOM 11", &tucker, NULL, NULL, sPtr[9], NULL, &green, 11);
	sPtr[11]->setSpace("ROOM 12", &tucker, NULL, NULL, sPtr[12], sPtr[2], NULL, 12);
	sPtr[12]->setSpace("ROOM 13", &tucker, NULL, NULL, NULL, sPtr[11], aarowSwitch, 13);

}

/* ..............................................
  @brief 
  
  @return Player* 
.............................................. */
Player* Dungeon::getPlayer()
{
	return &tucker;
}

/* ..............................................
  @brief 
  
  @param startingRoom 
  @param i 
.............................................. */
void Dungeon::setPlayer(Space *startingRoom, int i)
{
	tucker.setPlayerRoom(startingRoom->getSpaceName(), startingRoom->getSpaceNum());
	tucker.setRowPos(startingRoom->getSpSizeRow()-2);
	tucker.setColPos(startingRoom->getSpSizeCol() / 2);
}

/* ..............................................
  @brief 
  
  @param i 
  @return Space* 
.............................................. */
Space* Dungeon::getRoom(int i)
{
	return sPtr[i];
}

/* ..............................................
  @brief 
  
  @param i 
  @return true 
  @return false 
.............................................. */
bool Dungeon::getSwitch(int i)
{
	return switches[i].getTripped();
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Dungeon::getASwitch()
{
	return aarowSwitch[0].getTripped();
}