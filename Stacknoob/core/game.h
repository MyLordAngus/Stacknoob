#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>

using namespace std;

class Game
{
protected:
    vector<Player*> players;

public:
    Game(Player *_player);
    void initBoard(Player *_player);
};

#endif // GAME_H
