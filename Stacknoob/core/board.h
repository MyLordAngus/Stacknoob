#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "piece.h"

class Board : public Grid
{
public:
    Board();
    void setPiece(Piece *piece);

protected:
    Piece *piece;
};

#endif // BOARD_H
