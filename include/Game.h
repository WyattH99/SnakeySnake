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

        // Getters
        bool get_gameLoop();
        int get_gameState();

        // Setters
        void set_gameLoop(bool foo);
        void set_gameState(int newState);

};

#endif