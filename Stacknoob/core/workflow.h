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

    /// Repaint the board widget
    void updateBoardView();

    /// Create/Move piece in board
    void createPiece();
    void move(directionType _direction);
    void spin();
    void drop();
    int fixPieceInBoard();

    /// Timer stuff
    void startTimer();
    void setTimerInterval(int msec);
    void stopTimer();

protected:
    Player* player;
    Board board;
    QTimer* timer;

public slots:
    void timeoutView();

signals:
    void paintBoard(vector<vector<Cell> >);
    void updateScore(int);
    void updateLevel(int);
    void updateLines(int);
    void nextPiece(vector<vector<Cell> >);
    void endGame();
};

#endif // WORKFLOW_H
