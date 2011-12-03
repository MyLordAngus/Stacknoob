#include "boardframe.h"

BoardFrame::BoardFrame(int h, int w, QFrame *parent) :
    QFrame(parent), height(h), width(w)
{
    this->cells = vector< vector<Cell>>(height, vector<Cell>(width, Cell()));
}

void BoardFrame::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int i = 0, j = 0;

    for(auto it_i = this->cells.begin(); it_i != this->cells.end(); ++it_i)
    {
        i = distance(this->cells.begin(), it_i);
        for(auto it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
        {
            // Fill the rect if the cell is non empty
            j = distance(it_i->begin(), it_j);
            painter.fillRect(j * SQUARE_WIDTH,
                             i * SQUARE_HEIGHT,
                             SQUARE_WIDTH,
                             SQUARE_HEIGHT,
                             it_j->getQColor());

            // Vertical line
            painter.drawLine(QLineF(j * SQUARE_HEIGHT, 0.0, j * SQUARE_HEIGHT, this->height * SQUARE_HEIGHT));
        }
        // Horizontal line
        painter.drawLine(QLineF(0.0, i * SQUARE_WIDTH, this->width * SQUARE_WIDTH, i * SQUARE_WIDTH));
    }

    // Last vertical line
    painter.drawLine(QLineF(this->cells.front().size() * SQUARE_HEIGHT, 0.0, this->cells.front().size() * SQUARE_HEIGHT, this->height * SQUARE_HEIGHT));
    // Last horizontal line
    painter.drawLine(QLineF(0.0, this->cells.size() * SQUARE_WIDTH, this->width * SQUARE_WIDTH, this->cells.size() * SQUARE_WIDTH));
}

void BoardFrame::repaint(vector<vector<Cell> >& c)
{
    this->cells = c;
    QFrame::repaint();
}
