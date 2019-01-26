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
  werase(this->statusWindow);
  box(this->statusWindow, 0, 0);
  wbkgd(this->statusWindow, COLOR_PAIR(MENU_PAIR));
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
  wrefresh(this->statusWindow);
}

void Game::renderWorld()
{
  box(this->worldWindow, 0, 0);
  wbkgd(this->worldWindow, COLOR_PAIR(GRASS_PAIR));
  renderRoom();
  renderPlayer();
  wrefresh(this->worldWindow);
}

void Game::renderInventory()
{
  werase(this->inventoryWindow);
  box(this->inventoryWindow, 0, 0);
  wbkgd(this->inventoryWindow, COLOR_PAIR(MENU_PAIR));

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
      line = std::to_string(i+1) + "\t" + inventory[i]->getName() + "\t" + std::to_string(inventory[i]->getWeight());
    }
    else
    {
      line = std::to_string(i+1) + "\tempty slot";
    }
    mvwprintw(this->inventoryWindow, i + 5, 2, line.c_str());
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
  mvwprintw(this->narrativeWindow, 2, 2, this->getNarrative().c_str());
  wrefresh(this->narrativeWindow);
}

void Game::renderRoom()
{
  renderWalls();
  renderDoors();
  //TODO: renderItems();
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
        mvwaddchWithColor(height + 1, width + 1, c, DUNGEON_PAIR);
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
      mvwaddchWithColor(doors[i]->getYPos(), doors[i]->getXPos(), doors[i]->getSymbol(), DUNGEON_PAIR);
    }
  }
}

void Game::renderItems()
{
  //TODO: renderItems
}

void Game::renderPlayer()
{
  mvwaddchWithColor(player.getYPos(), player.getXPos(), player.getSymbol(), PLAYER_PAIR); // render the player
}

void Game::mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  wattron(this->worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwaddch(this->worldWindow, yPos, xPos, TILE_SYMBOL);
  wattroff(this->worldWindow, COLOR_PAIR(TILE_PAIR));
}
