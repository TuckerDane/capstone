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
#include "Colors.hpp"

using std::string;

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

	// ACTIONS
	virtual int setColorPair(int objectColor, int backgroundColor);
};

#endif
