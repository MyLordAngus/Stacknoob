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
        for(unsigned int j = 0; j < vp.at(i).size(); j++)
        {
            if(!vp.at(i).at(j).isBlank())
            {
                coordX = i + y - 3;
                coordY = j + x - 1;
                if(coordX >= 0 && coordX < this->height && coordY >= 0 && coordY < this->width)
                    v[coordX][coordY].setIsBlank(false);
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


