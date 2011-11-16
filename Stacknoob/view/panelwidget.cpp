#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    QLabel* score = new QLabel();
    score->setText("hello");

    this->layout.addWidget(score);
    this->setLayout(&layout);
}
