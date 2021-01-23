
// Includes and namespaces
#include <iostream>
#include "../include/Game.h"
#include "../include/Board.h"
#include "../include/Snake.h"

using namespace std;


// Start of Program
int main(){
    cout << "Helloworld" << endl;

    class Game* Game = new class Game();
    Game->setNum(0);
    cout << Game->getNum() << endl;

    return 0;
}
