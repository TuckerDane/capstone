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

void Game::setCurrentWindow(WINDOW* window)
{
    this->currentWindow = window;
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

WINDOW* Game::getCurrentWindow()
{
    return this->currentWindow;
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
    case 'i':
    case 'I':
        if (this->getCurrentWindow() == this->worldWindow)
        {
            this->setCurrentWindow(this->inventoryWindow);
            this->setNarrative("switched to inventory window!");
            renderNarrative();
            renderInventory();
        }
        else if (this->getCurrentWindow() == this->inventoryWindow)
        {
            this->setCurrentWindow(this->worldWindow);
            this->setNarrative("switched to world window!    ");
            renderWorld();
            renderNarrative();
        }
        break;
    case '`':
    case '~':
        if (this->getCurrentWindow() != this->developerWindow)
        {
            this->setCurrentWindow(this->developerWindow);
            this->setNarrative("switched to developer window!");
        }
        else
        {
            this->setCurrentWindow(this->worldWindow);
        }
    break;
    case 'q':
    case 'Q':
        setIsComplete(true);
        break;
    }
}