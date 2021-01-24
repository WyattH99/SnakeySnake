
#include "Game.h"

// Implementations of the "Game" class functions

// Constructor
Game::Game():gameLoop(true), gameState(0){}

// Getters
bool Game::get_gameLoop() {return gameLoop;}

int Game::get_gameState() {return gameState;}

// Setters
void Game::set_gameLoop(bool foo){
    this->gameLoop = foo;
    return;
}

void Game::set_gameState(int newState){
    this->gameState = newState;
    return;
}

