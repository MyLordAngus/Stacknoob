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
    void createPiece();

    /// Repaint the board widget
    void updateBoardView();
    void move(directionType _direction);
    void spin();
    void fixPieceInBoard();

protected:
    Player* player;

signals:
    void paintBoard(vector<vector<Cell> >);
    void updateScore(int);
};

#endif // WORKFLOW_H
