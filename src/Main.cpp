
// Includes and namespaces
#include <iostream>
#include "../include/Game.h"
#include "../include/Board.h"
#include "../include/Snake.h"

using namespace std;



// Start of Program
int main(){
    cout << "\e[31m" << "Hello" << "\e[0m" << "World" << endl; // Testing ANSI Escape Codes


    // Initialize the Game, Board, and Snake
    class Game* gamePtr = new class Game();
    class Board* boardPtr = new class Board();
    class Snake* snakePtr = new class Snake();

    // Game loop
    while(gamePtr->get_gameLoop()){
        
        // Figure out what state the game is in
        switch(gamePtr->get_gameState()){
            // Menu : State 0
            case 0: 
                // Display Menu
                
                // Take user input


            // Playing : State 1
            case 1:

            // Endgame : State 2
            case 2:

        }






    }



    return 0;
}
