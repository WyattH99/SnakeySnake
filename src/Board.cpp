
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>



using namespace std;

// Implementations of the "Board" class functions

// Constructor
Board::Board():width(0), height(0){}

void Board::setBoardSize(int height, int width){
    this->width = height;
    this->height = width;
    this->snake = new Snake(width, height);
    this->food = new Food(width, height);
}

void Board::drawMenu(){

}

void Board::drawBoard(){
    int col = 0;
    int row = 0;
    for(row=0; row<height; row++){ // scale y axis
        mvprintw(row, 0, "#"); // print left
        mvprintw(row, width-1, "#"); // print right
    }
    for(col=1; col<width-1; col++){
        mvprintw(0, col, "#"); // print top
        mvprintw(height-1, col, "#"); // print bottom
    }
    
}

void Board::drawSnake(){
    for(int i=0; i<this->snake->get_snakeBody().size(); i++){
        mvprintw(this->snake->get_snakeBody()[i].posY, this->snake->get_snakeBody()[i].posX, "@");
    }
    return;
}

void Board::drawEndgame(){

}