#ifndef WORKFLOW_H
#define WORKFLOW_H

#include "piecefactory.h"
#include "player.h"
#include "view/boardwidget.h"

class Workflow
{
protected:
    Player *player;
    BoardWidget* b_widget;

public:
    Workflow();
    Workflow(Player *player);
    void createPiece();
    void setBWidget(BoardWidget* w) { this->b_widget = w; }
    void updateView();
};

#endif // WORKFLOW_H
