#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <vector>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QPainter>

#include "core/cell.h"
#include "core/workflow.h"

using namespace std;

class BoardWidget : public QFrame
{
    Q_OBJECT

public:
    explicit BoardWidget(QFrame *parent = 0);
    void connectWorkflow(Workflow* w);

public slots:
    void paintBoard(vector<vector<Cell> >);

private:
    /// The vector of cells to be printed in the view
    vector<vector<Cell> > cells;
    virtual void paintEvent(QPaintEvent* event);

signals:

};

#endif // BOARDWIDGET_H
