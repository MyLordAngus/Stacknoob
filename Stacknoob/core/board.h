#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "piece.h"
#include "constants.h"

enum directionType {DOWN ,LEFT ,RIGHT };

class Board : public Grid
{
public:
    Board();
    void setPiece(Piece* p) { this->piece = p; }

    /// Place the piece in a copy of grid with the right coordonate
    /// to give it to the view
    vector< vector<Cell> > mergePieceInBoard();
    /// Moving the picies
    bool move(directionType _direction);
    bool spin();

protected:
    Piece *piece;
};

#endif // BOARD_H
