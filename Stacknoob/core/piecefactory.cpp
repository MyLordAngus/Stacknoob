#include "piecefactory.h"

PieceFactory::PieceFactory()
{
}

Piece* PieceFactory::initPiece()
{
    return new Piece();
}
