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
    int level;
    Board board;

public:
    Player(string _name,int _score = 0,int _level = 0);
    void setBoard(Board _board);
    int getScore() { return this->score; }
    void setScore(int _score) { this->score = _score; }
    void setLevel(int _level) { this->level = _level; }
    Board& getBoard();
};

#endif // PLAYER_H
