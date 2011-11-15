#ifndef GRID_H
#define GRID_H

#include <vector>

#include "cell.h"

using namespace std;

class Grid
{
protected:
    int width;
    int height;
    vector< vector<Cell> > cells;

public:
    Grid();
    Grid(int, int);
    Grid(vector< vector<Cell> >&);
    vector< vector<Cell> >& getCells() { return this->cells; }
    void setCells(vector< vector<Cell> > c) { this->cells = c; }
};

#endif // GRID_H
