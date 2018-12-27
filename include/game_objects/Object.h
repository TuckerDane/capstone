/* ..............................................
  @file Object.h
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
  @brief 
  
.............................................. */
class Object
{
protected:
	int rowPos;	// a variable which stores the row the ant is on in the matrix
	int colPos;	// a variable which stores the column the ant is on in the matrix
	int weight;	// how much the object weighs
	char symbol; // holds the symbol of the object
	string type; // holds the type name of the object
	string name; // holds the name of the object
							 //TODO: add color attribute

public:
	Object();																					// default constructor for Object
	Object(char s, string n, int r, int c, string t); // constructor for inherited classes
	~Object();																				// deconstructor for Object

	//TODO: add setColor
	virtual void setWeight(int w) = 0; // sets the weight of an object
	virtual void setRowPos(int r);		 // set rowPos of the Object
	virtual void setColPos(int c);		 // set colPos of the Object

	//TODO: add getColor
	virtual int getRowPos();			// returns the row of the Object
	virtual int getColPos();			// returns the column of the Object
	virtual char getSymbol();			// returns the type of the Object
	virtual int getWeight() = 0;	// returns the weight of the object
	virtual string getName() = 0; // returns the name of the Object
	virtual string getType();			// returns the type of Object
};

#endif
