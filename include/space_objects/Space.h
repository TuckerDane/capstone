/* ..............................................
  @file Space.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-20
  
  
.............................................. */

#ifndef SPACE_HPP
#define SPACE_HPP

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
class Space
{
protected:
  static const int MAX_HEIGHT = 50;
  static const int MAX_WIDTH = 50;
  static const int MAX_ITEMS = MAX_WIDTH * MAX_HEIGHT;
  char walls[MAX_WIDTH][MAX_HEIGHT];
  Item *items[MAX_ITEMS];
  string type;
  string name;
  string description;

public:
  // CONSTRUCTOR/DESTRUCTORS
  Space();
  ~Space();

  // SETTERS
  void setWalls(string spaceFile);
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
