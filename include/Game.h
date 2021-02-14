#ifndef GAME_H
#define GAME_H

/*
    Game will keep track of the Game state, and handles players input.
    States: 
        - Menu : State 0
        - Playing : State 1
        - Endgame : State 2
            - Show stats
            - Replay?
*/

class Game{

    private:
        bool gameLoop;
        int gameState;

    public:
        //Constructor
        Game();
        void init(void); // Initializes everything and checks if color is possible
        void finish(void); // Finishes game and cleans everything up
        void checkKeyPress(); // Checks if esc key was pressed
        

        // Getters
        bool get_gameLoop(){ return gameLoop;}
        int get_gameState(){ return gameState;}

        // Setters
        void set_gameLoop(bool foo){ gameLoop = foo;}
        void set_gameState(int newState){ gameState = newState;}

};

#endif