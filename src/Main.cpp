/* ..............................................
  @file Main.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief An adventure game for CS467 Capstone
  @date 2018-12-26
  
  
.............................................. */
#include "Game.h"
#include "Space.h"
/* ..............................................
  @brief Main entry point to instantiate the game
  
  @return int 
.............................................. */
int main(void)
{
  Game myGame;
  myGame.run();
  return 0;
}