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
  player.setXPos(5);
  player.setYPos(5);
  player.setInventoryItem(new Key("Yellow Key", 1), 0);
  player.setInventoryItem(new Key("Blue Key", 2), 1);
  player.setInventoryItem(new Key("Green Key", 3), 2);
  player.setNumItems(2);

  /* initialize Rooms */

  // room 0
  rooms[0] = new Room("rooms/generic.room");                                // init room
  rooms[0]->setDoor(new Door(5, 23, -1, -1, -1, 1, true, COLOR_YELLOW), 0); // doors
  rooms[0]->setDoor(new Door(15, 23, -1, -1, -1, 2, true, COLOR_BLUE), 1);
  rooms[0]->setDoor(new Door(10, 35, 1, 5, 2, 3, true, COLOR_GREEN), 2);
  rooms[0]->setItem(new Potion(6, 8), 0);      // potions
  rooms[0]->setItem(new Trap(6, 12), 1);       // traps
  rooms[0]->setItem(new Movable(15, 4), 2);    // movable
  rooms[0]->setItem(new Immovable(15, 12), 3); // immovable

  // room 1
  rooms[1] = new Room("rooms/round.room");                               // init room
  rooms[1]->setDoor(new Door(5, 1, 0, 10, 34, 3, true, COLOR_GREEN), 2); // doors
  rooms[1]->setItem(new Movable(5, 5, COLOR_GREEN, 1, 1), 0);            // movable
  rooms[1]->setItem(new Movable(7, 7, COLOR_RED, 1, 2), 1);

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
