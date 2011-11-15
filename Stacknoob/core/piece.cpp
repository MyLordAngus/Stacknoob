#include "piece.h"

Piece::Piece()
{
}

Piece::Piece(vector<Grid> & p, pieceType n, int _x, int _y, int cur_pos) :
    Grid(p[cur_pos]), x(_x), y(_y), positions(p), cur_position(cur_pos), name(n)
{
}

Grid& Piece::getGrid()
{
    return this->positions.at(this->cur_position);
}

int Piece::maxRange(char position)
{
    int maxX = 0, maxY = 0;

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

                if(y > maxY)
                {
                    maxY = y;
                }
            }
        }
    }

    return (position == 'Y') ? maxY : maxX;
}
