/* ..............................................
  @ file Game.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
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
  nodelay(stdscr, TRUE);
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
  planted = false;
  hasBeenDamaged = false;
  narrativeOneDone = false;
  priorRoomIndex = 0;
  currentRoomIndex = 0;
  player.setCurrentRoom(0);
  player.setXPos(40);
  player.setYPos(15);
 
  player.setInventoryItem(new Potion(), 0); 
  /* initialize Rooms */

  rooms[0] = initStartRoom();
  rooms[1] = initPuzzleRoom1();
  rooms[2] = initPuzzleRoom2();
  rooms[3] = initPuzzleRoom3();
  rooms[4] = initPuzzleRoom4();
  rooms[5] = initPuzzleRoom5();
  rooms[6] = initPuzzleRoom6();
  rooms[7] = initPuzzleRoom7();
  rooms[8] = initPuzzleRoom8();
  rooms[9] = initPuzzleRoom9();
  rooms[10] = initPuzzleRoom10();
  rooms[11] = initPuzzleRoom11(); //new trap maze
  rooms[12] = initPuzzleRoom12();
  rooms[13] = initPuzzleRoom13(); //repair/end room
  rooms[14] = initPuzzleRoom14();
  rooms[15] = initExtraRoom1();
  rooms[16] = initExtraRoom2();

  /* init narrative */
  worldNarrative = "Luckily for you, this parallel universe is considerate enough to offer a tutorial room. But don't expect it to always be so generous...";
  itemNarrative = "";
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
  renderEndScreen();
  sleep(1); // display end screen for 3 seconds
  getchar();
}
