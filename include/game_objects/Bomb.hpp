/*......................................
 @file Bomb.h
 @date 02/25/2019

......................................*/
#ifndef BOMB_HPP
#define BOMB_HPP

#include "Item.hpp"
#include "Console.hpp"
#include <stdlib.h>
#include <sys/time.h>

/*.....................................
 @brief

.....................................*/

class Bomb : public Item
{
  private:
  	struct timeval lastTimeMoved;
  public:
	//CONSTRUCTOR/DESTRUCTOR
	Bomb();
	Bomb(int yPos, int xPos);
	void renderBombAnimation(int y, int x, WINDOW *window);
	void mvwaddchWithColorBomb(int yPos, int xPos, string TILE_SYMBOL, char TILE_PAIR, WINDOW *window);
	~Bomb();

	//SETTERS
	//GETTERS
	//ACTION
};

#endif