/* ..............................................
  @file Game.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include "Player.h"
#include "Item.h"

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
  Item item;

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

  // GETTERS
  bool getIsComplete();
  bool isMoveAllowed(int y, int x);
  char getUserInput();

  // ACTIONS
  void update();

  /* ..............................................
    RENDER.CPP
    
  .............................................. */

  // ACTIONS
  void render();
  void renderMap();
  void renderItem();
  void renderPlayer();
  void mvaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR);
};

#endif