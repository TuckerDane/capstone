/* ..............................................
  @file Key.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#include "Key.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Key::Key() : Item()
{
  this->name = "normal key";
  this->type = "key";
  this->weight = 1;
  this->password = -1;
  this->description = "used to unlock doors";
}

Key::Key(string name, int password) : Item()
{
  this->name = name;
  this->weight = 1;
  this->password = password;
  this->description = "used to unlock doors";
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
  return this->password;
}

/* ..............................................
  ACTIONS
  
.............................................. */
bool Key::use(Door *door)
{
  if (this->password == door->getPassword())
  {
    door->setLocked(!door->getLocked());
    if (door->getLocked() == true)
    {
      door->setSymbol('#');
    }
    else
    {
      door->setSymbol(' ');
    }

    return true;
  }
  else
  {
    return false;
  }
}