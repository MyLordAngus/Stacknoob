#include "workflow.h"
#include <time.h>

Workflow::Workflow() : QObject()
{
}

Workflow::Workflow(Player* p) : QObject()
{
    this->player = p;
    this->board = p->getBoard();
}

void Workflow::createPiece()
{
    Piece* p = this->board.getNextPiece();
    if(p == NULL)
        this->board.setPiece(PieceFactory::initPiece());
    else
        this->board.setPiece(this->board.getNextPiece());

    this->board.setNextPiece(PieceFactory::initPiece());
    this->updateBoardView();

    emit nextPiece(this->board.getNextPiece()->getGrid().getCells());
}

void Workflow::updateBoardView()
{
    vector<vector<Cell> > v = this->board.mergePieceInBoard();

    emit paintBoard(v);
}

void Workflow::move(directionType _directionType)
{
    if(this->board.move(_directionType))
    {
        this->updateBoardView();
    }
    else
    {
        if(_directionType == DOWN){
            if(-1 == fixPieceInBoard())
                return;

            this->createPiece();
        }
    }
}

void Workflow::spin()
{
    if(this->board.spin())
    {
        this->updateBoardView();
    }
}

void Workflow::drop()
{
    while(this->board.move(DOWN) != false){}
    if(-1 == this->fixPieceInBoard())
        return;

    this->createPiece();
}

int Workflow::fixPieceInBoard()
{
    this->board.setCells(this->board.mergePieceInBoard());

    int score = this->board.deleteFullLine();

    if(0 < score)
    {
        this->player->setLines(this->player->getlines() + score);
        this->player->setScore(this->player->getScore() + (100 * score));
        emit(updateScore(this->player->getScore()));
        emit(updateLines(this->player->getlines()));

        int lines = this->player->getlines();
        int level = 1;

        if(lines > 1 && lines <= 90 )
        {
            level = (int)(1 + ((float(lines) - 1.0)/10.0));
        }
        else if(lines >= 91)
        {
            level = 10;
        }

        if(this->player->getLevel() != level)
        {
            this->player->setLevel(level);
            emit(updateLevel(level));

            switch (level)
            {
                case 1:  this->setTimerInterval(500); break;
                case 2:  this->setTimerInterval(450); break;
                case 3:  this->setTimerInterval(400); break;
                case 4:  this->setTimerInterval(350); break;
                case 5:  this->setTimerInterval(300); break;
                case 6:  this->setTimerInterval(250); break;
                case 7:  this->setTimerInterval(200); break;
                case 8:  this->setTimerInterval(150); break;
                case 9:  this->setTimerInterval(100); break;
                case 10: this->setTimerInterval(50); break;
            }
        }
    }

    if(this->board.isFull()){
        this->stopTimer();

        this->board.setNextPiece(0);
        this->board.setPiece(0);

        emit nextPiece(vector< vector<Cell>>(4, vector<Cell>(4, Cell())));     // delete next piece in view

        for(int y = (this->board.getCells().size() - 1); y >= 0; y--){
            this->board.fillAllCells(y);
            this->updateBoardView();
            usleep(15000);
        }

        emit endGame();

        return -1;
    }
    return 0;
}

void Workflow::startTimer()
{
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutView()));
    timer->start(500);
}

void Workflow::setTimerInterval(int msec)
{
    this->timer->setInterval(msec);
}

void Workflow::stopTimer()
{
    this->timer->stop();
}

void Workflow::timeoutView()
{
    this->move(DOWN);
    this->updateBoardView();
}
