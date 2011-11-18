#include "player.h"

Player::Player(string _name,int _score,int _level,int _lines)
{
    this->name = _name;
    this->score = _score;
    this->lines = _lines;
    this->level = _level;
}

void Player::setBoard(Board _board)
{
    this->board = _board;
}

Board& Player::getBoard()
{
    return this->board;
}
