#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "grid.h"

using namespace std;

enum pieceType {O ,I ,S ,Z ,L ,J ,T };

class Piece : public Grid
{
public:
    Piece();
    int getX() { return this->x; }
    int getY() { return this->y; }
    void setX(int _x) { this->x = _x; }
    void setY(int _y) { this->y = _y; }
    Piece(vector<Grid> & _positions, pieceType _name, int _x = 4, int _y = 0, int _cur_position = 0);
    Grid& getGrid();
    int maxRange(char);

protected:
    int x;
    int y;
    vector<Grid> positions;
    int cur_position;
    pieceType name;
};

#endif // PIECE_H
