#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "board.h"
#include "workflow.h"

using namespace std;

class Player
{
protected:
    string name;
    int score;
    Board board;
    Workflow workflow;

public:
    Player(string _name,int _score);
    void setBoard(Board _board);
    Board& getBoard();
    Workflow& getWorkflow() { return this->workflow; }
};

#endif // PLAYER_H
