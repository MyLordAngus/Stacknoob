#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "piecefactory.h"
#include "player.h"

class Workflow
{
protected:
    Player *player;
public:
    Workflow();
    Workflow(Player *player);
    void createPiece();
};

#endif // WORKFLOW_H
