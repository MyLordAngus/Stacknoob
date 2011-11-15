#include "game.h"

Game::Game()
{
    Player* p = new Player("hello", 0);

    this->initBoard(p);
    players.push_back(p);
}

void Game::initBoard(Player *_player)
{
    _player->setBoard(Board());
}

void Game::launchGame()
{
    for(unsigned int i = 0; i < this->players.size(); i++)
        this->players[i]->getWorkflow().createPiece(this->players[0]->getBoard());
}
