/* ..............................................
  @file Game.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include "Space.h"
#include "Player.h"

#define MAX_SPACES 10

#define GRASS ' '
#define EMPTY ' '

#define GRASS_PAIR 1
#define EMPTY_PAIR 1
#define PLAYER_PAIR 4

class Game
{
private:
  bool isComplete;
  char userInput;
  Player player;
  Space spaces[MAX_SPACES];
  WINDOW* worldWindow;
  WINDOW* statusWindow;
  WINDOW* inventoryWindow;
  WINDOW* narrativeWindow;

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

  // GETTERS
  bool getIsComplete();
  bool isMoveAllowed(int y, int x);
  char getUserInput();
  Space getSpace(int spaceIndex);

  // ACTIONS
  void update();

  /* ..............................................
    RENDER.CPP
    
  .............................................. */   

  // ACTIONS
  void render();
  void renderWorld();
  void renderMap();
  void renderSpace();
  void renderItem();
  void renderPlayer();
  void mvaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR); 
  // comment by marisa    
};

#endif