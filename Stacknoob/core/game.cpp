#include "game.h"

Game::Game()
{
    Player* p = new Player("hello", 0);

    this->initBoard(p);
    players.push_back(p);
}

void Game::initBoard(Player* p)
{
    this->workflow = new Workflow(p);
    p->setBoard(Board());
}

Workflow* Game::getWorkflow()
{
    return this->workflow;
}

void Game::launchGame()
{
    //for(unsigned int i = 0; i < this->players.size(); i++)
    this->workflow->createPiece(this->players[0]->getBoard());
}
