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
  if (getCurrentWindow() == inventoryWindow)
  {
    renderInventory();
  }
  else if (getCurrentWindow() == worldWindow)
  {
    renderWorld();
  }
  else if (getCurrentWindow() == developerWindow)
  {
    renderDev();
  }
}

void Game::colorWindow(WINDOW *window, int colorPair)
{
  werase(window);                       // render window
  box(window, 0, 0);                    // render border
  wbkgd(window, COLOR_PAIR(colorPair)); // render color
}

void Game::renderStatus()
{
  colorWindow(statusWindow, BLACK_ON_BLUE);

  // render player's selected item
  mvwprintw(statusWindow, 1, 2, "Item");
  mvwprintw(statusWindow, 2, 2, "----");
  if (player.getInventoryItem(player.getPermSelectedItemIndex()) == NULL)
  {
    mvwprintw(statusWindow, 3, 2, "none");
  }
  else
  {
    mvwprintw(statusWindow, 3, 2, player.getInventoryItem(player.getPermSelectedItemIndex())->getName().c_str());
  }

  // render player's HP
  string hp;
  hp = std::to_string(player.getHP());
  mvwprintw(statusWindow, 1, 22, "HP");
  mvwprintw(statusWindow, 2, 20, "------");
  mvwprintw(statusWindow, 3, 22, hp.c_str());

  wrefresh(statusWindow);
}

void Game::renderWorld()
{
  colorWindow(worldWindow, BLACK_ON_GREEN);
  renderRoom();
  renderPlayer();
  wrefresh(worldWindow);
}

void Game::renderInventory()
{
  colorWindow(inventoryWindow, BLACK_ON_BLUE);

  // render inventory
  mvwprintw(inventoryWindow, 1, 2, "INVENTORY");
  mvwprintw(inventoryWindow, 2, 2, "================================================================================================================================================");
  mvwprintw(inventoryWindow, 3, 2, "Slot\tItem\t\tWeight");
  mvwprintw(inventoryWindow, 4, 2, "----\t----\t\t------");

  Item **inventory = player.getInventory();
  string line;
  for (int i = 0; i < player.getMaxInventory(); i++)
  {
    int highlightColor;
    if (i == player.getSelectedItemIndex())
    {
      if (inventory[i] == NULL)
      {
        highlightColor = WHITE_ON_BLACK;
      }
      else
      {
        highlightColor = inventory[i]->setColorPair(inventory[i]->getColor(), COLOR_BLACK);
      }
      wattron(inventoryWindow, COLOR_PAIR(highlightColor));
    }
    if (inventory[i] != NULL)
    {
      line = std::to_string(i + 1);
      mvwprintw(inventoryWindow, i + 5, 2, line.c_str());
      if(i == player.getPermSelectedItemIndex())
      {
	line = inventory[i]->getName() + "*";
      }
      else
      {
	line = inventory[i]->getName();
      }
      mvwprintw(inventoryWindow, i + 5, 8, line.c_str());
      line = std::to_string(inventory[i]->getWeight());
      mvwprintw(inventoryWindow, i + 5, 26, line.c_str());
    }
    else
    {
      line = std::to_string(i + 1) + "\tempty slot";
      mvwprintw(inventoryWindow, i + 5, 2, line.c_str());
    }
    wattroff(inventoryWindow, COLOR_PAIR(highlightColor)); 
  }

  wrefresh(inventoryWindow);
}

void Game::renderDev()
{
  colorWindow(developerWindow, RED_ON_BLACK);

  // render logfile
  int startingLine = 0;
  int lines = devConsole.getNumLogLines();
  int maxHeight = devConsole.getMaxHeight();
  if (lines > maxHeight)
  {
    startingLine = lines - maxHeight;
  }
  for (int height = 0; height < maxHeight; height++)
  {
    string logLine = devConsole.getLogLine(startingLine + height);
    int textColor;
    if (logLine.find("ERROR") != std::string::npos)
    {
      textColor = RED_ON_BLACK;
    }
    else if (logLine.find("SUCCESS") != std::string::npos)
    {
      textColor = GREEN_ON_BLACK;
    }
    else
    {
      textColor = WHITE_ON_BLACK;
    }

    wattron(developerWindow, COLOR_PAIR(textColor));
    mvwprintw(developerWindow, height + 1, 2, logLine.c_str());
    wattroff(developerWindow, COLOR_PAIR(textColor));
  }
  wrefresh(developerWindow);
}

void Game::renderNarrative()
{
  colorWindow(narrativeWindow, BLACK_ON_BLUE);
  mvwprintw(narrativeWindow, 2, 2, this->getNarrative().c_str());
  wrefresh(narrativeWindow);
}

void Game::renderRoom()
{
  renderWalls();
  renderDoors();
  renderItems();
}

void Game::renderWalls()
{
  for (int height = 0; height < rooms[player.getCurrentRoom()]->getMaxHeight(); height++)
  {
    for (int width = 0; width < rooms[player.getCurrentRoom()]->getMaxWidth(); width++)
    {
      char c = rooms[player.getCurrentRoom()]->getWall(height, width);
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
      int doorColor = doors[i]->setColorPair(doors[i]->getColor(), COLOR_BLACK);
      mvwaddchWithColor(doors[i]->getYPos(), doors[i]->getXPos(), doors[i]->getSymbol(), doorColor);
    }
  }
}

void Game::renderItems()
{
  Item **items = rooms[player.getCurrentRoom()]->getItems();

  for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxItems(); i++)
  {
    if (items[i] != NULL)
    {
      int itemColor = items[i]->setColorPair(items[i]->getColor(), COLOR_BLACK);
      mvwaddchWithColor(items[i]->getYPos(), items[i]->getXPos(), items[i]->getSymbol(), itemColor);
      //insert if color is black? same for doors, hidden doors or items? Lamp/light stretch goal
    }
  }
}

void Game::renderPlayer()
{
  mvwaddchWithColor(player.getYPos(), player.getXPos(), player.getSymbol(), CYAN_ON_BLACK); // render the player
}

void Game::mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  wattron(worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwaddch(worldWindow, yPos, xPos, TILE_SYMBOL);
  wattroff(worldWindow, COLOR_PAIR(TILE_PAIR));
}
