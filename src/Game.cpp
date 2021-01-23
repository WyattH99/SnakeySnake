
#include "Game.h"

// Implementations of the "Game" class functions

// Constructor
Game::Game():num(0) {}

Game::Game(int n): num(n) {}

int Game::getNum(){
    return num;
}

void Game::setNum(int n){
    num = n;
}

