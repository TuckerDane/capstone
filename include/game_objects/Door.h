/* ..............................................
  @file Door.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */

#ifndef DOOR_HPP
#define DOOR_HPP

#include "Object.h"

/* ..............................................
  @brief 
  
.............................................. */
class Door : public Object
{
private:
  int nextRoom; // points to the room that the door goes to
  int nextYPos; // Y position in the next room on the other side of the door
  int nextXPos; // X position in the next room on the other side of the door
  int password; // password used to lock/unlock the door
  bool locked;  // true of the door is locked, false if it is unlocked

public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Door(); // default constructor for Door
  Door(int yPos, int xPos, int nextRoom, int nextYPos, int nextXPos, int password, bool locked, int color);
  ~Door(); // deconstructor for Door

  // SETTERS
  void setNextRoom(int nextRoom);
  void setNextYPos(int nextYPos);
  void setNextXPos(int nextXPos);
  void setPassword(int password);
  void setLocked(bool locked);

  // GETTERS
  int getNextRoom();
  int getNextYPos();
  int getNextXPos();
  int getPassword();
  bool getLocked();
};

#endif