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
  refresh();
  renderStatus();
  renderWorld();
  renderNarrative();  
}

void Game::renderStatus()
{
  box(this->statusWindow, 0, 0);
  wbkgd(this->statusWindow, COLOR_PAIR(MENU_PAIR));
  wrefresh(this->statusWindow);
}

void Game::renderWorld()
{
  box(this->worldWindow, 0, 0);
  renderMap();
  renderPlayer();
  wrefresh(this->worldWindow);
}

void Game::renderNarrative()
{
  box(this->narrativeWindow, 0, 0);
  wbkgd(this->narrativeWindow, COLOR_PAIR(MENU_PAIR));
  wrefresh(this->narrativeWindow);
}

void Game::renderMap()
{
    /* background */
    wbkgd(this->worldWindow, COLOR_PAIR(DUNGEON_PAIR));
    renderSpace();
}

void Game::renderSpace()
{
  int spaceIndex = 0;
  for (int height = 0; height < this->spaces[spaceIndex].getMaxHeight(); height++)
  {
    for (int width = 0; width < this->spaces[spaceIndex].getMaxWidth(); width++)
    {
        char c = this->spaces[spaceIndex].getWall(height, width);
        if (c == '+' || c == '-' || c == '|' || c == ' ' || c == '\\' || c == '/')
        {
          mvwaddchWithColor(height+1, width+1, c, DUNGEON_PAIR);
        }
    }
  }
}

void Game::renderPlayer()
{
  mvwaddchWithColor(player.getYPos(), player.getXPos(), player.getSymbol(), PLAYER_PAIR);            // render the player       
}

void Game::mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  attron(COLOR_PAIR(TILE_PAIR));
  mvwaddch(this->worldWindow, yPos, xPos, TILE_SYMBOL);
  attroff(COLOR_PAIR(TILE_PAIR));
}