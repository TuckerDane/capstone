/* ..............................................
  @file Render.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */

#include "Render.h"

/* ..............................................
  ACTIONS
  
.............................................. */

void Game::render()
{
  renderMap();
  renderPlayer();
  refresh();
}

void Game::renderMap()
{
    int y;

    /* background */
    attron(COLOR_PAIR(GRASS_PAIR));
    for (y = 0; y < LINES; y++) {
        mvhline(y, 0, GRASS, COLS);
    }
    attroff(COLOR_PAIR(GRASS_PAIR));
}

void Game::renderPlayer()
{
  mvaddchWithColor(player.getYPos(), player.getXPos(), player.getSymbol(), PLAYER_PAIR);            // render the player       
}

void Game::mvaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  attron(COLOR_PAIR(TILE_PAIR));
  mvaddch(yPos, xPos, TILE_SYMBOL);
  attroff(COLOR_PAIR(TILE_PAIR));
}