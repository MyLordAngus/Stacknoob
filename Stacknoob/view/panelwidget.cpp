#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    this->score = new QLCDNumber;
    this->score->setDigitCount(4);

    this->layout.addWidget(score);

    this->setLayout(&layout);
}

void PanelWidget::connectWorkflow(Workflow* w)
{
    this->workflow = w;
    connect(w, SIGNAL(updateScore(int)), this, SLOT(updateScore(int)));
}


void PanelWidget::updateScore(int s)
{
    score->display(s + score->value());
}
