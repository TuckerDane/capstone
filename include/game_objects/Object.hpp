/* ..............................................
  @file Object.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>

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
class Object
{
  protected:
	int xPos, yPos;		// the coordinate positions
	int color;			// ncurses colors
	char symbol;		// holds the symbol of the object
	string type;		// holds the type name of the object
	string name;		// holds the name of the object
	string description; // holds description of the object

  public:
	// CONSTRUCTOR/DESTRUCTORS
	Object();
	Object(int xPos, int yPos, int color, char symbol, string type, string name, string description);
	virtual ~Object();

	// SETTERS
	virtual void setXPos(int xPos);
	virtual void setYPos(int yPos);
	virtual void setColor(int color);
	virtual void setSymbol(char symbol);
	virtual void setType(string type);
	virtual void setName(string name);
	virtual void setDescription(string description);

	// GETTERS
	virtual int getXPos();
	virtual int getYPos();
	virtual int getColor();
	virtual char getSymbol();
	virtual string getType();
	virtual string getName();
	virtual string getDescription();
};

#endif