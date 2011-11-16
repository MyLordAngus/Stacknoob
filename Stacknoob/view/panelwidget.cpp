#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* score = new QLabel();
    this->layout.addWidget(score);

    this->setLayout(&layout);
}
