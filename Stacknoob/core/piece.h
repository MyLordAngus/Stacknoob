#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "grid.h"

using namespace std;

class Piece : public Grid
{
public:
    Piece();
    int getX() { return this->x; }
    int getY() { return this->y; }
    Piece(vector<Grid> & _positions, int _x = 4, int _y = 0, int _cur_position = 0);
    Grid& getGrid();

protected:
    int x;
    int y;
    vector<Grid> positions;
    int cur_position;
};

#endif // PIECE_H
