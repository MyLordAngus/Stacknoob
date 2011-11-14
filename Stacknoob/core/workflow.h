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
    Workflow(Player*);
    void createPiece();
    void setBWidget(BoardWidget* w) { this->b_widget = w; }

    /// Repaint the board widget
    void updateBoardView();
};

#endif // WORKFLOW_H
