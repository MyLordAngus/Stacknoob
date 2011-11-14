#include "piecefactory.h"

PieceFactory::PieceFactory()
{
}

Piece* PieceFactory::initPiece()
{

    int x = 1;
    vector<Grid> positions;

    switch (x)
    {
        case 1:
            Cell cell(BLUE,false);

            Grid jPos1 = Grid(4,4);
            vector< vector<Cell> > pos1 = jPos1.getCells();
            pos1[2][0] = cell;
            pos1[3][0] = cell;
            pos1[3][1] = cell;
            pos1[3][2] = cell;
            jPos1.setCells(pos1);

            positions.push_back(jPos1);

            return new Piece(positions);
    }
}
