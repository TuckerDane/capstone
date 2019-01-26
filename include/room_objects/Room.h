/* ..............................................
  @file Room.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-20
  
  
.............................................. */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"
#include "Door.h"

using std::fstream;
using std::string;

/* ..............................................
  GLOBALS
  
.............................................. */

/* ..............................................
  @brief 
  
.............................................. */
class Room
{
protected:
  static const int MAX_DOORS = 4;
  static const int MAX_HEIGHT = 28;
  static const int MAX_WIDTH = 148;
  static const int MAX_ITEMS = MAX_WIDTH * MAX_HEIGHT;
  char walls[MAX_HEIGHT][MAX_WIDTH];
  Item *items[MAX_ITEMS];
  Door *doors[MAX_DOORS];
  string type;
  string name;
  string description;

public:
  // CONSTRUCTOR/DESTRUCTORS
  Room();
  Room(string roomFile);
  ~Room();

  // SETTERS
  void setWalls(string roomFile);
  void setItems();
  void setItem();
  void setType(string type);
  void setName(string name);
  void setDescription(string description);
  void setDoor(Door *door, int doorIndex);

  // GETTERS
  int getMaxHeight();
  int getMaxWidth();
  int getMaxItems();
  int getMaxDoors();
  char getWall(int height, int width);
  Item **getItems();
  string getType();
  string getName();
  string getDescription();
  Door *getDoor(int doorIndex);
  Door **getDoors();
};

#endif
