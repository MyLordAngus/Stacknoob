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
    Piece* getNextPiece() { return this->next_piece; }
    void setNextPiece(Piece* p) { this->next_piece = p; }
    Piece* getPiece() { return this->piece; }

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

    /// Check if the board is completed
    bool isFull();

protected:
    Piece *piece, *next_piece;
    vector< vector<Cell> >::iterator it_i;
    vector<Cell>::iterator it_j;
};

#endif // BOARD_H
