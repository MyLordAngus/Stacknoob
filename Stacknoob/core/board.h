#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "piece.h"

class Board : public Grid
{
public:
    Board();
    void setPiece(Piece* p) { this->piece = p; }

    /// Place the piece in a copy of grid with the right coordonate
    /// to give it to the view
    vector< vector<Cell> > mergePieceInBoard();

protected:
    Piece *piece;
};

#endif // BOARD_H
