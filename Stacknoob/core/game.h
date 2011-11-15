#ifndef GAME_H
#define GAME_H

#include <vector>

#include "player.h"

using namespace std;

class Game
{
protected:
    vector<Player*> players;

public:
    Game();
    Player* getPlayer(int i) { return this->players[i]; }
    void initBoard(Player*);
    void launchGame();

};

#endif // GAME_H
