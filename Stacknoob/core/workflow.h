#ifndef WORKFLOW_H
#define WORKFLOW_H

#include <QObject>

#include "piecefactory.h"
#include "board.h"
#include "player.h"

class Workflow : public QObject
{
    Q_OBJECT

public:
    Workflow();
    Workflow(Player*);
    void createPiece(Board & b);

    /// Repaint the board widget
    void updateBoardView(Board & b);

protected:
    Player* player;

signals:
    void paintBoard(vector<vector<Cell> >);
};

#endif // WORKFLOW_H
