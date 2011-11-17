#ifndef WORKFLOW_H
#define WORKFLOW_H

#include <QObject>
#include <QTimer>

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
    void startTimer();

protected:
    Player* player;
    QTimer* timer;

public slots:
    void timeoutView();

signals:
    void paintBoard(vector<vector<Cell> >);
    void updateScore(int);
    void nextPiece(vector<vector<Cell> >);
};

#endif // WORKFLOW_H
