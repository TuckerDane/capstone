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
  statusWindow = newwin(STATUS_WINDOW_HEIGHT, WINDOW_WIDTH, 0, 0);
  worldWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  inventoryWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  developerWindow = newwin(WORLD_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT, 0);
  narrativeWindow = newwin(NARRATIVE_WINDOW_HEIGHT, WINDOW_WIDTH, STATUS_WINDOW_HEIGHT + WORLD_WINDOW_HEIGHT, 0);
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

  /* initialize Game class variables */
  isComplete = false;
  player.setCurrentRoom(0);
  player.setXPos(5);
  player.setYPos(5);
  player.setInventoryItem(new Key("Yellow Key", 1), 0);
  player.setInventoryItem(new Key("Blue Key", 2), 1);
  player.setNumItems(2);

  /* initialize Rooms */

  // room 0
  rooms[0] = new Room("rooms/generic.room");
  rooms[0]->setDoor(new Door(5, 23, 1, 0, 1, true), 0);
  rooms[0]->setDoor(new Door(15, 23, 1, 0, 2, true), 1);

  narrative = "default narrative";
  currentWindow = worldWindow;
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