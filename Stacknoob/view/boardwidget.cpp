#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    QVBoxLayout* layout = new QVBoxLayout();

    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    this->setLineWidth(2);

    this->setLayout(layout);


}

void BoardWidget::paintEvent(QPaintEvent *event)
{
}
