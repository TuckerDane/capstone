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
  box(this->inventoryWindow, 0, 0);
  wbkgd(this->inventoryWindow, COLOR_PAIR(MENU_PAIR));

  mvwprintw(this->inventoryWindow, 2, 2, "INVENTORY");
  //mvwprintw(this->inventoryWindow, 3, 2, "---------");


  Item** inventory = player.getInventory();
  //int numItems = 10; //FOR LOOP TESTING. USUALLY: player.getNumItems();

  for (int i=0; i < player.getNumItems(); i++)
  {
    if(i == highlight)
    {
      wattron(this->inventoryWindow, A_REVERSE);
    }
    //mvwprintw(this->inventoryWindow, i + 3, 2, "inventoryStuffGoesHere"); // FOR TESTING
    string line =  i + " " + inventory[i]->getName() + " " + inventory[i]->getDescription();
    mvwprintw(this->inventoryWindow, i + 3, 2, line.c_str()); // ADD ITEM WEIGHT LATER

    wattroff(this->inventoryWindow, A_REVERSE);
  }

  wrefresh(this->inventoryWindow);
}

void Game::renderDev()
{
  box(this->inventoryWindow, 0, 0);
  wbkgd(this->inventoryWindow, COLOR_PAIR(DUNGEON_PAIR));
  wrefresh(this->inventoryWindow);
}

void Game::renderNarrative()
{
  box(this->narrativeWindow, 0, 0);
  wbkgd(this->narrativeWindow, COLOR_PAIR(MENU_PAIR));
  mvwprintw(this->narrativeWindow, 1, 1, this->getNarrative().c_str()); // print a string to position 1, 1 of a window. must be type c_str. strings can be converted with .s_str() function
  wrefresh(this->narrativeWindow);
}

void Game::renderMap()
{
    /* background */
    wbkgd(this->worldWindow, COLOR_PAIR(GRASS_PAIR));
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
  wattron(this->worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwaddch(this->worldWindow, yPos, xPos, TILE_SYMBOL);
  wattroff(this->worldWindow, COLOR_PAIR(TILE_PAIR));
}