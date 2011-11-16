#include "boardwidget.h"

BoardWidget::BoardWidget(QFrame *parent) :
    QFrame(parent)
{
    this->setFocusPolicy(Qt::StrongFocus);  // Respond to keyboard event

    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    this->cells = vector< vector<Cell> >(HEIGHT, vector<Cell>(WIDTH, Cell()));
}

void BoardWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    for(unsigned int i(0); i < this->cells.size(); ++i)
    {
        for(unsigned int j(0); j < this->cells[i].size(); ++j)
        {
            // Fill the rect if the cell is non empty
            //if(false == this->cells[i][j].isBlank())
                painter.fillRect(j * SQUARE_WIDTH,
                                 i * SQUARE_HEIGHT,
                                 SQUARE_WIDTH,
                                 SQUARE_HEIGHT,
                                 this->cells[i][j].getQColor());

            // Vertical line
            painter.drawLine(QLineF(j * 10, 0.0, j * 10, HEIGHT * SQUARE_HEIGHT));
        }
        // Horizontal line
        painter.drawLine(QLineF(0.0, i * 10, WIDTH * SQUARE_WIDTH, i * 10));
    }

    // Last vertical line
    painter.drawLine(QLineF(this->cells[0].size() * 10, 0.0, this->cells[0].size() * 10, HEIGHT * SQUARE_HEIGHT));
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
    default:
        QFrame::keyPressEvent(event);
    }
    event->accept();
}
