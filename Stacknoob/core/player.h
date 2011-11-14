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
    Player(string _name,int _score);
    void setBoard(Board _board);
    Board& getBoard();
};

#endif // PLAYER_H
