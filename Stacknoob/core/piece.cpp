#include "piece.h"

Piece::Piece(vector<Grid> & p, pieceType n, int _x, int _y) : Grid(p[0].getCells()), x(_x), y(_y), positions(p), name(n)
{
    this->cur_position = this->positions.begin();
}

Grid Piece::getGrid()
{
    return *(this->cur_position);
}

int Piece::maxRange(char position)
{
    unsigned int maxX = 0, maxY = 0;

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

void Piece::rotate()
{
    this->cur_position = this->nextPosition();
    this->cells = this->cur_position->getCells();
}

vector<Grid>::iterator Piece::nextPosition()
{
    vector<Grid>::iterator pos = this->cur_position;
    if(++pos == this->positions.end())
    {
        return this->positions.begin();
    }
    return pos;
}
