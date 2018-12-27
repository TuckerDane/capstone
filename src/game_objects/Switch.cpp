/* ..............................................
  @file Switch.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Switch.h"

/* ..............................................
  @brief Construct a new Switch:: Switch object
  
.............................................. */
Switch::Switch() : Object('S', "Colored", 2, 2, "Switch")
{
	color = "none";
	weight = 100;
}

/* ..............................................
  @brief Construct a new Switch:: Switch object
  
  @param row 
  @param col 
  @param c 
  @param s 
.............................................. */
Switch::Switch(int row, int col, string c, char s) : Object(s, "Colored", row, col, "Switch")
{
	color = c;
	symbol = 'S';
	tripped = false;
}

/* ..............................................
  @brief Destroy the Switch:: Switch object
  
.............................................. */
Switch::~Switch()
{
}

/* ..............................................
  @brief 
  
  @param row 
  @param col 
  @param c 
  @param s 
.............................................. */
void Switch::setSwitch(int row, int col, string c, char s)
{
	this->symbol = s;
	this->rowPos = row;
	this->colPos = col;
	this->color = c;
	this->type = "Switch";
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Switch::getWeight()
{
	return weight;
}

/* ..............................................
  @brief 
  
  @param w 
.............................................. */
void Switch::setWeight(int w)
{
	weight = w;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Switch::getName()
{
	return color;
}

/* ..............................................
  @brief 
  
  @param t 
.............................................. */
void Switch::setTripped(bool t)
{
	tripped = t;
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Switch::getTripped()
{
	return tripped;
}
