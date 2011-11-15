#include "grid.h"

Grid::Grid()
{

}

Grid::Grid(vector< vector<Cell> >& c)
{
    this->height = 4;
    this->width = 4;
    this->cells = c;
}

Grid::Grid(int _width, int _height)
{
    this->height = _height;
    this->width = _width;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}
