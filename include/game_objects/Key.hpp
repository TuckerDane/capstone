/* ..............................................
  @file Key.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#ifndef KEY_HPP
#define KEY_HPP

#include "Item.hpp"
#include "Door.hpp"

/* ..............................................
  @brief 
  
.............................................. */
class Key : public Item
{
private:
  int password; // value of the key

public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Key(); // default constructor for Key
  Key(string name, int password, int color);
  ~Key(); // deconstructor for Key

  // SETTERS
  void setPassword(int password);

  // GETTERS
  int getPassword();

  // ACTIONS
  bool use(Door* door);
};

#endif
