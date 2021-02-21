
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


    for(int i=0; i<height; i++){
        printw("#");
        for(int j=0; j<width-2; j++){
            if(i==0 || i==height-1){
                printw("#");
            }else if(this->snake->checkSnakePosition(width, height)){
                printw("@");
            }else if(this->food->checkFoodPosition(width, height)){
                printw("@");
            }
            else{
                printw(" ");
            }
            
        }
        printw("#");
    }
    // refresh();
}

void Board::drawEndgame(){

}