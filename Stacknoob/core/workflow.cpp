#include "workflow.h"

Workflow::Workflow() : QObject()
{
}

Workflow::Workflow(Player* p) : QObject()
{
    this->player = p;
}

void Workflow::createPiece()
{
    this->player->getBoard().setPiece(PieceFactory::initPiece());
    this->updateBoardView();
}

void Workflow::updateBoardView()
{
    vector<vector<Cell> > v = this->player->getBoard().mergePieceInBoard();

    emit paintBoard(v);
}

void Workflow::move(directionType _directionType)
{
    if(this->player->getBoard().move(_directionType))
    {
        this->updateBoardView();
    }
}
