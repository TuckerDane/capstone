/* ..............................................
  @ file Render.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 20196
  
  
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
  checkForNarrativeUpdate();
  renderNarrative();
}

void Game::renderStartScreen()
{
  refresh();
  renderStatus();
  colorWindow(developerWindow, RED_ON_BLACK);
  string narrative;

  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 4, 10, narrative.c_str());

  setWorldNarrative(s1);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 7, 10, narrative.c_str());
  setWorldNarrative(s2);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 8, 10, narrative.c_str());
  setWorldNarrative(s3);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 9, 10, narrative.c_str());
  setWorldNarrative(s4);

  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 12, 10, narrative.c_str());
  setWorldNarrative(s5);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 13, 10, narrative.c_str());
  setWorldNarrative(s6);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 14, 10, narrative.c_str());
  
  setWorldNarrative(s7);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 17, 10, narrative.c_str());

  setWorldNarrative("OBJECTIVE: COLLECT AND REASSEMBLE ALL 5 PIECES OF THE SHATTERED PANDORA'S CUBE");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 20, 10, narrative.c_str());

  setWorldNarrative(":: Press any key to continue ::");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 25, 57, narrative.c_str());


  setWorldNarrative("Luckily for you, this parallel universe is considerate enough to offer a tutorial room. But don't expect it to always be so generous...");
  wrefresh(developerWindow);
}

void Game::renderEndScreen()
{
refresh();
  renderStatus();
  colorWindow(developerWindow, RED_ON_BLACK);
  string narrative;

  setWorldNarrative("Congratulations! You have found and assembled all 5 pieces of Pandora's Cube and beat the game!");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 2, 25, narrative.c_str());
  setWorldNarrative("We hope you enjoyed joining us on a walk down - or rather a battle through - memory lane.");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 3, 28, narrative.c_str());
  setWorldNarrative("Please review the Game Guide to see if you missed any special features along the way.");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 4, 30, narrative.c_str());

  setWorldNarrative(e1);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 6, 68, narrative.c_str());
  setWorldNarrative("<Adventure Game>");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 10, 64, narrative.c_str());

  setWorldNarrative(e2);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 13, 66, narrative.c_str());
  setWorldNarrative(e3);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 14, 60, narrative.c_str());
  
  setWorldNarrative(e4);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 16, 64, narrative.c_str());
  setWorldNarrative(e5);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 17, 59, narrative.c_str());
  
  setWorldNarrative(e6);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 19, 66, narrative.c_str());
  setWorldNarrative(e7);
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 20, 60, narrative.c_str());

  setWorldNarrative(":: Press any key to quit ::");
  narrative = getWorldNarrative();
  mvwprintw(developerWindow, 26, 57, narrative.c_str());

  wrefresh(developerWindow);
}

void Game::renderPlayerDiedScreen()
{
  refresh();
  renderStatus();
  colorWindow(developerWindow, RED_ON_BLACK);
  string narrative = "You Died. Press any key to continue...";
  mvwprintw(developerWindow, 3, 2, narrative.c_str());
  wrefresh(developerWindow);
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
  colorWindow(statusWindow, WHITE_ON_BLACK);

  // render player's selected item
  mvwprintw(statusWindow, 1, 2, "Item");
  mvwprintw(statusWindow, 2, 2, "----");
  if (player.getInventoryItem(player.getEquippedItemIndex()) == NULL)
  {
    mvwprintw(statusWindow, 3, 2, "none");
  }
  else
  {
    int color = WHITE_ON_BLACK;
    if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_RED)
    {
      color = RED_ON_BLACK;
    }
    else if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_GREEN)
    {
      color = GREEN_ON_BLACK;
    }
    else if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_YELLOW)
    {
      color = YELLOW_ON_BLACK;
    }
    else if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_BLUE)
    {
      color = BLUE_ON_BLACK;
    }
    else if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_MAGENTA)
    {
      color = MAGENTA_ON_BLACK;
    }
    else if (player.getInventoryItem(player.getEquippedItemIndex())->getColor() == COLOR_CYAN)
    {
      color = CYAN_ON_BLACK;
    }

    wattron(statusWindow, COLOR_PAIR(color));
    mvwprintw(statusWindow, 3, 2, player.getInventoryItem(player.getEquippedItemIndex())->getSymbol().c_str());
    mvwprintw(statusWindow, 3, 4, player.getInventoryItem(player.getEquippedItemIndex())->getName().c_str());
    wattroff(statusWindow, COLOR_PAIR(color));
  }

  // render player's HP
  int hp = player.getHP();
  mvwprintw(statusWindow, 1, 22, "HP");
  mvwprintw(statusWindow, 2, 20, "------");
  wattron(statusWindow, COLOR_PAIR(RED_ON_BLACK));
  for (int i = 0; i < hp; i++)
  {
    mvwprintw(statusWindow, 3, 20 + (2 * i), "♥");
  }
  wattroff(statusWindow, COLOR_PAIR(RED_ON_BLACK));
//  wrefresh(statusWindow);

//print number of cube parts the player has
  string parts;
  parts = std::to_string(player.getNumCubeParts());
  mvwprintw(statusWindow, 1, 45, "Cube Parts");
  mvwprintw(statusWindow, 2, 43, "--------------");
  mvwprintw(statusWindow, 3, 50, parts.c_str());
  wrefresh(statusWindow);
}

void Game::renderWorld()
{
  colorWindow(worldWindow, BLACK_ON_GREEN);
  renderRoom();
  renderPlayer();
  renderEnemies();
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
      if (i == player.getEquippedItemIndex())
      {
        line = inventory[i]->getSymbol() + " " + inventory[i]->getName() + "*";
      }
      else
      {
        line = inventory[i]->getSymbol() + " " + inventory[i]->getName();
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
    else if (logLine.find("INFO") != std::string::npos)
    {
      textColor = YELLOW_ON_BLACK;
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
  renderItemNarrative();
  renderWorldNarrative();
  wrefresh(narrativeWindow);
}

void Game::renderItemNarrative()
{
  string temp = this->getItemNarrative();
  int lineLength = temp.size();
  int xCoord = 2; // 75 - (146/2)
  if (lineLength > 146)
  {
    string shortenedLine = temp.substr(0, 146);
    mvwprintw(narrativeWindow, 1, xCoord, shortenedLine.c_str());
  }
  else
  {
    xCoord = 75 - (lineLength / 2);
    mvwprintw(narrativeWindow, 1, xCoord, temp.c_str());       
  }
}

void Game::renderWorldNarrative()
{
  string temp = this->getWorldNarrative();
  int lineLength = temp.size();
  int xCoord = 2;  // 75 - (146/2)
  if (lineLength > 146)
  {
    string shortenedLine = temp.substr(0, 146);
    mvwprintw(narrativeWindow, 2, xCoord, shortenedLine.c_str());
  }
  else
  {
    xCoord = 75 - (lineLength / 2);
    mvwprintw(narrativeWindow, 2, xCoord, temp.c_str());       
  }
}

void Game::renderRoom()
{
  renderWalls();
  renderDoors();
  renderItems();
  renderTeleporters();
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
        mvwaddchWithColor(height + 1, width + 1, string(1, c), WHITE_ON_BLACK);
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

void Game::renderTeleporters()
{
  Teleporter **teleporters = rooms[player.getCurrentRoom()]->getTeleporters();

  for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxTeleporters(); i++)
  {
    if (teleporters[i] != NULL)
    {
      int teleporterColor = teleporters[i]->setColorPair(teleporters[i]->getColor(), COLOR_BLACK);
      mvwaddchWithColor(teleporters[i]->getYPos(), teleporters[i]->getXPos(), teleporters[i]->getSymbol(), teleporterColor);
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

void Game::mvwaddchWithColor(int yPos, int xPos, string TILE_SYMBOL, char TILE_PAIR)
{
  wattron(worldWindow, COLOR_PAIR(TILE_PAIR));
  mvwprintw(worldWindow, yPos, xPos, TILE_SYMBOL.c_str());
  wattroff(worldWindow, COLOR_PAIR(TILE_PAIR));
}

void Game::renderEnemies()
{
  Enemy **enemies = rooms[player.getCurrentRoom()]->getEnemies();

  for (int i = 0; i < rooms[player.getCurrentRoom()]->getMaxEnemies(); i++)
  {
    if (enemies[i] != NULL)
    {
      mvwaddchWithColor(enemies[i]->getYPos(), enemies[i]->getXPos(), enemies[i]->getSymbol(), RED_ON_BLACK); // render the player
    }
  }
}
