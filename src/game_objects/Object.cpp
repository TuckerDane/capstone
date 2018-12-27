/* ..............................................
  @file Object.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Object.h"

/* ..............................................
  @brief Construct a new Object:: Object object
  
.............................................. */
Object::Object()
{
  rowPos = 0;
  colPos = 0;
  symbol = 'O';
  name = "null object";
  type = "generic";
}

/* ..............................................
  @brief Construct a new Object:: Object object
  
  @param s 
  @param n 
  @param r 
  @param c 
  @param t 
.............................................. */
Object::Object(char s, string n, int r, int c, string t)
{
  rowPos = r;
  colPos = c;
  symbol = s;
  name = n;
  type = t;
}

/* ..............................................
  @brief Destroy the Object:: Object object
  
.............................................. */
Object::~Object()
{
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Object::getRowPos()
{
  return rowPos;
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Object::getColPos()
{
  return colPos;
}

/* ..............................................
  @brief 
  
  @return char 
.............................................. */
char Object::getSymbol()
{
  return symbol;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Object::getType()
{
  return type;
}

/* ..............................................
  @brief 
  
  @param r 
.............................................. */
void Object::setRowPos(int r)
{
  rowPos = r;
}

/* ..............................................
  @brief 
  
  @param c 
.............................................. */
void Object::setColPos(int c)
{
  colPos = c;
}
