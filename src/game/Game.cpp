/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
.............................................. */
#include "Game.hpp"

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
  statusWindow = newwin(STATUS_WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
  worldWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  inventoryWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  developerWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  narrativeWindow = newwin(NARRATIVE_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT + WORLD_WINDOW_HEIGHT, 0);
  currentWindow = worldWindow;
  refresh();

  /* initialize colors */
  start_color();
  initColorPairs();

  /* clear the screen */
  clear();

  /* initialize Game class variables */
  isComplete = false;
  player.setCurrentRoom(0);
  player.setXPos(2);
  player.setYPos(2);

  /* initialize Rooms */

  // room 0
  rooms[0] = new Room("rooms/puzzle_2.room");
  rooms[0]->setDoor(new Door(7, 17, 0, 2, 2, 1, true, COLOR_YELLOW), 0);
  rooms[0]->setDoor(new Door(2, 1, 0, 7, 16, 1, true, COLOR_YELLOW), 1);
  rooms[0]->setItem(new Immovable(7, 2), 0);
  rooms[0]->setItem(new Immovable(6, 3), 1);
  rooms[0]->setItem(new Immovable(5, 4), 2);
  rooms[0]->setItem(new Immovable(5, 5), 3);
  rooms[0]->setItem(new Movable(3, 6), 4);
  rooms[0]->setItem(new Immovable(4, 5), 5);
  rooms[0]->setItem(new Movable(5, 6), 6);
  rooms[0]->setItem(new Immovable(4, 7), 7);
  rooms[0]->setItem(new Movable(6, 7), 8);
  rooms[0]->setItem(new Immovable(4, 8), 9);
  rooms[0]->setItem(new Immovable(5, 8), 10);
  rooms[0]->setItem(new Movable(6, 8), 11);
  rooms[0]->setItem(new Immovable(5, 9), 12);
  rooms[0]->setItem(new Immovable(6, 10), 13);
  rooms[0]->setItem(new Immovable(7, 11), 14);
  rooms[0]->setItem(new Key(7, 10, "Yellow Key", 1, COLOR_YELLOW), 15);
  // room 1

  /* init narrative */
  narrative = "default narrative";
}

Game::~Game()
{
  /* Destroy ncurses */
  endwin();
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
