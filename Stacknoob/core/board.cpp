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

    vector<vector<Cell> > v = this->getCells();

    for(int i = 0; i < this->piece->getCells().size(); i++)
    {
        for(int j = 0; j < this->piece->getCells().at(i).size(); j++)
        {
            if(!this->piece->getCells().at(i).at(j).isEmpty())
            {
                if(i >= 0 && i < this->width && j >= 0 && j < this->height)
                    v.at(i + x - 2).at(j + y - 1).setIsBlank(false);
            }
        }
    }

    return v;
}

