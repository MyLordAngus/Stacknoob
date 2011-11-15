#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();

    //this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    //this->setLineWidth(2);

    this->setLayout(layout);
    this->cells = vector< vector<Cell> >(HEIGHT, vector<Cell>(WIDTH, Cell()));
}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    for(unsigned int i(0); i < this->cells.size(); ++i)
    {
        for(unsigned int j(0); j < this->cells[i].size(); ++j)
        {
            // Fill the rect if the cell is non empty
            if(this->cells.at(i).at(j).isBlank())
                painter.fillRect(j * SQUARE_WIDTH,
                                 i * SQUARE_HEIGHT,
                                 SQUARE_WIDTH,
                                 SQUARE_HEIGHT,
                                 QColor(100, 100, 100));

            // Vertical line
            painter.drawLine(QLineF(j * 10, 0.0, j * 10, HEIGHT * SQUARE_HEIGHT));
        }
        // Horizontal line
        painter.drawLine(QLineF(0.0, i * 10, WIDTH * SQUARE_WIDTH, i * 10));
    }

    // Last vertical line
    painter.drawLine(QLineF(this->cells[0].size() * 10, 0.0, this->cells[0].size() * 10, HEIGHT * SQUARE_HEIGHT));
    // Last horizontal line
    painter.drawLine(QLineF(0.0, this->cells.size() * 10, WIDTH * SQUARE_WIDTH, this->cells.size() * 10));
}

void BoardWidget::connectWorkflow(Workflow* w)
{
    connect(w, SIGNAL(paintBoard(vector<vector<Cell> >)), this, SLOT(paintBoard(vector<vector<Cell> >)));
}

void BoardWidget::paintBoard(vector<vector<Cell> > c)
{
    this->cells = c;
    this->repaint();
}
