/* ..............................................
  @file Key.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#include "Key.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Key::Key() : Item()
{
  name = "normal key";
  type = "key";
  weight = 1;
  password = -1;
  description = "used to unlock doors";
}

Key::Key(string name, int password) : Item()
{
  type = "key";
  this->name = name;
  weight = 1;
  this->password = password;
  description = "used to unlock doors";
}

Key::~Key()
{
}

/* ..............................................
  SETTERS
  
.............................................. */

void Key::setPassword(int password)
{
  this->password = password;
}

/* ..............................................
  GETTERS
  
.............................................. */

int Key::getPassword()
{
  return password;
}

/* ..............................................
  ACTIONS
  
.............................................. */
bool Key::use(Door *door)
{
  if (password == door->getPassword())
  {
    if (door->getLocked() == true)
    {
      // unlock the door
      door->setLocked(false);
      door->setSymbol(' ');
    }
    else
    {
      // otherwise lock the door
      door->setLocked(true);
      door->setSymbol('#');
    }
    return true;
  }
  else
  {
    return false;
  }
}