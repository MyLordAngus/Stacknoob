#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <vector>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QPainter>
#include <QKeyEvent>

#include "core/cell.h"
#include "core/workflow.h"

using namespace std;

class BoardWidget : public QFrame
{
    Q_OBJECT

public:
    explicit BoardWidget(QFrame *parent = 0);
    void connectWorkflow(Workflow* w);

private:
    Workflow* workflow;

    /// The vector of cells to be printed in the view
    vector<vector<Cell> > cells;
    void paintEvent(QPaintEvent* event);
    void keyPressEvent(QKeyEvent *);

public slots:
    void paintBoard(vector<vector<Cell> >);
};

#endif // BOARDWIDGET_H
