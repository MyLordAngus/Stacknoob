#include "board.h"

Board::Board()
{
    this->width = WIDTH;
    this->height = HEIGHT;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}

vector< vector<Cell> > Board::mergePieceInBoard()
{
    int x = this->piece->getX();
    int y = this->piece->getY();
    int coordX = 0, coordY = 0;

    vector<vector<Cell> > v = this->getCells();
    vector<vector<Cell> > vp = this->piece->getGrid().getCells();

    for(unsigned int i = 0; i < vp.size(); i++)
    {
        for(unsigned int j = 0; j < vp[i].size(); j++)
        {
            if(!vp[i][j].isBlank())
            {
                coordX = j + x;
                coordY = i + y - 3;
                if(coordX >= 0 && coordX < this->width && coordY >= 0 && coordY < this->height)
                    v[coordY][coordX].setIsBlank(false);
            }
        }
    }

    return v;
}

bool Board::move(directionType _direction)
{
    int x = this->piece->getX();
    int y = this->piece->getY();

    switch (_direction)
    {
        case DOWN:
        {
            y = y + 1;
            if(y < HEIGHT){
                this->piece->setY(y);
                return true;
            }
            return false;
        }
        case LEFT:
        {
            x = x - 1;
            this->piece->setX(x);
            break;
        }
        case RIGHT:
        {
            x = x + 1;
            this->piece->setX(x);
            break;
        }
    }
}


