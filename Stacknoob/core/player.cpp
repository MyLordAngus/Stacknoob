#include "player.h"
#include <string>

Player::Player(string _name,int _score)
{
    this->name = _name;
    this->score = _score;
}

void Player::setBoard(Board _board)
{
    this->board = _board;
}

Board& Player::getBoard()
{
    return this->board;
}
