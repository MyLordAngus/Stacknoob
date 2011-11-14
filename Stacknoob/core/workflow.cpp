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
