#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#include "piece.h"

class PieceFactory
{
public:
    PieceFactory();
    static Piece* initPiece();
};

#endif // PIECEFACTORY_H
