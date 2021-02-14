
#include "Board.h"
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
}

void Board::drawMenu(){

}

void Board::drawBoard(){
    for(int i=0; i<height; i++){
        // cout << "#";
        printw("#");
        for(int j=0; j<width-2; j++){
            if(i==0 || i==height-1){
                // cout << "#";
                printw("#");
            }else{
                // cout << " ";
                printw(" ");
            }
        }
        // cout << "#\n";
        // printw("#\n");
    }
    refresh();
}

void Board::drawEndgame(){

}