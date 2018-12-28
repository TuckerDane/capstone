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

#define GRASS     ' '
#define EMPTY     '.'
#define WATER     '~'
#define MOUNTAIN  '^'
#define PLAYER    '*'

#define GRASS_PAIR     1
#define EMPTY_PAIR     1
#define WATER_PAIR     2
#define MOUNTAIN_PAIR  3
#define PLAYER_PAIR    4

/* ..............................................
  @brief 
  
.............................................. */
class Game
{
private:
  bool isComplete;
  int userInput;
  Player player;

public:
  
  Game();  // default constructor
  ~Game(); // deconstructor

  void process(); // processes game
  void update();  // updates the game state
  void render();  // renderst the game state
  void run();     // runs the game

  void setIsComplete(bool isComplete); // sets whether or not the game is complete

  bool getIsComplete(); // gets the completion state of the game
  char getUserInput(); // gets keyboard input from the user

  int is_move_okay(int y, int x); // checks to see if the move is ok
  void draw_map(); // draws the map
};

#endif