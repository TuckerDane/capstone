/* ..............................................
  @file Room.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-20
  
  
.............................................. */

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "Item.hpp"
#include "Door.hpp"

using std::fstream;
using std::string;

/* ..............................................
  GLOBALS
  
.............................................. */
#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7

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
  int tileColor;

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
  void setTileColor(int color);

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
  int getTileColor();
};

#endif
