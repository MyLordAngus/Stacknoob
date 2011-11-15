#include "workflow.h"

Workflow::Workflow() : QObject()
{
}

Workflow::Workflow(Player* p) : QObject()
{
    this->player = p;
}

void Workflow::createPiece(Board & b)
{
    b.setPiece(PieceFactory::initPiece());
    this->updateBoardView(b);
}

void Workflow::updateBoardView(Board & b)
{
    vector<vector<Cell> > v = b.mergePieceInBoard();

    emit paintBoard(v);
}
