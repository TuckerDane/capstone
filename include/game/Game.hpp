/* ..............................................
  @file Game.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <string>
#include "Console.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Movable.hpp"
#include "Immovable.hpp"

#define MAX_ROOMS 10

#define GRASS ' '
#define EMPTY ' '
#define WALL1 '-'
#define WALL2 '|'
#define WALL3 '\\'
#define WALL4 '/'
#define WALL5 '+'
#define DOOR '#'


#define WINDOW_WIDTH 150
#define WORLD_WINDOW_HEIGHT 30
#define NARRATIVE_WINDOW_HEIGHT 5
#define STATUS_WINDOW_HEIGHT 5

class Game
{
private:
  bool isComplete;
  unsigned int userInput;
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
  bool isNotAWall(int y, int x);
  unsigned int getUserInput();
  Room *getRoom(int roomIndex);
  string getNarrative();
  WINDOW *getCurrentWindow();

  // ACTIONS
  void update();
  void resolveDoorMovement();
  void useKey();
  void resolveHealing();  //user takes healing
  void resolveDamage();    //user takes damage
  void resolveMovingItem(char direction); //user pushes an item forward in the direction they are trying to go
  void resolveItemAction(char direction);

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
