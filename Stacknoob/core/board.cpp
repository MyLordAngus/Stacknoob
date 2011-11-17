#include "board.h"

Board::Board() : piece(0), next_piece(0), Grid(WIDTH, HEIGHT)
{
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
                coordX = distance(it_i->begin(), it_j) + x;
                coordY = distance(vp.begin(), it_i) + y - 3;
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
            if(y < HEIGHT && checkCollision(DOWN))
            {
                this->piece->setY(y);
                return true;
            }
            return false;
        }
        case LEFT:
        {
            x--;
            if(x >= 0 && checkCollision(LEFT))
            {
                this->piece->setX(x);
                return true;
            }
            return false;
        }
        case RIGHT:
        {
            x++;
            if((x < WIDTH - this->piece->maxRange('X')) && checkCollision(RIGHT))
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
    if(this->checkCollision(ROTATE))
    {
        this->piece->rotate();
        return true;
    }
    return false;
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
        if(j == this->cells[i].size())  // We have inspect all cell on a line without break
        {
            this->cells.erase(this->cells.begin() + i);
            this->cells.insert(this->cells.begin(), vector<Cell>(this->width, Cell()));
            ++delete_line;
        }
    }
    return delete_line;
}

bool Board::checkCollision(directionType _direction)
{
    int x = this->piece->getX();
    int y = this->piece->getY();
    int coordX = 0, coordY = 0;
    vector<vector<Cell> > vp;

    if(_direction == ROTATE){
         vp = this->piece->getPositions().at(this->piece->nextPosition()).getCells();
    }else{
         vp = this->piece->getGrid().getCells();
    }

    switch (_direction)
    {
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case ROTATE: break;
    }

    for(it_i = vp.begin(); it_i != vp.end(); ++it_i)
    {
        for(it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
        {
            if(!it_j->isBlank())
            {
                coordX = distance(it_i->begin(), it_j) + x;
                coordY = distance(vp.begin(), it_i) + y - 3;

                if(coordX >= 0 && coordY >= 0 && coordX < WIDTH && coordY < HEIGHT)
                {
                    if(!this->cells[coordY][coordX].isBlank())
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board::isFull()
{
    for(int x = 0; x < this->cells[0].size(); x++)
    {
        if(!this->cells[0][x].isBlank())
        {
            return true;
        }
    }
}
