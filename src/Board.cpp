
#include "Board.h"
#include "Snake.h"
#include "Food.h"
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

// Implementations of the "Board" class functions

// Constructor
Board::Board():width(0), height(0){}

void Board::setBoardSize(int height, int width){
    this->width = height;
    this->height = width;
    this->snake = new Snake(this->width, this->height);
    this->food = new Food(this->width+20, this->height);
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
        mvprintw(this->snake->get_snakeBody()[i].posY, this->snake->get_snakeBody()[i].posX, this->snake->get_snakeBody()[i].body);
    }
    return;
}

void Board::drawFood(){
    // Check if snake ate the food
    if(this->food->checkFoodPosition(this->snake->get_snakeBody()[0].posX, this->snake->get_snakeBody()[0].posY)){
        int row = rand() % (this->height-1) + 1;
        int col = rand() % (this->width-1) + 1;
        this->food->set_posY(row);
        this->food->set_posX(col);
        mvprintw(row, col, this->food->get_apple());
    }else{
        mvprintw(this->food->get_posY(), this->food->get_posX(), this->food->get_apple());
    }
    return;
}

void Board::drawEndgame(){

}