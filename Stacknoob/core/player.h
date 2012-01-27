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

    void setBoard(Board const &);
    int getScore() { return this->score; }
    void setScore(int s) { this->score = s; }
    int getLevel() { return this->level; }
    void setLevel(int l) { this->level = l; }
    int getlines() { return this->lines; }
    void setLines(int l) { this->lines = l; }

    Board& getBoard();
};

#endif // PLAYER_H
