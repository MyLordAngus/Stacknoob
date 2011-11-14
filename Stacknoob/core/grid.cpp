#include "grid.h"

Grid::Grid()
{

}

Grid::Grid(int _width, int _height)
{
    this->height = _height;
    this->width = _width;
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}
