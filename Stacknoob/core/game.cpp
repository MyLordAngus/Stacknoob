#include "game.h"
#include "player.h"
#include "board.h"


Game::Game(Player *_player)
{
    this->initBoard(_player);
    players.push_back(_player);
}

void Game::initBoard(Player *_player)
{
    _player->setBoard(Board());
}
