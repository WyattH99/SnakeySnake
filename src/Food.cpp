#include "Food.h"
using namespace std;

// Implementations of the "Food" class functions

//Constructors
Food::Food():posX(0),posY(0){}
Food::Food(int col, int row):posX((col/2)+5), posY(row/2){}

// Puts the food on the board
void Food::putFood(){


}

bool Food::checkFoodPosition(int col, int row){
    if(this->posX == col && this->posY == row){
        return true;
    }

    return false;
}