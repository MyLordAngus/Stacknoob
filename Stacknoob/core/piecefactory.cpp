#include "piecefactory.h"
#include <stdlib.h>

PieceFactory::PieceFactory()
{
}

Piece* PieceFactory::initPiece()
{
    int x = rand() % 7 + 1;

    pieceType p_name;
    vector<Grid> positions;
    vector< vector<Cell> > cur_pos;
    Cell cell;
    cell.setIsBlank(false);

    switch (x)
    {
        case 1:
        {
            //O-Tetrimino
            p_name = O;
            cell.setColor(YELLOW);

            Grid oPos1 = Grid(4,4);
            cur_pos = oPos1.getCells();
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            oPos1.setCells(cur_pos);
            positions.push_back(oPos1);

            break;
        }
        case 2:
        {
            //I-Tetrimino
            p_name = I;
            cell.setColor(CYAN);

            Grid iPos1 = Grid(4,4);
            cur_pos = iPos1.getCells();
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            cur_pos[3][2] = cell;
            cur_pos[3][3] = cell;
            iPos1.setCells(cur_pos);
            positions.push_back(iPos1);

            Grid iPos2 = Grid(4,4);
            cur_pos = iPos2.getCells();
            cur_pos[0][0] = cell;
            cur_pos[1][0] = cell;
            cur_pos[2][0] = cell;
            cur_pos[3][0] = cell;
            iPos2.setCells(cur_pos);
            positions.push_back(iPos2);

            break;
        }
        case 3:
        {
            //S-Tetrimino
            p_name = S;
            cell.setColor(GREEN);

            Grid sPos1 = Grid(4,4);
            cur_pos = sPos1.getCells();
            cur_pos[2][1] = cell;
            cur_pos[2][2] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            sPos1.setCells(cur_pos);
            positions.push_back(sPos1);

            Grid sPos2 = Grid(4,4);
            cur_pos = sPos2.getCells();
            cur_pos[1][0] = cell;
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][1] = cell;
            sPos2.setCells(cur_pos);
            positions.push_back(sPos2);

            break;
        }
        case 4:
        {
            //Z-Tetrimino
            p_name = Z;
            cell.setColor(RED);

            Grid zPos1 = Grid(4,4);
            cur_pos = zPos1.getCells();
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][1] = cell;
            cur_pos[3][2] = cell;
            zPos1.setCells(cur_pos);
            positions.push_back(zPos1);

            Grid zPos2 = Grid(4,4);
            cur_pos = zPos2.getCells();
            cur_pos[1][1] = cell;
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][0] = cell;
            zPos2.setCells(cur_pos);
            positions.push_back(zPos2);

            break;
        }
        case 5:
        {
            //L-Tetrimino
            p_name = L;
            cell.setColor(ORANGE);

            Grid lPos1 = Grid(4,4);
            cur_pos = lPos1.getCells();
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[2][2] = cell;
            cur_pos[3][0] = cell;
            lPos1.setCells(cur_pos);
            positions.push_back(lPos1);

            Grid lPos2 = Grid(4,4);
            cur_pos = lPos2.getCells();
            cur_pos[1][0] = cell;
            cur_pos[2][0] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            lPos2.setCells(cur_pos);
            positions.push_back(lPos2);

            Grid lPos3 = Grid(4,4);
            cur_pos = lPos3.getCells();
            cur_pos[2][2] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            cur_pos[3][2] = cell;
            lPos3.setCells(cur_pos);
            positions.push_back(lPos3);

            Grid lPos4 = Grid(4,4);
            cur_pos = lPos4.getCells();
            cur_pos[1][0] = cell;
            cur_pos[1][1] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][1] = cell;
            lPos4.setCells(cur_pos);
            positions.push_back(lPos4);

            break;
        }
        case 6:
        {
            //J-Tetrimino
            p_name = J;
            cell.setColor(BLUE);

            Grid jPos1 = Grid(4,4);
            cur_pos = jPos1.getCells();
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[2][2] = cell;
            cur_pos[3][2] = cell;
            jPos1.setCells(cur_pos);
            positions.push_back(jPos1);

            Grid jPos2 = Grid(4,4);
            cur_pos = jPos2.getCells();
            cur_pos[1][0] = cell;
            cur_pos[1][1] = cell;
            cur_pos[2][0] = cell;
            cur_pos[3][0] = cell;
            jPos2.setCells(cur_pos);
            positions.push_back(jPos2);

            Grid jPos3 = Grid(4,4);
            cur_pos = jPos3.getCells();
            cur_pos[2][0] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            cur_pos[3][2] = cell;
            jPos3.setCells(cur_pos);
            positions.push_back(jPos3);

            Grid jPos4 = Grid(4,4);
            cur_pos = jPos4.getCells();
            cur_pos[1][1] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            jPos4.setCells(cur_pos);
            positions.push_back(jPos4);

            break;
        }
        case 7:
        {
            //T-Tetrimino
            p_name = T;
            cell.setColor(MAGENTA);

            Grid tPos1 = Grid(4,4);
            cur_pos = tPos1.getCells();
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[2][2] = cell;
            cur_pos[3][1] = cell;
            tPos1.setCells(cur_pos);
            positions.push_back(tPos1);

            Grid tPos2 = Grid(4,4);
            cur_pos = tPos2.getCells();
            cur_pos[1][0] = cell;
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][0] = cell;
            tPos2.setCells(cur_pos);
            positions.push_back(tPos2);

            Grid tPos3 = Grid(4,4);
            cur_pos = tPos3.getCells();
            cur_pos[2][1] = cell;
            cur_pos[3][0] = cell;
            cur_pos[3][1] = cell;
            cur_pos[3][2] = cell;
            tPos3.setCells(cur_pos);
            positions.push_back(tPos3);

            Grid tPos4 = Grid(4,4);
            cur_pos = tPos4.getCells();
            cur_pos[1][1] = cell;
            cur_pos[2][0] = cell;
            cur_pos[2][1] = cell;
            cur_pos[3][1] = cell;
            tPos4.setCells(cur_pos);
            positions.push_back(tPos4);

            break;
        }
    }

    return new Piece(positions, p_name);
}
