/* ..............................................
  @file Door.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Door.h"

/* ..............................................
  @brief Construct a new Door:: Door object
  
.............................................. */
Door::Door() : Object(' ', "Generic", -1, -1, "Door")
{
  weight = 100;
}

/* ..............................................
  @brief Construct a new Door:: Door object
  
  @param s 
  @param row 
  @param col 
.............................................. */
Door::Door(char s, int row, int col) : Object(s, "Generic", row, col, "Door")
{
}

/* ..............................................
  @brief Destroy the Door:: Door object
  
.............................................. */
Door::~Door()
{
}

/* ..............................................
  @brief 
  
  @param s 
.............................................. */
void Door::setSymbol(char s)
{
  symbol = s;
}

/* ..............................................
  @brief 
  
  @param o 
.............................................. */
void Door::setOpen(bool o)
{
  open = o;
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Door::getWeight()
{
  return weight;
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Door::getOpen()
{
  return open;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Door::getName()
{
  return name;
}

/* ..............................................
  @brief 
  
  @param w 
.............................................. */
void Door::setWeight(int w)
{
  weight = w;
}