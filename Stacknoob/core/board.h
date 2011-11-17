#ifndef BOARD_H
#define BOARD_H

#include "grid.h"
#include "piece.h"
#include "constants.h"

enum directionType {DOWN ,LEFT ,RIGHT, ROTATE };

class Board : public Grid
{
public:
    Board();
    void setPiece(Piece* p) { this->piece = p; }

    /// Place the piece in a copy of grid with the right coordonate
    /// to give it to the view
    vector< vector<Cell> > mergePieceInBoard();

    /// Moving the pieces in the board
    bool move(directionType _direction);
    /// Rotate the piece in the board
    bool spin();

    /// Test if there is a full line present and delete it
    /// Return the number of line deleted
    int deleteFullLine();
    bool checkCollision(directionType _direction);

protected:
    Piece *piece;
    vector< vector<Cell> >::iterator it_i;
    vector<Cell>::iterator it_j;
};

#endif // BOARD_H
