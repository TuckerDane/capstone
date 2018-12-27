/*
	Name:			Tucker Dane Walker
	Date:			26 December 2018
	Description:	The Game Class
*/

#include "Game.h"

Game::Game() {
    setTest('a');
    setIsComplete(false);
}

Game::~Game() {

}

void Game::process() {
    char newChar;
    cin >> newChar;
    setTest(newChar);
}

void Game::update() {
    if (getTest() == 'x') {
        setIsComplete(true);
    }
    setTest(getTest()+1);
}

void Game::render() {
    cout << "The next character is: " << getTest() << "\n";
}

void Game::run() {
    cout << "GAME START\n";
    while(getIsComplete() == false) {
        process();
        update();
        render();
    }
    cout << "GAME OVER\n";
}

bool Game::getIsComplete() {
    return this->isComplete;
}

void Game::setIsComplete(bool isComplete) {
    this->isComplete = isComplete;
}

char Game::getTest() {
    return this->test;
}

void Game::setTest(char test) {
    this->test = test;
}