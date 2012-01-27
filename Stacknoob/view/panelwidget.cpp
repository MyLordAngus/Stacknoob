#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent) :
    QWidget(parent)
{
    this->score = new QLCDNumber;
    this->score->setDigitCount(4);
    this->layout.addWidget(score);

    this->next_piece = new BoardFrame(6, 6);
    this->layout.addWidget(next_piece);

    QVBoxLayout* bottom_layout = new QVBoxLayout;

    this->level = new QLabel;
    this->level->setText("Level : 1");
    bottom_layout->addWidget(level);

    this->lines = new QLabel;
    this->lines->setText("Lines : 0");
    bottom_layout->addWidget(lines);

    this->layout.addLayout(bottom_layout);

    this->setLayout(&layout);
}

void PanelWidget::connectWorkflow(Workflow* w)
{
    this->workflow = w;
    connect(w, SIGNAL(updateScore(int)), this, SLOT(updateScore(int)));
    connect(w, SIGNAL(nextPiece(vector<vector<Cell> > &)), this, SLOT(udpateNextPiece(vector<vector<Cell> > &)));
    connect(w, SIGNAL(updateLevel(int)), this, SLOT(updateLevel(int)));
    connect(w, SIGNAL(updateLines(int)), this, SLOT(updateLines(int)));
}


void PanelWidget::updateScore(int s)
{
    score->display(s);
}

void PanelWidget::updateLevel(int l)
{
    this->level->setText("Level : " + QString::number(l));
}

void PanelWidget::updateLines(int l)
{
    this->lines->setText("Lines : " + QString::number(l));
}

void PanelWidget::udpateNextPiece(vector<vector<Cell>> & c)
{
    c.push_back(vector<Cell>(4, Cell()));
    c.push_back(vector<Cell>(4, Cell()));

    for(auto it = c.begin(); it != c.end(); ++it)
    {
        it->insert(it->begin(), Cell());
        it->push_back(Cell());
    }
    this->next_piece->repaint(c);
}
