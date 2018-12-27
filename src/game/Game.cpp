/* ..............................................
  @file Game.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Game.h"

/* ..............................................SS
  @brief Construct a new Game:: Game object
  
.............................................. */
Game::Game()
{
  setTest('a');
  setIsComplete(false);
}

/* ..............................................
  @brief Destroy the Game:: Game object
  
.............................................. */
Game::~Game()
{
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::process()
{
  char newChar;
  cin >> newChar;
  setTest(newChar);
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::update()
{
  if (getTest() == 'x')
  {
    setIsComplete(true);
  }
  setTest(getTest() + 1);
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::render()
{
  cout << "The next character is: " << getTest() << "\n";
}

/* ..............................................
  @brief 
  
.............................................. */
void Game::run()
{
  cout << "GAME START\n";
  while (getIsComplete() == false)
  {
    process();
    update();
    render();
  }
  cout << "GAME OVER\n";
}

/* ..............................................
  @brief 
  
  @return true 
  @return false 
.............................................. */
bool Game::getIsComplete()
{
  return this->isComplete;
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
  
  @return char 
.............................................. */
char Game::getTest()
{
  return this->test;
}

/* ..............................................
  @brief 
  
  @param test 
.............................................. */
void Game::setTest(char test)
{
  this->test = test;
}