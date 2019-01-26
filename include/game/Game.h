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
#include "Space.h"
#include "Player.h"

#define MAX_SPACES 10

#define GRASS ' '
#define EMPTY ' '

#define GRASS_PAIR 1
#define EMPTY_PAIR 2
#define MENU_PAIR 3
#define DUNGEON_PAIR 4
#define PLAYER_PAIR 5

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
  Space spaces[MAX_SPACES];
  WINDOW* statusWindow;
  WINDOW* worldWindow;
  WINDOW* inventoryWindow;
  WINDOW* narrativeWindow;
  string narrative;
  WINDOW* developerWindow;
  WINDOW* currentWindow;

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
  void setSpace(Space space, int spaceIndex);
  void setNarrative(string narrative);
  void setCurrentWindow(WINDOW* window);

  // GETTERS
  bool getIsComplete();
  bool isMoveAllowed(int y, int x);
  char getUserInput();
  Space getSpace(int spaceIndex);
  string getNarrative();
  WINDOW* getCurrentWindow();

  // ACTIONS
  void update();

  /* ..............................................
    RENDER.CPP
    
  .............................................. */   

  int highlight = 0;

  // ACTIONS
  void render();
  void renderCurrentWindow();
  void renderStatus();
  void renderWorld();
  void renderInventory();
  void renderDev();
  void renderNarrative();
  void renderMap();
  void renderSpace();
  void renderItem();
  void renderPlayer();
  void mvwaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR); 
};

#endif