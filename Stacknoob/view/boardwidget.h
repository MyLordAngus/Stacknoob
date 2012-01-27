#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <vector>
#include <QWidget>
#include <QVBoxLayout>
#include <QKeyEvent>

#include "core/cell.h"
#include "core/workflow.h"
#include "boardframe.h"

using namespace std;

class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget *parent = 0);
    void connectWorkflow(Workflow *);

private:
    Workflow* workflow;
    BoardFrame* board;

    void keyPressEvent(QKeyEvent *);

public slots:
    void paintBoard(vector<vector<Cell> > &);
    void disconnectWorkflow();
};

#endif // BOARDWIDGET_H
