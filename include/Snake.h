#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>

/*
    Snake will keep track of the snake position and size
*/

struct SnakePart{
    public:
    int posX, posY;
    SnakePart(); // Constructor
    SnakePart(int col, int row); // Constructor given X and Y
};

class Snake{
    // Private and Public Variables
    private:
    char currentDirection;
    bool gotFood;
    std::vector<SnakePart> snakeBody;


    public:
    Snake(); // Constructor
    Snake(int col, int row); // Constructor given position of snake

    // Class Functions
    void moveSnake();
    bool collision();
    bool checkSnakePosition(int col, int row);

    // Getters
    char get_currentDirection() {return currentDirection;}
    bool get_gotFood() {return gotFood;}
    std::vector<SnakePart> get_snakeBody() {return snakeBody;}

    // Setters
    void set_currentDirection(char newDirection) {currentDirection = newDirection;}
    void set_gotFood(bool foo) {gotFood = foo;}
    
};

#endif