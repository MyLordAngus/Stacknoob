#include "workflow.h"

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
    }else
    {
        if(_directionType == DOWN){
            fixPieceInBoard();
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
    this->fixPieceInBoard();
    this->createPiece();
}

void Workflow::fixPieceInBoard()
{
    this->board.setCells(this->board.mergePieceInBoard());

    int score = this->board.deleteFullLine();
    if(0 < score)
    {
        emit(updateScore(100 * score));
    }
}

void Workflow::startTimer()
{
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeoutView()));
    timer->start(500);
}

void Workflow::timeoutView()
{
    this->move(DOWN);
    this->updateBoardView();
}
