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
};

#endif // GRID_H
