#ifndef GAME_H
#define GAME_H

class Game{

    private:
        int num;


    public:
        Game();
        Game(int num); // Constructor
        void setNum(int n);
        int getNum();

};

#endif