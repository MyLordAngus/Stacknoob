#include "player.h"

Player::Player(string n) :
    name(n),
    score(0),
    level(1),
    lines(0)
{
}

void Player::setBoard(Board _board)
{
    this->board = _board;
}

Board& Player::getBoard()
{
    return this->board;
}
