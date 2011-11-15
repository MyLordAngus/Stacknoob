#include "piecefactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

PieceFactory::PieceFactory()
{
}

Piece* PieceFactory::initPiece()
{
    //random value
    srand( time(NULL) );
    int x = rand() % 7 + 1;

    pieceType pName;
    vector<Grid> positions;
    vector< vector<Cell> > pos;
    Cell cell;
    cell.setIsBlank(false);

    switch (x)
    {
        case 1:
        {
            //O-Tetrimino
            pName = O;
            cell.setColor(YELLOW);

            Grid oPos1 = Grid(4,4);
            pos = oPos1.getCells();
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            oPos1.setCells(pos);
            positions.push_back(oPos1);

            break;
        }
        case 2:
        {
            //I-Tetrimino
            pName = I;
            cell.setColor(CYAN);

            Grid iPos1 = Grid(4,4);
            pos = iPos1.getCells();
            pos[3][0] = cell;
            pos[3][1] = cell;
            pos[3][2] = cell;
            pos[3][3] = cell;
            iPos1.setCells(pos);
            positions.push_back(iPos1);

            Grid iPos2 = Grid(4,4);
            pos = iPos2.getCells();
            pos[0][0] = cell;
            pos[1][0] = cell;
            pos[2][0] = cell;
            pos[3][0] = cell;
            iPos2.setCells(pos);
            positions.push_back(iPos2);

            break;
        }
        case 3:
        {
            //S-Tetrimino
            pName = S;
            cell.setColor(GREEN);

            Grid sPos1 = Grid(4,4);
            pos = sPos1.getCells();
            pos[2][1] = cell;
            pos[2][2] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            sPos1.setCells(pos);
            positions.push_back(sPos1);

            Grid sPos2 = Grid(4,4);
            pos = sPos2.getCells();
            pos[1][0] = cell;
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][1] = cell;
            sPos2.setCells(pos);
            positions.push_back(sPos2);

            break;
        }
        case 4:
        {
            //Z-Tetrimino
            pName = Z;
            cell.setColor(RED);

            Grid zPos1 = Grid(4,4);
            pos = zPos1.getCells();
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][1] = cell;
            pos[3][2] = cell;
            zPos1.setCells(pos);
            positions.push_back(zPos1);

            Grid zPos2 = Grid(4,4);
            pos = zPos2.getCells();
            pos[1][1] = cell;
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][0] = cell;
            zPos2.setCells(pos);
            positions.push_back(zPos2);

            break;
        }
        case 5:
        {
            //L-Tetrimino
            pName = L;
            cell.setColor(ORANGE);

            Grid lPos1 = Grid(4,4);
            pos = lPos1.getCells();
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[2][2] = cell;
            pos[3][0] = cell;
            lPos1.setCells(pos);
            positions.push_back(lPos1);

            Grid lPos2 = Grid(4,4);
            pos = lPos2.getCells();
            pos[1][0] = cell;
            pos[2][0] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            lPos2.setCells(pos);
            positions.push_back(lPos2);

            Grid lPos3 = Grid(4,4);
            pos = lPos3.getCells();
            pos[2][2] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            pos[3][2] = cell;
            lPos3.setCells(pos);
            positions.push_back(lPos3);

            Grid lPos4 = Grid(4,4);
            pos = lPos4.getCells();
            pos[1][0] = cell;
            pos[1][1] = cell;
            pos[2][1] = cell;
            pos[3][1] = cell;
            lPos4.setCells(pos);
            positions.push_back(lPos4);

            break;
        }
        case 6:
        {
            //J-Tetrimino
            pName = J;
            cell.setColor(BLUE);

            Grid jPos1 = Grid(4,4);
            pos = jPos1.getCells();
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[2][2] = cell;
            pos[3][2] = cell;
            jPos1.setCells(pos);
            positions.push_back(jPos1);

            Grid jPos2 = Grid(4,4);
            pos = jPos2.getCells();
            pos[1][0] = cell;
            pos[2][0] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            jPos2.setCells(pos);
            positions.push_back(jPos2);

            Grid jPos3 = Grid(4,4);
            pos = jPos3.getCells();
            pos[2][0] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            pos[3][2] = cell;
            jPos3.setCells(pos);
            positions.push_back(jPos3);

            Grid jPos4 = Grid(4,4);
            pos = jPos4.getCells();
            pos[1][1] = cell;
            pos[2][1] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            jPos4.setCells(pos);
            positions.push_back(jPos4);

            break;
        }
        case 7:
        {
            //T-Tetrimino
            pName = T;
            cell.setColor(MAGENTA);

            Grid tPos1 = Grid(4,4);
            pos = tPos1.getCells();
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[2][2] = cell;
            pos[3][1] = cell;
            tPos1.setCells(pos);
            positions.push_back(tPos1);

            Grid tPos2 = Grid(4,4);
            pos = tPos2.getCells();
            pos[1][0] = cell;
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][0] = cell;
            tPos2.setCells(pos);
            positions.push_back(tPos2);

            Grid tPos3 = Grid(4,4);
            pos = tPos3.getCells();
            pos[2][1] = cell;
            pos[3][0] = cell;
            pos[3][1] = cell;
            pos[3][2] = cell;
            tPos3.setCells(pos);
            positions.push_back(tPos3);

            Grid tPos4 = Grid(4,4);
            pos = tPos4.getCells();
            pos[1][1] = cell;
            pos[2][0] = cell;
            pos[2][1] = cell;
            pos[3][1] = cell;
            tPos4.setCells(pos);
            positions.push_back(tPos4);

            break;
        }
    }

    return new Piece(positions,pName);
}
