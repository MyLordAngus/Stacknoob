#include "board.h"

Board::Board()
{
    this->width = WIDTH;
    this->height = HEIGHT;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width, Cell()));
}

vector< vector<Cell> > Board::mergePieceInBoard()
{
    int x = this->piece->getX();
    int y = this->piece->getY();
    int coordX = 0, coordY = 0;

    vector<vector<Cell> > v = this->getCells();
    vector<vector<Cell> > vp = this->piece->getGrid().getCells();

    for(it_i = vp.begin(); it_i != vp.end(); ++it_i)
    {
        for(it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
        {
            if(!it_j->isBlank())
            {
                coordX = it_j - it_i->begin() + x;
                coordY = it_i - vp.begin() + y - 3;
                if(coordX >= 0 && coordX < this->width &&
                        coordY >= 0 && coordY < this->height)
                {
                    v[coordY][coordX] = *it_j;
                }
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
            y++;
            if(y < HEIGHT)
            {
                this->piece->setY(y);
                return true;
            }
            return false;
        }
        case LEFT:
        {
            x--;
            if(x >= 0)
            {
                this->piece->setX(x);
                return true;
            }
            return false;
        }
        case RIGHT:
        {
            x++;
            if(x < WIDTH - this->piece->maxRange('X'))
            {
                this->piece->setX(x);
                return true;
            }
            return false;
        }
    }
}

bool Board::spin()
{
    this->piece->nextPosition();
    return true;
}

int Board::deleteFullLine()
{
    unsigned int delete_line = 0, j = 0;

    for(unsigned int i = 0; i < this->cells.size(); ++i)
    {
        for(j = 0; j < this->cells[i].size(); ++j)
        {
            if(this->cells[i][j].isBlank())
                break;      // Break if there is a blank line in it
        }
        if(j == this->cells[i].size())
        {
            this->cells.erase(this->cells.begin() + i);
            this->cells.insert(this->cells.begin() ,vector<Cell>(this->width, Cell()));
            ++delete_line;
        }
    }
    return delete_line;
}
