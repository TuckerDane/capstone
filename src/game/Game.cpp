/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
.............................................. */
#include "Game.h"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

Game::Game()
{
  /* initialize ncurses */
  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  noecho();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  curs_set(0);

  /* initialize windows */
  this->statusWindow = newwin(STATUS_WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
  this->worldWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  this->narrativeWindow = newwin(NARRATIVE_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT+WORLD_WINDOW_HEIGHT, 0);
  refresh();

  /* initialize colors */
  start_color();

  init_pair(GRASS_PAIR, COLOR_BLACK, COLOR_GREEN);
  init_pair(EMPTY_PAIR, COLOR_WHITE, COLOR_BLACK);
  init_pair(MENU_PAIR, COLOR_BLACK, COLOR_BLUE);
  init_pair(DUNGEON_PAIR, COLOR_WHITE, COLOR_BLACK);
  init_pair(PLAYER_PAIR, COLOR_CYAN, COLOR_BLACK);

  /* clear the screen */
  clear();

  /* initialize player object */
  this->player.setXPos(5);
  this->player.setYPos(5);

  /* initialize spaces */

}

Game::~Game()
{
  /* Destroy ncurses */
  endwin();

  /* Destroy player */
  player.~Player();
}

/* ..............................................
  ACTIONS
  
.............................................. */

void Game::run()
{
  do
  {
    render();  // render the game state
    process(); // process player input
    update();  // update the game state
  } while (getIsComplete() != true);
}