/* ..............................................
  @file Main.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief An adventure game for CS467 Capstone
  @date 2018-12-26
  
  
.............................................. */
#include "Game.h"
#include <ncurses.h>
/* ..............................................
  @brief Main entry point to instantiate the game
  
  @return int 
.............................................. */
int main(void)
{
  initscr();
  WINDOW* win = newwin(10, 10, 10, 10);
  refresh();
  box(win, 0, 0);
  wrefresh(win);
  int c = getch();
  endwin();
  //Game myGame;
  //myGame.run();
  return 0;
}