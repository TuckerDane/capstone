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
#define MAX_HEIGHT  50
#define MAX_WIDTH   50
#define MAX_AREA    MAX_HEIGHT*MAX_WIDTH
#define MAX_ITEMS   MAX_AREA

/* ..............................................
  @brief 
  
.............................................. */
class Space
{
  protected:
    char walls[MAX_AREA];
    Item* items[MAX_ITEMS];
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
	  char* getWalls();
    Item** getItems();
    string getType();
    string getName();
    string getDescription();
};

#endif
