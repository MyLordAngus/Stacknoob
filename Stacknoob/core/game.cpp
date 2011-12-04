#include "game.h"

Game::Game()
{
    Player* p = new Player{ "hello" };

    this->initBoard(p);
    players.push_back(p);
}

Game::~Game()
{
    delete this->workflow;
    for(Player* p : this->players)
        delete p;
}

void Game::initBoard(Player* p)
{
    this->workflow = new Workflow(p);
    p->setBoard(Board());
}

void Game::launchGame()
{
    //for(unsigned int i = 0; i < this->players.size(); i++)
    this->workflow->createPiece();
    this->workflow->startTimer();
}
