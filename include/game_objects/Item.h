/* ..............................................
  @file Item.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdlib.h>
#include "Object.h"

/* ..............................................
  @brief 
  
.............................................. */
class Item : public Object
{
  private:
  	int weight;		// how much the object weights

  public:
    // CONSTRUCTORS/DECONSTRUCTORS
    Item();  // default constructor for Item
    ~Item(); // deconstructor for Item

    // SETTERS
    void setWeight(int weight);

    // GETTERS
    int getWeight();
};

#endif