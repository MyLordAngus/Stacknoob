#include "workflow.h"

Workflow::Workflow() : QObject()
{
}

Workflow::Workflow(Player* p) : QObject()
{
    this->player = p;
}

void Workflow::createPiece()
{
    Piece* p = this->player->getBoard().getNextPiece();
    if(p == NULL)
        this->player->getBoard().setPiece(PieceFactory::initPiece());
    else
        this->player->getBoard().setPiece(this->player->getBoard().getNextPiece());

    this->player->getBoard().setNextPiece(PieceFactory::initPiece());
    this->updateBoardView();

    emit nextPiece(this->player->getBoard().getNextPiece()->getGrid().getCells());
}

void Workflow::updateBoardView()
{
    vector<vector<Cell> > v = this->player->getBoard().mergePieceInBoard();

    emit paintBoard(v);
}

void Workflow::move(directionType _directionType)
{
    if(this->player->getBoard().move(_directionType))
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
    if(this->player->getBoard().spin())
    {
        this->updateBoardView();
    }
}

void Workflow::drop()
{
    while(this->player->getBoard().move(DOWN) != false){}
    this->fixPieceInBoard();
    this->createPiece();
}

void Workflow::fixPieceInBoard()
{
    this->player->getBoard().setCells(this->player->getBoard().mergePieceInBoard());

    int score = this->player->getBoard().deleteFullLine();
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
