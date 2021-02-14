
// Includes and namespaces
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/Game.h"
#include "../include/Board.h"
#include "../include/Snake.h"

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

    printw("here");
    cout << "here" << endl;

    
    // // Testing out ncurses
    // initscr();                 /* Start curses mode     */
    // keypad(stdscr, true);
    // printw("Hello World !!!"); /* Print Hello World    */
    // refresh();                 /* Print it on to the real screen */
    // getch();                   /* Wait for user input */
    // endwin();                  /* End curses mode    */
    

    
    // Game loop
    while(game->get_gameLoop()){
        
        // Figure out what state the game is in
        switch(game->get_gameState()){
            // Menu : State 0
            case 0: 
                // cout << "Menu" << endl;
                board->drawMenu();
                break;

            // Playing : State 1
            case 1:
                // cout << "Board" << endl;
                board->drawBoard();
                game->checkKeyPress();
                getch();
                game->finish();
                break;

            // Endgame : State 2
            case 2:
                // cout << "Endgame" << endl;
                board->drawEndgame();
                break;

        }
        break;
    }
    
    


    return 0;
}
