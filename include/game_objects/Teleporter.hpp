/* ..............................................
  @ file Teleporter.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#ifndef TELEPORTER_HPP
#define TELEPORTER_HPP

#include "Object.hpp"

/* ..............................................
  @brief 
  
.............................................. */
class Teleporter : public Object
{
private:
  int nextRoom; // points to the room that the teleporter goes to. useful if the teleporter takes you to a different room
  int nextYPos; // Y position in the next room
  int nextXPos; // X position in the next room

public:
  // CONSTRUCTORS/DECONSTRUCTORS
  Teleporter(); // default constructor for Door
  Teleporter(int yPos, int xPos, int nextRoom, int nextYPos, int nextXPos, int color);
  ~Teleporter(); // deconstructor for Door

  // SETTERS
  void setNextRoom(int nextRoom);
  void setNextYPos(int nextYPos);
  void setNextXPos(int nextXPos);

  // GETTERS
  int getNextRoom();
  int getNextYPos();
  int getNextXPos();
};

#endif