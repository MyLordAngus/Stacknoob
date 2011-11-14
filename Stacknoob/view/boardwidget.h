#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <vector>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QPainter>

#include "core/cell.h"
#include "core/piece.h"

using namespace std;

class BoardWidget : public QFrame
{
    Q_OBJECT
public:
    explicit BoardWidget(QFrame *parent = 0);
    virtual void paintEvent(QPaintEvent* event);
    void setPaintableBoard(vector<vector<Cell> > c) { this->cells = c; };

private:
    vector<vector<Cell> > cells;
    Piece* piece;

signals:

public slots:

};

#endif // BOARDWIDGET_H
