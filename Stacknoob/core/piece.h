#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "grid.h"

using namespace std;

enum pieceType {O ,I ,S ,Z ,L ,J ,T };

class Piece : public Grid
{
public:
    Piece(vector<Grid> &, pieceType, int _x = 4, int _y = 0);

    int getX() { return this->x; }
    void setX(int _x) { this->x = _x; }
    int getY() { return this->y; }
    void setY(int _y) { this->y = _y; }

    vector<Grid>::iterator getCurPosition() { return this->cur_position; }
    vector<Grid> & getPositions() { return this->positions; }

    Grid getGrid();

    /// Determine the X or Y coord maximum
    int maxRange(char);
    void rotate();
    vector<Grid>::iterator nextPosition();

protected:
    int x, y;
    vector<Grid> positions;
    vector<Grid>::iterator cur_position;
    pieceType name;
};

#endif // PIECE_H
