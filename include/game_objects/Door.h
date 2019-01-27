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
  int nextDoor; // points to the door in the next room that the door goes to
  int password; // password used to lock/unlock the door
  bool locked;  // true of the door is locked, false if it is unlocked

public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Door(); // default constructor for Door
  Door(int yPosition, int xPos, int nextRoom, int nextDoor, int password, bool locked);
  ~Door(); // deconstructor for Door

  // SETTERS
  void setNextRoom(int nextRoom);
  void setNextDoor(int nextDoor);
  void setPassword(int password);
  void setLocked(bool locked);

  // GETTERS
  int getNextRoom();
  int getNextDoor();
  int getPassword();
  bool getLocked();
};

#endif