/* ..............................................
  @file Game.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
using namespace std;

/* ..............................................
  @brief 
  
.............................................. */
class Game
{
private:
  bool isComplete;
  char test;

public:
  Game();  // default constructor
  ~Game(); // deconstructor

  void process(); // processes game
  void update();  // updates the game state
  void render();  // renderst the game state
  void run();     // runs the game

  bool getIsComplete();
  void setIsComplete(bool isComplete);

  char getTest();
  void setTest(char test);
};

#endif