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
    Piece* getPiece() { return this->piece; }
    void setNextPiece(Piece* p) { this->next_piece = p; }
    Piece* getNextPiece() { return this->next_piece; }

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

    /// Check if there is collision
    /// 0 : Collision, abort move action
    /// 1 : No collision
    /// 2 : Collision on wall during rotation, use wall kick
    int checkCollision(directionType _direction);

    /// Implement Wall Kick rotation system
    int wallKick(int coordX, int coordY);

    /// Check if the board is completed
    bool isFull();

    void fillAllCells(int y);

protected:
    Piece *piece, *next_piece;
    vector< vector<Cell> >::iterator it_i;
    vector<Cell>::iterator it_j;
};

#endif // BOARD_H
