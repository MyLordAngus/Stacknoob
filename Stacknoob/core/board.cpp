#include "board.h"
#include <stdlib.h>
#include <unistd.h>

Board::Board() :
    Grid(WIDTH, HEIGHT),
    piece(nullptr),
    next_piece(nullptr)
{
    this->cells = vector< vector<Cell>>(this->height, vector<Cell>(this->width, Cell()));
}

vector< vector<Cell> > Board::mergePieceInBoard()
{
    if(this->piece == NULL){
        return this->cells;
    }

    int x = this->piece->getX();
    int y = this->piece->getY();
    int coordX = 0, coordY = 0;

    vector<vector<Cell>> v = this->getCells();
    vector<vector<Cell>> vp = this->piece->getGrid().getCells();

    for(auto it_i = vp.begin(); it_i != vp.end(); ++it_i)
    {
        for(auto it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
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
            if(y < HEIGHT && 1 == checkCollision(DOWN))
            {
                this->piece->setY(y);
                return true;
            }
            return false;
        }
        case LEFT:
        {
            x--;
            if(x >= 0 && 1 == checkCollision(LEFT))
            {
                this->piece->setX(x);
                return true;
            }
            return false;
        }
        case RIGHT:
        {
            x++;
            if((x < WIDTH - this->piece->maxRange('X')) && 1 == checkCollision(RIGHT))
            {
                this->piece->setX(x);
                return true;
            }
            return false;
        }
        default:
            return false;
    }
}

bool Board::spin()
{
    int rotate = 2;
    while((rotate = this->checkCollision(ROTATE)) == 2){} // Wall kick if possible

    if(-1 != rotate)
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

int Board::checkCollision(directionType _direction)
{
    int x = this->piece->getX();
    int y = this->piece->getY();
    int coordX = 0, coordY = 0;
    vector<vector<Cell>> vp;

    if(_direction == ROTATE)
        vp = this->piece->nextPosition()->getCells();
    else
        vp = this->piece->getGrid().getCells();

    switch (_direction)
    {
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case ROTATE: break;
    }

    for(auto it_i = vp.begin(); it_i != vp.end(); ++it_i)
    {
        for(auto it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
        {
            if(it_j->isBlank())
                continue;

            coordX = distance(it_i->begin(), it_j) + x;
            coordY = distance(vp.begin(), it_i) + y - 3;

            if(coordX >= 0 && coordY >= 0 && coordX < WIDTH && coordY < HEIGHT)
            {
                if(!this->cells[coordY][coordX].isBlank()) { return 0; }
            }
            else
            {
                if(_direction == ROTATE) { return wallKick(coordX, coordY); }
                return 0;
            }
        }
    }
    return 1;
}

int Board::wallKick(int coordX, int coordY)
{
    if(coordX < 0){
        this->move(RIGHT);
        return 2;
    }
    if(coordX >= WIDTH){
        this->move(LEFT);
        return 2;
    }
    if(coordY < 0){
        this->move(DOWN);
        return 2;
    }
    return 0;
}

bool Board::isFull()
{
    for(unsigned int x = 0; x < this->cells[0].size(); x++)
    {
        if(!this->cells[0][x].isBlank())
            return true;
    }
    return false;
}

void Board::fillAllCells(int y)
{
    for(unsigned int x = 0; x < this->cells[y].size(); x++)
        this->cells[y][x] = Cell((colorType)(rand() % 7 + 1), false);
}


