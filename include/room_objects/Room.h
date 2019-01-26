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
  static const int MAX_HEIGHT = 28;
  static const int MAX_WIDTH = 148;
  static const int MAX_ITEMS = MAX_WIDTH * MAX_HEIGHT;
  char walls[MAX_HEIGHT][MAX_WIDTH];
  Item *items[MAX_ITEMS];
  string type;
  string name;
  string description;

public:
  // CONSTRUCTOR/DESTRUCTORS
  Room();
  ~Room();

  // SETTERS
  void setWalls(string roomFile);
  void setItems();
  void setItem();
  void setType(string type);
  void setName(string name);
  void setDescription(string description);

  // GETTERS
  int getMaxHeight();
  int getMaxWidth();
  int getMaxItems();
  char getWall(int height, int width);
  Item **getItems();
  string getType();
  string getName();
  string getDescription();
};

#endif
