#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(vector<Grid> & _positions, int _x, int _y, int _cur_position)
{
    this->x = _x;
    this->y = _y;
    this->positions = _positions;
    this->cur_position = _cur_position;
}

Grid& Piece::getGrid()
{
    return this->positions.at(this->cur_position);
}
