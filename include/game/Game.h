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

#define GRASS     ' '
#define EMPTY     ' '

#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define PLAYER_PAIR    4

/* ..............................................
  @brief 
  
.............................................. */
class Game
{
private:
  bool isComplete;  // tells if the game is complete or not
  char userInput;  // holds the user's last keystroke
  Player player; // the player object
  Item item;
  int playersPreviousXpos;
  int playersPreviousYpos;

public:
  
  Game();  // default constructor
  ~Game(); // deconstructor

  void process(); // processes game
  void update();  // updates the game state
  void render();  // renders the game state
  void renderPlayer();  // renders player if moved
  void renderItem();
  void run();     // runs the game
  void renderMap(); // draws the map
  void mvaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR);
  void setIsComplete(bool isComplete); // sets whether or not the game is complete
  void setPlayersPreviousXpos(int xPos);
  void setPlayersPreviousYpos(int yPos);

  int getPlayersPreviousXpos();
  int getPlayersPreviousYpos();

  char getUserInput(); // gets the value of the player's last keystroke

  bool isGameComplete(); // gets the completion state of the game
  bool isMoveAllowed(int y, int x); // checks to see if the move is ok
};

#endif