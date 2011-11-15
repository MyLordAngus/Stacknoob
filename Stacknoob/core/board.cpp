#include "board.h"

Board::Board()
{
    this->width = 10;
    this->height = 20;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}

void Board::setPiece(Piece *_piece)
{
    this->piece = _piece;
}

vector< vector<Cell> > Board::mergePieceInBoard()
{
    int x = this->piece->getX();
    int y = this->piece->getY();

    int coordX = 0, coordY = 0;

    vector<vector<Cell> > v = this->getCells();

    for(unsigned int i = 0; i < this->piece->getCells().size(); i++)
    {
        for(unsigned int j = 0; j < this->piece->getCells().at(i).size(); j++)
        {
            if(!this->piece->getCells()[i][j].isEmpty())
            {
                coordX = i + y - 3;
                coordY = j + x - 1;
                if(coordX >= 0 && coordX < this->width && coordY >= 0 && coordY < this->height)
                    v[coordX][coordY].setIsBlank(false);
            }
        }
    }

    return v;
}

