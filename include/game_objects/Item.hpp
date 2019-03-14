/* ..............................................
  @ file Item.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdlib.h>
#include <iostream>
#include "Object.hpp"
#include "Door.hpp"
#include "Console.hpp"

/* ..............................................
  @brief 
  
.............................................. */
class Item : public Object
{
protected:
  int weight; // how much the object weights
  int healing = 0;
  int damage = 0;
  Console devConsole;

public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Item();          // default constructor for Item
  virtual ~Item(); // deconstructor for Item

  // SETTERS
  void setWeight(int weight);
  void setDamage(int damage);
  void setHealing(int healing);

  // GETTERS
  int getWeight();
  int getHealing();
  int getDamage();

  // Actions
  virtual bool use(); // returns true if use() is successful, false if unsuccessful
  virtual bool use(Door *door);
  virtual void triggerItemActions(char direction);
};

#endif
