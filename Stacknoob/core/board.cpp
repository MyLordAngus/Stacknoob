#include "board.h"

Board::Board()
{
    this->width = 10;
    this->height = 20;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}

void Board::setPiece(Piece *_piece)
{
    this->piece = _piece;
}
