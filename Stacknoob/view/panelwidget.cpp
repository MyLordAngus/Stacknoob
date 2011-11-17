#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    this->score = new QLCDNumber;
    this->score->setDigitCount(4);
    this->layout.addWidget(score);

    this->next_piece = new BoardFrame(6, 6);
    this->layout.addWidget(next_piece);

    this->setLayout(&layout);
}

void PanelWidget::connectWorkflow(Workflow* w)
{
    this->workflow = w;
    connect(w, SIGNAL(updateScore(int)), this, SLOT(updateScore(int)));
    connect(w, SIGNAL(nextPiece(vector<vector<Cell> >)), this, SLOT(udpateNextPiece(vector<vector<Cell> >)));
}


void PanelWidget::updateScore(int s)
{
    score->display(s + score->value());
}

void PanelWidget::udpateNextPiece(vector<vector<Cell> > c)
{
    c.push_back(vector<Cell>(4, Cell()));
    c.push_back(vector<Cell>(4, Cell()));

    for(vector<vector<Cell> >::iterator it = c.begin(); it != c.end(); ++it)
    {
        it->insert(it->begin(), Cell());
        it->push_back(Cell());
    }
    this->next_piece->repaint(c);
}
