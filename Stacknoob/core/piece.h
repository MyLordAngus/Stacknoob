#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "grid.h"

using namespace std;

class Piece : public Grid
{
public:
    Piece();

protected:
    int x;
    int y;
    int color;
    vector<Grid> positions;
    int cur_position;
};

#endif // PIECE_H
