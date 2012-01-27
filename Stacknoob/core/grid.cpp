#include "grid.h"

Grid::Grid()
{
}

Grid::Grid(vector<vector<Cell> > const & c) : cells(c), height(c.size()), width(c[0].size())
{
}

Grid::Grid(int w, int h) : height(h), width(w)
{
    this->cells = vector< vector<Cell> >(this->height, vector<Cell>(this->width,Cell()));
}
