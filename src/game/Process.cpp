/* ..............................................
  @ file Process.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#include "Process.hpp"

/* ..............................................
  ACTIONS
  
.............................................. */

void Game::process()
{
  player.setPlayerInput(getch());
}