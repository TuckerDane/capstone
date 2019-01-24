/* ..............................................
  @file Update.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-16
  
  
.............................................. */

#include "Update.h"

/* ..............................................
  SETTERS
  
.............................................. */

void Game::setIsComplete(bool isComplete)
{
    this->isComplete = isComplete;
}

void Game::setSpace(Space space, int spaceIndex)
{
    this->spaces[spaceIndex] = space;
}

void Game::setNarrative(string narrative)
{
    this->narrative = narrative;
}

/* ..............................................
  GETTERS
  
.............................................. */

bool Game::getIsComplete()
{
    return this->isComplete;
}

bool Game::isMoveAllowed(int y, int x)
{
    int testch;

    /* return true if the space is okay to move into */
    testch = mvwinch(this->worldWindow, y, x);
    return (((testch & A_CHARTEXT) == GRASS) || ((testch & A_CHARTEXT) == EMPTY));
}

char Game::getUserInput()
{
    return this->userInput;
}

Space Game::getSpace(int spaceIndex)
{
    return this->spaces[spaceIndex];
}

string Game::getNarrative()
{
    return this->narrative;
}

/* ..............................................
  ACTIONS
  
.............................................. */
void Game::update()
{
    player.setIsMoved(false);
    switch ((unsigned int)this->userInput)
    {
    case KEY_UP:
    case 'w':
    case 'W':
        player.setSymbol('^');
        if ((player.getYPos() > 0) && isMoveAllowed(player.getYPos() - 1, player.getXPos()))
        {
            player.move('w');
        }
        break;
    case KEY_DOWN:
    case 's':
    case 'S':
        player.setSymbol('v');
        if ((player.getYPos() < LINES - 1) && isMoveAllowed(player.getYPos() + 1, player.getXPos()))
        {
            player.move('s');
        }
        break;
    case KEY_LEFT:
    case 'a':
    case 'A':
        player.setSymbol('<');
        if ((player.getXPos() > 0) && isMoveAllowed(player.getYPos(), player.getXPos() - 1))
        {
            player.move('a');
        }
        break;
    case KEY_RIGHT:
    case 'd':
    case 'D':
        player.setSymbol('>');
        if ((player.getXPos() < COLS - 1) && isMoveAllowed(player.getYPos(), player.getXPos() + 1))
        {
            player.move('d');
        }
        break;
    case 'q':
    case 'Q':
        setIsComplete(true);
        break;
    }
}