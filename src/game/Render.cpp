/* ..............................................
  @file Render.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Render.hpp"
#include <string>

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
  werase(this->statusWindow);
  box(this->statusWindow, 0, 0);
  wbkgd(this->statusWindow, COLOR_PAIR(BLACK_ON_BLUE));
  mvwprintw(this->statusWindow, 1, 2, "Item");
  mvwprintw(this->statusWindow, 2, 2, "----");
  if(player.getInventoryItem(player.getSelectedItemIndex()) == NULL)
  {
    mvwprintw(this->statusWindow, 3, 2, "none");
  }
  else
  {
    mvwprintw(this->statusWindow, 3, 2, player.getInventoryItem(player.getSelectedItemIndex())->getName().c_str());
  }
  
  string hp;
  hp = std::to_string(player.getHP());
  mvwprintw(this->statusWindow, 1, 22, "HP");
  mvwprintw(this->statusWindow, 2, 20, "------");
  mvwprintw(this->statusWindow, 3, 22, hp.c_str());


  wrefresh(this->statusWindow);
}

void Game::renderWorld()
{
  werase(this->worldWindow);
  box(this->worldWindow, 0, 0);
  wbkgd(this->worldWindow, COLOR_PAIR(BLACK_ON_GREEN));
  renderRoom();
  renderPlayer();
  wrefresh(this->worldWindow);
}

void Game::renderInventory()
{
  werase(this->inventoryWindow);
  box(this->inventoryWindow, 0, 0);
  wbkgd(this->inventoryWindow, COLOR_PAIR(BLACK_ON_BLUE));

  mvwprintw(this->inventoryWindow, 1, 2, "INVENTORY");
  mvwprintw(this->inventoryWindow, 2, 2, "================================================================================================================================================");
  mvwprintw(this->inventoryWindow, 3, 2, "Slot\tItem\t\tWeight");
  mvwprintw(this->inventoryWindow, 4, 2, "----\t----\t\t------");

  Item **inventory = player.getInventory();
  string line;
  for (int i = 0; i < player.getMaxInventory(); i++)
  {
    if (i == player.getSelectedItemIndex())
    {
      wattron(this->inventoryWindow, A_REVERSE);
    }
    if (inventory[i] != NULL)
    {
      line = std::to_string(i+1);
      mvwprintw(this->inventoryWindow, i + 5, 2, line.c_str());
      line = inventory[i]->getName();
      mvwprintw(this->inventoryWindow, i + 5, 8, line.c_str());
      line = std::to_string(inventory[i]->getWeight());
      mvwprintw(this->inventoryWindow, i + 5, 26, line.c_str());
    }
    else
    {
      line = std::to_string(i+1) + "\tempty slot";
      mvwprintw(this->inventoryWindow, i + 5, 2, line.c_str());
    }
    wattroff(this->inventoryWindow, A_REVERSE);
  }

  wrefresh(this->inventoryWindow);
}

void Game::renderDev()
{
  werase(this->developerWindow);
  box(this->developerWindow, 0, 0);
  wbkgd(this->developerWindow, COLOR_PAIR(RED_ON_BLACK));
  int startingLine = 0;
  int lines = devConsole.getNumLogLines();
  int maxHeight = devConsole.getMaxHeight();
  if (lines > maxHeight)
  {
    startingLine = lines - maxHeight;
  }
  for (int height = 0; height < maxHeight; height++)
  {
    mvwprintw(this->developerWindow, height+1, 2, devConsole.getLogLine(startingLine+height).c_str());
  }
  wrefresh(this->developerWindow);
}

void Game::renderNarrative()
{
  werase(this->narrativeWindow);
  box(this->narrativeWindow, 0, 0);
  wbkgd(this->narrativeWindow, COLOR_PAIR(BLACK_ON_BLUE));
  mvwprintw(this->narrativeWindow, 2, 2, this->getNarrative().c_str());
  wrefresh(this->narrativeWindow);
}

void Game::renderRoom()
{
  renderWalls();
  renderDoors();
  renderItems();
}

void Game::renderWalls()
{
  for (int height = 0; height < this->rooms[this->player.getCurrentRoom()]->getMaxHeight(); height++)
  {
    for (int width = 0; width < this->rooms[this->player.getCurrentRoom()]->getMaxWidth(); width++)
    {
      char c = this->rooms[this->player.getCurrentRoom()]->getWall(height, width);
      if (c == '+' || c == '-' || c == '|' || c == ' ' || c == '\\' || c == '/')
      {
        mvwaddchWithColor(height + 1, width + 1, c, WHITE_ON_BLACK);
      }
    }
  }
}

void Game::renderDoors()
{
  Door **doors = rooms[player.getCurrentRoom()]->getDoors();

  for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxDoors(); i++)
  {
    if (doors[i] != NULL)
    {
      int doorColor = doors[i]->setColorPair(doors[i]->getColor());
      mvwaddchWithColor(doors[i]->getYPos(), doors[i]->getXPos(), doors[i]->getSymbol(), doorColor);
    }
  }
}

void Game::renderItems()
{
  Item **items = rooms[player.getCurrentRoom()]->getItems();
  
  for(int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
  {
    if (items[i] != NULL)
    {
     															//insert if color is black? same for doors, hidden doors or items? Lamp/light stretch goal 
      if (items[i]->getColor() == 1) //if color is red
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), RED_ON_BLACK);
      }
      else if (items[i]->getColor() == 2) //if color is green
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), GREEN_ON_BLACK);
      }
      else if (items[i]->getColor() == 3) //yellow
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), YELLOW_ON_BLACK);
      }
      else if (items[i]->getColor() == 4) //blue
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), BLUE_ON_BLACK);
      }
      else if (items[i]->getColor() == 5) //magenta
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), MAGENTA_ON_BLACK);
      }
      else if (items[i]->getColor() == 6) //cyan
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), CYAN_ON_BLACK);
      }
      else
      {
        mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), WHITE_ON_BLACK);
      }
    }
  }
}

void Game::renderPlayer()
{
  mvwaddchWithColor(player.getYPos(), player.getXPos(), player.getSymbol(), CYAN_ON_BLACK); // render the player
}

void Game::mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  wattron(this->worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwaddch(this->worldWindow, yPos, xPos, TILE_SYMBOL);
  wattroff(this->worldWindow, COLOR_PAIR(TILE_PAIR));
}
