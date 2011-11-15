#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();

    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    this->setLineWidth(2);

    this->setLayout(layout);
    this->cells = vector< vector<Cell> >(20, vector<Cell>(10, Cell()));
}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    for(unsigned int i(0); i < this->cells.size(); ++i)
    {
        for(unsigned int j(0); j < this->cells.at(i).size(); ++j)
        {
            // Fill the rect if the cell is non empty
            if(this->cells.at(i).at(j).isEmpty())
                painter.fillRect(j * 10, i * 10, 10, 10, QColor(100, 100, 100));
        }
    }
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
