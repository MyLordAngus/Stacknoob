#ifndef GAME_H
#define GAME_H

#include <vector>

#include "player.h"
#include "workflow.h"

using namespace std;

class Game
{
protected:
    vector<Player*> players;
    Workflow* workflow;

public:
    Game();
    Player* getPlayer(int i) { return this->players[i]; }
    void initBoard(Player*);
    Workflow* getWorkflow();
    void launchGame();

};

#endif // GAME_H
