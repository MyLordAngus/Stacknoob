#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    QLCDNumber* score = new QLCDNumber;
    this->layout.addWidget(score);

    this->setLayout(&layout);
}
