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
    void drop();
    void fixPieceInBoard();

protected:
    Player* player;

signals:
    void paintBoard(vector<vector<Cell> >);
    void updateScore(int);
    void nextPiece(vector<vector<Cell> >);
};

#endif // WORKFLOW_H
