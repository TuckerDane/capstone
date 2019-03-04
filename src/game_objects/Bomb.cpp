/*............................................
 @file Bomb.cpp
 @date 2/25/19

............................................*/
#include "Bomb.hpp"
#include "Bomb.hpp"

/*............................................
  CONSTRUCTOR/DESTRUCTORS

............................................*/

Bomb::Bomb()
{
	name = "Bomberman Bomb";
	type = "bomb";
	weight = 1;
  damage = 2;
	symbol = "Ỏ"; 
	color = COLOR_RED;
	description = "Creates an explosion in a + shape. Don't forget to duck for cover!";
	gettimeofday(&lastTimeMoved, NULL);
}

Bomb::Bomb(int yPos, int xPos)
{
	this->yPos = yPos;
	this->xPos = xPos;
	name = "Bomberman Bomb";
	type = "bomb";
	weight = 1;
  damage = 2;
	symbol = "Ỏ"; 
	color = COLOR_RED;
	description = "Creates an explosion in a + shape. Don't forget to duck for cover!";
	gettimeofday(&lastTimeMoved, NULL);
}

void Bomb::renderBombAnimation(int y, int x, WINDOW *window)
{
    struct timeval timeNow;
    gettimeofday(&timeNow, NULL);
		bool timesUp = false;

    mvwaddchWithColorBomb(y, x, "Ỏ", RED_ON_BLACK, window); // display bomb on floor

		while (timesUp == false)
		{
			if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) && ((timeNow.tv_sec - lastTimeMoved.tv_sec) <=1))
			{
					//delay 1 second ❸ ❷ ❶
					mvwaddchWithColorBomb(y, x, "❸", RED_ON_BLACK, window); // 3
			}
			if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) && ((timeNow.tv_sec - lastTimeMoved.tv_sec) <=1))
			{
					//delay 1 second ❸ ❷ ❶
					mvwaddchWithColorBomb(y, x, "❷", RED_ON_BLACK, window); // 2
			}
			if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) && ((timeNow.tv_sec - lastTimeMoved.tv_sec) <=1))
			{
					//delay 1 second ❸ ❷ ❶
					mvwaddchWithColorBomb(y, x, "❶", RED_ON_BLACK, window); // 1
			}
			if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) && ((timeNow.tv_sec - lastTimeMoved.tv_sec) <=1))
			{
					mvwaddchWithColorBomb(y, x, "✶", RED_ON_BLACK, window); // display explosion
			}
			if (((timeNow.tv_sec - lastTimeMoved.tv_sec) > 0) && ((timeNow.tv_sec - lastTimeMoved.tv_sec) <=1))
			{
					mvwaddchWithColorBomb(y, x, " ", BLACK_ON_BLACK, window); // display empty
			}
			else
			{
				timesUp = true;		
			}
		}
}


void Bomb::mvwaddchWithColorBomb(int yPos, int xPos, string TILE_SYMBOL, char TILE_PAIR, WINDOW *window)
{
  wattron(window, COLOR_PAIR(TILE_PAIR));
  mvwprintw(window, yPos, xPos, TILE_SYMBOL.c_str());
  wattroff(window, COLOR_PAIR(TILE_PAIR));
}

Bomb::~Bomb()
{
}

/*............................................
GETTERS

............................................*/

/*............................................
ACTIONS

............................................*/