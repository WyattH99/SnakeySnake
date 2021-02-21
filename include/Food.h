#ifndef FOOD_H
#define FOOD_H
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>

/*
    Food will keep track of the Food position
*/

class Food{
    private:
    int posX, posY;

    public:
    Food(); // Constructor
    Food(int col, int row); // Constructor given X and Y
    
    void putFood();
    bool checkFoodPosition(int col, int row);

    // Getters
    int get_posX() {return posX;}
    int get_posY() {return posY;}

    // Setters
    void set_posX(int X) {posX = X;}
    void set_posY(int Y) {posY = Y;}

};


#endif