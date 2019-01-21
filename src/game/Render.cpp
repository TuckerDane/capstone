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
  renderSpace();
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

void Game::renderSpace()
{
  int spaceIndex = 0;
  int refreshCounter = 0;
  for (int height = 0; height < this->spaces[spaceIndex].getMaxHeight(); height++)
  {
    for (int width = 0; width < this->spaces[spaceIndex].getMaxWidth(); width++)
    {
        char c = this->spaces[spaceIndex].getWall(height, width);
        if (c == '+' || c == '-' || c == '|' || c == ' ' || c == '\\' || c == '/')
        {
          mvaddchWithColor(height+5, width+5, c, PLAYER_PAIR);
          refreshCounter++;
          if(refreshCounter > 5)
          {
            refresh();
            refreshCounter = 0;
          }
        }
    }
  }
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