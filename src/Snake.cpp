
#include "Snake.h"
#include "Food.h"
using namespace std;

// Implementations of the "Snake" class functions

SnakePart::SnakePart():posX(0),posY(0){}
SnakePart::SnakePart(int col, int row):posX(col), posY(row){}
SnakePart::SnakePart(int col, int row, char direction):posX(col), posY(row){
    switch(direction){
        // Up
        case 'u': {
            body = "^";
            break;
        } 
        // Down
        case 'd': {
            body = "v";
            break;
        }
        // Left
        case 'l': {
            body = "<";
            break;
        }
        // Right
        case 'r': {
            body = ">";
            break;
        }
    }
}

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
    for(int i=0; i<10; i++){
        snakeBody.insert(snakeBody.begin(), SnakePart(posX+i, posY, currentDirection));
    }
}

void Snake::moveSnake(int input, class Food* food){
    // Create the next snake body part
    switch(input){
        // Move up 'w' or up arrow
        case 119:
        case KEY_UP: {
            SnakePart head = SnakePart(snakeBody.begin()->posX, snakeBody.begin()->posY-1, 'u');
            snakeBody.insert(snakeBody.begin(), head);
            if(!food->checkFoodPosition(snakeBody.begin()->posX, snakeBody.begin()->posY)){
                mvprintw(snakeBody.back().posY, snakeBody.back().posX, " ");
                this->snakeBody.pop_back();
            }
            break;
        }
        // Move left 'a' or left arrow
        case 97:
        case KEY_LEFT: {
            SnakePart head = SnakePart(snakeBody.begin()->posX-1, snakeBody.begin()->posY, 'l');
            snakeBody.insert(snakeBody.begin(), head);
            if(!food->checkFoodPosition(snakeBody.begin()->posX, snakeBody.begin()->posY)){
                mvprintw(snakeBody.back().posY, snakeBody.back().posX, " ");
                this->snakeBody.pop_back();
            }
            break;
        }
        // Move down 's' or down arrow
        case 115:
        case KEY_DOWN: {
            SnakePart head = SnakePart(snakeBody.begin()->posX, snakeBody.begin()->posY+1, 'd');
            snakeBody.insert(snakeBody.begin(), head);
            if(!food->checkFoodPosition(snakeBody.begin()->posX, snakeBody.begin()->posY)){
                mvprintw(snakeBody.back().posY, snakeBody.back().posX, " ");
                this->snakeBody.pop_back();
            }
            break;
        }
        // Move right 'd' or right arrow
        case 100:
        case KEY_RIGHT: {
            SnakePart head = SnakePart(snakeBody.begin()->posX+1, snakeBody.begin()->posY, 'r');
            snakeBody.insert(snakeBody.begin(), head);
            if(!food->checkFoodPosition(snakeBody.begin()->posX, snakeBody.begin()->posY)){ // if the food is not ate delete the last segment of snake
                mvprintw(snakeBody.back().posY, snakeBody.back().posX, " ");
                this->snakeBody.pop_back();
            }
            break;
        }
        // No input
        case ERR: {
            break;
        }
    }
        
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