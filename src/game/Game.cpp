/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  TODO: reorder functions
  TODO: add function descriptions
.............................................. */
#include "Game.h"

/* ..............................................
  @brief Construct a new Game:: Game object
  
.............................................. */
Game::Game()
{
  /* initialize ncurses */
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
  curs_set(0);

  /* initialize colors */
  start_color();
  init_pair(GRASS_PAIR, COLOR_YELLOW, COLOR_GREEN);
  init_pair(PLAYER_PAIR, COLOR_BLACK, COLOR_GREEN);

  /* clear the screen */
  clear();

  /* TODO: initialize game map(s) as objects */

  /* initialize player object */
  this->player.setX(LINES-1);
  this->player.setY(0);
}

/* ..............................................
  @brief Destroy the Game:: Game object
  
.............................................. */
Game::~Game()
{
  /* Destroy ncurses */
  endwin();

  /* Destroy player */
  player.~Player();
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::process()
{
  this->userInput = getch();
}

/* ..............................................
  @brief 
  TODO: figure out a better way to code than switches
.............................................. */
void Game::update()
{
  player.setMoved(false);
  switch ((unsigned int)this->userInput) {
    case KEY_UP:
    case 'w':
    case 'W':
        if ((player.getY() > 0) && isMoveAllowed(player.getY() - 1, player.getX())) {
            player.move('w');
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        if ((player.getY() < LINES - 1) && isMoveAllowed(player.getY() + 1, player.getX())) {
            player.move('s');
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        if ((player.getX() > 0) && isMoveAllowed(player.getY(), player.getX() - 1)) {
            player.move('a');
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        if ((player.getX() < COLS - 1) && isMoveAllowed(player.getY(), player.getX() + 1)) {
            player.move('d');
        }
        break;
    case 'q':
    case 'Q':
        setIsComplete(true);
        break;
    }
}

/* ..............................................
  @brief 
  TODO: modularize render
  TODO: figure out a better way to code than switches
.............................................. */
void Game::render()
{
  switch ((unsigned int)this->userInput) {
    case KEY_UP:
    case 'w':
    case 'W':
        player.setSymbol('^');
        if (player.isMoved()) {
          mvaddchWithColor(player.getY()+1, player.getX(), EMPTY, EMPTY_PAIR);
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        player.setSymbol('v');
        if (player.isMoved()) {
          mvaddchWithColor(player.getY()-1, player.getX(), EMPTY, EMPTY_PAIR);
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        player.setSymbol('<');
        if (player.isMoved()) {
          mvaddchWithColor(player.getY(), player.getX()+1, EMPTY, EMPTY_PAIR);
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        player.setSymbol('>');
        if (player.isMoved()) {
          mvaddchWithColor(player.getY(), player.getX()-1, EMPTY, EMPTY_PAIR);
        }
        break;
    }
    mvaddchWithColor(player.getY(), player.getX(), player.getSymbol(), PLAYER_PAIR);
    move(player.getY(), player.getX());
    refresh();
}

/* ..............................................
  @brief  runs the game while the game is not
          complete
.............................................. */
void Game::run()
{
  renderMap();
  do {
      process();  // process player input
      update();   // update the game state
      render();   // render the game state
    }
    while (isGameComplete() != true);
}

/* ..............................................
  @brief 
  
  @param isComplete 
.............................................. */
void Game::setIsComplete(bool isComplete)
{
  this->isComplete = isComplete;
}

/* ..............................................
  @brief 
  
  @param yPos 
  @param xPos 
  @param TILE_SYMBOL 
  @param TILE_PAIR 
.............................................. */
void Game::mvaddchWithColor(int yPos, int xPos, char TILE_SYMBOL, char TILE_PAIR)
{
  attron(COLOR_PAIR(TILE_PAIR));
  mvaddch(yPos, xPos, TILE_SYMBOL);
  attroff(COLOR_PAIR(TILE_PAIR));
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Game::isGameComplete()
{
  return this->isComplete;
}

/* ..............................................
  @brief 
  
  @return char 
.............................................. */
char Game::getUserInput() {
  return this->userInput;
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::renderMap()
{
    int y, x;

    /* background */
    attron(COLOR_PAIR(GRASS_PAIR));
    for (y = 0; y < LINES; y++) {
        mvhline(y, 0, GRASS, COLS);
    }
    attroff(COLOR_PAIR(GRASS_PAIR));
}

/* ..............................................
  @brief 
  
  @param y 
  @param x 
  @return true 
  @return false 
.............................................. */
bool Game::isMoveAllowed(int y, int x)
{
  int testch;

  /* return true if the space is okay to move into */
  testch = mvinch(y, x);
  return (((testch & A_CHARTEXT) == GRASS)
          || ((testch & A_CHARTEXT) == EMPTY));
}