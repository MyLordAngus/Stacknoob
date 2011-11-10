#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "board.h"

using namespace std;

class Player
{
protected:
    string name;
    int score;
    Board board;
public:
    Player();
};

#endif // PLAYER_H
