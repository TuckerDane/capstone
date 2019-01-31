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
  this->name = "normal key";
  this->type = "key";
  this->weight = 1;
  this->password = -1;
  this->description = "used to unlock doors";
}

Key::Key(string name, int password) : Item()
{
  this->type = "key";
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
bool Key::use(int playerYPos, int playerXPos, Door** doors)
{
  // for all doors possible in the room
  for (int i=0; i < 4; i++)
  {
    // if the door exsists
    if (doors[i] != NULL)
    {
      // and if the player is next to the door
      if (abs(doors[i]->getYPos() - playerYPos) + abs(doors[i]->getXPos() - playerXPos) == 1)
      {
        // if the key's password is equal to the door's password
        if (this->password == doors[i]->getPassword())
        {
          // if the door is locked
          if(doors[i]->getLocked() == true)
          {
            // unlock the door
            doors[i]->setLocked(false);
            doors[i]->setSymbol(' ');
          }
          else
          {
            // otherwise lock the door
            doors[i]->setLocked(true);
            doors[i]->setSymbol('#');
          }
          return true;
        } 
      }
    }
  }
  return false;
}
