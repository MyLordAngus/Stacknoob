#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent)
{
    this->workflow = 0;

    QVBoxLayout* layout = new QVBoxLayout;
    this->board = new BoardFrame(HEIGHT, WIDTH);
    layout->addWidget(this->board);

    this->setFocusPolicy(Qt::StrongFocus);  // Respond to keyboard event
    this->setLayout(layout);
}

void BoardWidget::connectWorkflow(Workflow* w)
{
    this->workflow = w;
    connect(w, SIGNAL(paintBoard(vector<vector<Cell> >)), this, SLOT(paintBoard(vector<vector<Cell> >)));
}

void BoardWidget::disconnectWorkflow()
{
    disconnect();
    this->workflow = 0;
}

void BoardWidget::paintBoard(vector<vector<Cell> > c)
{
    this->board->repaint(c);
}

void BoardWidget::keyPressEvent(QKeyEvent* event)
{
    if(NULL == this->workflow)
        QWidget::keyPressEvent(event);
    else
    {
        switch(event->key())
        {
        case Qt::Key_Down:
                this->workflow->move(DOWN);
                break;
        case Qt::Key_Left:
                this->workflow->move(LEFT);
                break;
        case Qt::Key_Right:
                this->workflow->move(RIGHT);
                break;
        case Qt::Key_Up:
                this->workflow->spin();
                break;
        case Qt::Key_Space:
                this->workflow->drop();
                break;
        default:
            QWidget::keyPressEvent(event);
        }
    }
    event->accept();
}
