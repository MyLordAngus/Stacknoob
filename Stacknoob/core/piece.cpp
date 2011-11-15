#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(vector<Grid> & _positions,pieceType _name, int _x, int _y, int _cur_position) : Grid(_positions[_cur_position])
{
    this->x = _x;
    this->y = _y;
    this->positions = _positions;
    this->cur_position = _cur_position;
    this->name = _name;
}

Grid& Piece::getGrid()
{
    return this->positions.at(this->cur_position);
}

int Piece::maxRange(char position)
{
    int maxX = 0;
    for(unsigned int y = 0; y < this->cells.size(); y++)
    {
        for(unsigned int x = 0; x < this->cells[y].size(); x++)
        {
            if(!this->cells[y][x].isBlank())
            {
                if(x > maxX)
                {
                    maxX = x;
                }
            }
        }
    }

    return maxX;
}
