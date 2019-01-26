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
  renderCurrentWindow();
  renderNarrative();  
}

void Game::renderCurrentWindow()
{
  if (getCurrentWindow() == this->inventoryWindow)
  {
    renderInventory();
  }
  else if (getCurrentWindow() == this->worldWindow)
  {
    renderWorld();
  }
  else if (getCurrentWindow() == this->developerWindow)
  {
    renderDev();
  }
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

void Game::renderInventory()
{
  werase(this->inventoryWindow);
  box(this->inventoryWindow, 0, 0);
  wbkgd(this->inventoryWindow, COLOR_PAIR(MENU_PAIR));

  mvwprintw(this->inventoryWindow, 2, 2, "INVENTORY");

  Item** inventory = player.getInventory();

  for (int i=0; i < player.getNumItems(); i++)
  {
    if(i == player.getSelectedItemIndex())
    {
      wattron(this->inventoryWindow, A_REVERSE);
    }
    string line =  i + " " + inventory[i]->getName() + " (" + std::to_string(inventory[i]->getWeight()) + "): " + inventory[i]->getDescription();
    mvwprintw(this->inventoryWindow, i + 3, 2, line.c_str());

    wattroff(this->inventoryWindow, A_REVERSE);
  }

  wrefresh(this->inventoryWindow);
}

void Game::renderDev()
{
  werase(this->developerWindow);
  box(this->developerWindow, 0, 0);
  wbkgd(this->developerWindow, COLOR_PAIR(DUNGEON_PAIR));
  wrefresh(this->developerWindow);
}

void Game::renderNarrative()
{
  werase(this->narrativeWindow);
  box(this->narrativeWindow, 0, 0);
  wbkgd(this->narrativeWindow, COLOR_PAIR(MENU_PAIR));
  mvwprintw(this->narrativeWindow, 1, 1, this->getNarrative().c_str()); // print a string to position 1, 1 of a window. must be type c_str. strings can be converted with .s_str() function
  wrefresh(this->narrativeWindow);
}

void Game::renderMap()
{
    /* background */
    wbkgd(this->worldWindow, COLOR_PAIR(GRASS_PAIR));
    renderRoom();
}

void Game::renderRoom()
{
  int roomIndex = 0;
  for (int height = 0; height < this->rooms[roomIndex].getMaxHeight(); height++)
  {
    for (int width = 0; width < this->rooms[roomIndex].getMaxWidth(); width++)
    {
        char c = this->rooms[roomIndex].getWall(height, width);
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
  wattron(this->worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwaddch(this->worldWindow, yPos, xPos, TILE_SYMBOL);
  wattroff(this->worldWindow, COLOR_PAIR(TILE_PAIR));
}
