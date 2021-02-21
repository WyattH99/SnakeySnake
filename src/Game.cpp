
#include "Game.h"
#include <ncurses.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>


// Implementations of the "Game" class functions

// Constructor
Game::Game():gameLoop(true), gameState(0){}

// Initializes everything and checks if color is possible
void Game::init(void){
	srand(time(0));
	savetty();	// save terminal settings
	initscr();	// init ncurses screen
	noecho();	// don't echo input to screen
	curs_set(0);	// make cursor invisible
	cbreak();	// don't wait for new line to grab user input
	nodelay(stdscr, true);	// force getch to be a non-blocking call
	keypad(stdscr, true); // enables special characters such as esc = 27

	// if terminal has color capabilities, use them
	if (has_colors()) {
		start_color();

		// use native background color when possible
		int bg = COLOR_BLACK;
		if (use_default_colors() != ERR) bg = -1;

		// define color pairs
		init_pair(0, 0, bg);
		init_pair(1, 1, bg);
		init_pair(2, 2, bg);
		init_pair(3, 3, bg);
		init_pair(4, 4, bg);
		init_pair(5, 5, bg);
		init_pair(6, 6, bg);
		init_pair(7, 7, bg);
		init_pair(8, 8, bg);
		init_pair(9, 9, bg);
		init_pair(10, 10, bg);
		init_pair(11, 11, bg);
		init_pair(12, 12, bg);
		init_pair(13, 13, bg);
		init_pair(14, 14, bg);
		init_pair(15, 15, bg);

		// restrict color pallete in non-256color terminals (e.g. screen or linux)
		if (COLORS < 256) {
			init_pair(8, 7, bg);	// gray will look white
			init_pair(9, 1, bg);
			init_pair(10, 2, bg);
			init_pair(11, 3, bg);
			init_pair(12, 4, bg);
			init_pair(13, 5, bg);
			init_pair(14, 6, bg);
			init_pair(15, 7, bg);
		}
	} else {
		printf("%s", "Warning: terminal does not have color support.");
	}

} 


// Finish the game and clean everything up
void Game::finish(void){
    clear();
    refresh();
    endwin();
    curs_set(1);
}

// Check if the esc key was pressed
void Game::checkKeyPress(){
    if((wgetch(stdscr) != ERR) || (wgetch(stdscr) == 27)){
        this->finish();
        exit(0);
    }
}
