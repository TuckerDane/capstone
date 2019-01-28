/* ..............................................
  @file Game.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <string>
#include "Console.h"
#include "Room.h"
#include "Player.h"
#include "Door.h"
#include "Key.h"

#define MAX_ROOMS 10

#define GRASS ' '
#define EMPTY ' '

#define WINDOW_WIDTH 150
#define WORLD_WINDOW_HEIGHT 30
#define NARRATIVE_WINDOW_HEIGHT 5
#define STATUS_WINDOW_HEIGHT 5

class Game
{
private:
  bool isComplete;
  char userInput;
  Player player;
  Console devConsole;
  Room *rooms[MAX_ROOMS];
  WINDOW *statusWindow;
  WINDOW *worldWindow;
  WINDOW *inventoryWindow;
  WINDOW *narrativeWindow;
  string narrative;
  WINDOW *developerWindow;
  WINDOW *currentWindow;

public:
  /* ..............................................
    GAME.CPP
    
  .............................................. */

  // CONSTRUCTORS/DESTRUCTORS
  Game();
  ~Game();

  // ACTIONS
  void run();

  /* ..............................................
    PROCESS.CPP
    
  .............................................. */

  // ACTIONS
  void process(); // gets input from the user and stores it in userInput

  /* ..............................................
    UPDATE.CPP
    
  .............................................. */

  // SETTERS
  void setIsComplete(bool isComplete);
  void setRoom(Room *room, int roomIndex);
  void setNarrative(string narrative);
  void setCurrentWindow(WINDOW *window);

  // GETTERS
  bool getIsComplete();
  bool isMoveAllowed(int y, int x);
  char getUserInput();
  Room *getRoom(int roomIndex);
  string getNarrative();
  WINDOW *getCurrentWindow();

  // ACTIONS
  void update();
  void resolveDoorMovement();

  /* ..............................................
    RENDER.CPP
    
  .............................................. */

  // ACTIONS
  void initColorPairs();
  void render();
  void renderCurrentWindow();
  void renderStatus();
  void renderWorld();
  void renderInventory();
  void renderDev();
  void renderNarrative();
  void renderRoom();
  void renderWalls();
  void renderDoors();
  void renderItems();
  void renderPlayer();
  void mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR);
};

#endif