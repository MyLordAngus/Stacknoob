#include "workflow.h"

Workflow::Workflow()
{
}

Workflow::Workflow(Player *_player)
{
    this->player = _player;
}

void Workflow::createPiece()
{
    this->player->getBoard().setPiece(PieceFactory::initPiece());
}

void Workflow::updateView()
{
    vector<vector<Cell> > v = this->player->getBoard().mergePieceInBoard();
    this->b_widget->setPaintableBoard(v);
    this->b_widget->repaint();
}

