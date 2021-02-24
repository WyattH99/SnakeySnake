#include "Food.h"
using namespace std;

// Implementations of the "Food" class functions

//Constructors
Food::Food():posX(0),posY(0),apple("@"){}
Food::Food(int col, int row):posX((col/2)+5), posY(row/2), apple("@"){}

// Puts the food on the board
void Food::putFood(){


}

bool Food::checkFoodPosition(int col, int row){
    if(posX == col && posY == row){
        return true;
    }
    return false;
}