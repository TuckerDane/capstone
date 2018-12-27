/* ..............................................
  @file Stone.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Stone.h"

/* ..............................................
  @brief Construct a new Stone:: Stone object
  
.............................................. */
Stone::Stone() : Object('O', "Colored", 2, 2, "Stone")
{
	color = "white";
	weight = 10;
}

/* ..............................................
  @brief Construct a new Stone:: Stone object
  
  @param row 
  @param col 
  @param c 
.............................................. */
Stone::Stone(int row, int col, string c) : Object('O', "Colored", row, col, "Stone")
{
	color = c;
	weight = 10;
}

/* ..............................................
  @brief Destroy the Stone:: Stone object
  
.............................................. */
Stone::~Stone()
{
}

/* ..............................................
  @brief 
  
  @param row 
  @param col 
  @param c 
.............................................. */
void Stone::setStone(int row, int col, string c)
{
	this->rowPos = row;
	this->colPos = col;
	this->color = c;
	this->type = "Stone";
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Stone::getWeight()
{
	return weight;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Stone::getName()
{
	return color;
}

/* ..............................................
  @brief 
  
  @param w 
.............................................. */
void Stone::setWeight(int w)
{
	weight = w;
}