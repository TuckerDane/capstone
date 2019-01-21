/* ..............................................
  @file Item.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Item.h"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS 
  
.............................................. */

Item::Item() : Object(-1, -1, COLOR_BLACK, '?', "item_object", "item")
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