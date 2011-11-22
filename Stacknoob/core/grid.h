#ifndef GRID_H
#define GRID_H

#include <vector>

#include "cell.h"

using namespace std;

class Grid
{
protected:
    vector< vector<Cell> > cells;
    int height;
    int width;

public:
    Grid();
    Grid(int, int);
    Grid(vector< vector<Cell> >&);
    vector< vector<Cell> >& getCells() { return this->cells; }
    void setCells(vector< vector<Cell> > c) { this->cells = c; }
};

#endif // GRID_H
