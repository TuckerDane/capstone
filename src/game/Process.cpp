/* ..............................................
  @file Process.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */
#include "Process.hpp"

/* ..............................................
  ACTIONS
  
.............................................. */

void Game::process()
{
  player.setPlayerInput(getch());
}