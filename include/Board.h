#ifndef BOARD_H
#define BOARD_H

// #include <iostream>

/*
    Board will keep track of the placements of walls, fruit, and snake
*/


class Board{
    // Private and Public Variables
    private:
    int width;
    int height;
    class Snake* snake;
    class Food* food;

    public:
    // Constructor
    Board();

    // Class Functions
    void setBoardSize(int widthNew, int heightNew);
    void drawMenu();
    void drawBoard();
    void drawSnake();
    void drawEndgame();

    // Getters
    int get_width(){ return width;}
    int get_height(){ return height;}
    class Snake* get_snake() {return snake;}
    class Food* get_food() {return food;}

    // Setters
    void set_width(int foo){ width = foo;}
    void set_height(int foo){ height = foo;}

};

#endif