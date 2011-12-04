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
    int lines;
    Board board;

public:
    Player(string);

    void setBoard(Board _board);
    int getScore() { return this->score; }
    void setScore(int _score) { this->score = _score; }
    int getLevel() { return this->level; }
    void setLevel(int _level) { this->level = _level; }
    int getlines() { return this->lines; }
    void setLines(int _lines) { this->lines = _lines; }

    Board& getBoard();
};

#endif // PLAYER_H
