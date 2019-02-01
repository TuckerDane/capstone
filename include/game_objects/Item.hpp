/* ..............................................
  @file Item.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdlib.h>
#include "Object.hpp"
#include "Door.hpp"

/* ..............................................
  @brief 
  
.............................................. */
class Item : public Object
{
protected:
  int weight; // how much the object weights
  int healing = 0;
  int damage = 0;
public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Item();          // default constructor for Item
  virtual ~Item(); // deconstructor for Item

  // SETTERS
  void setWeight(int weight);
  void setDamage(int damage);

  // GETTERS
  int getWeight();
  int getHealing();
  int getDamage();
  // Actions
  virtual bool use(); // returns true if use() is successful, false if unsuccessful
  virtual bool use(Door* door);
  virtual void triggerItemActions(char direction);
};

#endif
