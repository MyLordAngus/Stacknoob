#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <vector>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QPainter>

#include "core/cell.h"

using namespace std;

class BoardWidget : public QFrame
{
    Q_OBJECT
public:
    explicit BoardWidget(QFrame *parent = 0);
    virtual void paintEvent(QPaintEvent* event);

private:
    vector<vector<Cell> > cells;

signals:

public slots:

};

#endif // BOARDWIDGET_H
