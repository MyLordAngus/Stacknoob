#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    this->cells = vector< vector<Cell> >(HEIGHT, vector<Cell>(WIDTH, Cell()));

    this->setFocusPolicy(Qt::StrongFocus);  // Respond to keyboard event
    this->setLayout(new QVBoxLayout());

}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int i = 0, j = 0;

    for(vector<vector<Cell> >::iterator it_i = this->cells.begin(); it_i != this->cells.end(); ++it_i)
    {
        i = distance(this->cells.begin(), it_i);
        for(vector<Cell>::iterator it_j = it_i->begin(); it_j != it_i->end(); ++it_j)
        {
            // Fill the rect if the cell is non empty
            j = distance(it_i->begin(), it_j);
            painter.fillRect(j * SQUARE_WIDTH,
                             i * SQUARE_HEIGHT,
                             SQUARE_WIDTH,
                             SQUARE_HEIGHT,
                             it_j->getQColor());

            // Vertical line
            painter.drawLine(QLineF(j * 10, 0.0, j * 10, HEIGHT * SQUARE_HEIGHT));
        }
        // Horizontal line
        painter.drawLine(QLineF(0.0, i * 10, WIDTH * SQUARE_WIDTH, i * 10));
    }

    // Last vertical line
    painter.drawLine(QLineF(this->cells.front().size() * 10, 0.0, this->cells.front().size() * 10, HEIGHT * SQUARE_HEIGHT));
    // Last horizontal line
    painter.drawLine(QLineF(0.0, this->cells.size() * 10, WIDTH * SQUARE_WIDTH, this->cells.size() * 10));
}

void BoardWidget::connectWorkflow(Workflow* w)
{
    this->workflow = w;
    connect(w, SIGNAL(paintBoard(vector<vector<Cell> >)), this, SLOT(paintBoard(vector<vector<Cell> >)));
}

void BoardWidget::paintBoard(vector<vector<Cell> > c)
{
    this->cells = c;
    this->repaint();
}

void BoardWidget::keyPressEvent(QKeyEvent* event)
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
    default:
        QFrame::keyPressEvent(event);
    }
    event->accept();
}
