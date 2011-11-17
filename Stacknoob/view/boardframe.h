#ifndef BOARDFRAME_H
#define BOARDFRAME_H

#include <vector>
#include <QFrame>
#include <QPainter>

#include "core/cell.h"
#include "constants.h"

using namespace std;

class BoardFrame : public QFrame
{
public:
    BoardFrame(int, int, QFrame* = 0);
    void paintEvent(QPaintEvent*);
    void repaint(vector<vector<Cell> >&);

private:
    /// The vector of cells to be printed in the view
    vector<vector<Cell> > cells;
};

#endif // BOARDFRAME_H
