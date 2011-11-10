#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <vector>

using namespace std;

class Game
{
protected:
    vector<Player> players;

public:
    Game();
};

#endif // GAME_H
