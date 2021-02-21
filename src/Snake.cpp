
#include "Snake.h"
using namespace std;

// Implementations of the "Snake" class functions

SnakePart::SnakePart():posX(0),posY(0){}
SnakePart::SnakePart(int col, int row):posX(col), posY(row){}

Snake::Snake(){
    currentDirection = 'r';
    gotFood = false;
    for(int i=0; i<3; i++){
        snakeBody.push_back(SnakePart(10+i,10));
    }
}

Snake::Snake(int col, int row){
    int posX = col/2;
    int posY = row/2;
    currentDirection = 'r';
    gotFood = false;
    for(int i=0; i<3; i++){
        snakeBody.push_back(SnakePart(posX+i,posY));
    }
}

void Snake::moveSnake(){
    
    return;
}

bool Snake::collision(){


    return false;
}

bool Snake::checkSnakePosition(int col, int row){
    for(int i=0; i<this->snakeBody.size(); i++){
        if(this->snakeBody[i].posX == col && this->snakeBody[i].posY == row){
            return true;
        }
    }

    return false;
}