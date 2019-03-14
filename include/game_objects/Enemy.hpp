/* ..............................................
  @ file Enemy.hpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <stdlib.h>
#include <sys/time.h>
#include "Player.hpp"
#include <string>
#include "Console.hpp"

 /* ..............................................
  @brief 
  
.............................................. */
class Enemy : public Player
{
  private:
  struct timeval lastTimeMoved;
  Console devConsole;
  int damage;

   public:
	// CONSTRUCTOR/DESTRUCTORS
	Enemy();
  Enemy(int yPos, int xPos);
	~Enemy();

  // SETTERS
  void setDamage(int damage);

  // GETTERS
  int getDamage();

 	// ACTIONS
  unsigned int processMove();
	void move(char direction);  // moves the enemy
};

#endif