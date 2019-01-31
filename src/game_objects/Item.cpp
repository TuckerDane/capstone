/* ..............................................
  @file Item.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Item.hpp"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS 
  
.............................................. */

Item::Item() : Object(-1, -1, COLOR_BLACK, '?', "item_object", "item", "item_decription")
{
  this->weight = 0;
}

Item::~Item()
{
}

/* ..............................................
  SETTERS 
  
.............................................. */

void Item::setWeight(int weight)
{
  this->weight = weight;
}

/* ..............................................
  GETTERS 
  
.............................................. */

int Item::getWeight()
{
  return this->weight;
}

/* ..............................................
  ACTIONS
  
.............................................. */

bool Item::use()
{
  return false;
}

bool Item::use(int playerYPos, int playerXPos, Door** doors)
{
  return false;
}