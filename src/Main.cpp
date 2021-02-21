
// Includes and namespaces
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/Game.h"
#include "../include/Board.h"
#include "../include/Snake.h"
#include "../include/Food.h"

using namespace std;



// Start of Program
int main(int argc, char **argv){
    // cout << "\e[31m" << "Hello" << "\e[0m" << "World" << endl; // Testing ANSI Escape Codes


    // Initialize the Game, Board, and Snake
    class Game* game = new class Game();
    class Board* board = new class Board();
    class Snake* snake = new class Snake();

    game->init();

    // Get the size of the terminal window for the board
    int height, width;
    getmaxyx(stdscr, height, width);
    board->setBoardSize(width, height);

    game->set_gameState(1);

    // Game loop
    while(game->get_gameLoop()){
        
        // Figure out what state the game is in
        switch(game->get_gameState()){
            // Menu : State 0
            case 0: {
                // cout << "Menu" << endl;
                board->drawMenu();
                break;
            }  

            // Playing : State 1
            case 1: {
                int ch;
                while(true){
                    
                    ch = getch();
                    if(ch != ERR && ch != 113){
                        printw("Inside while loop: %d", ch);
                        // addstr("Inside while loop: %d", ch);
                        refresh();
                    }else if(ch == 113){
                        game->set_gameLoop(false);
                        break;
                    }
                    board->drawBoard();
                    refresh();
                }
                // 
                // game->checkKeyPress();
                // getch();
                break;
            }
                
            // Endgame : State 2
            case 2: {
                // cout << "Endgame" << endl;
                board->drawEndgame();
                break;
            }
                
        }
    }

    game->finish();
    return 0;
}
