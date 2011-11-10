#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();

    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    this->setLineWidth(2);

    this->setLayout(layout);
}

void BoardWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    for(int i(0); i < this->cells.size(); ++i)
    {
        for(int j(0); j < this->cells.at(i).size(); ++j)
        {
            // Fill the rect if the cell is non empty
            painter.fillRect(j * 10, i * 10, 10, 10, QColor(100 * j, i * 100, 100));
        }
    }
}
