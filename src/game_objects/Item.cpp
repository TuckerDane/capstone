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
  weight = 0;
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

void Item::setDamage(int damage)
{
  this->damage = damage;
}

/* ..............................................
  GETTERS 
  
.............................................. */

int Item::getWeight()
{
  return weight;
}

int Item::getHealing()
{
  return healing;
}

int Item::getDamage()
{
  return damage;
}

/* ..............................................
  ACTIONS
  
.............................................. */

bool Item::use()
{
  return false;
}

bool Item::use(Door *door)
{
  return false;
}

void Item::triggerItemActions(char direction)
{
  //filler
}
