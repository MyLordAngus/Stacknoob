#ifndef GAME_H
#define GAME_H

#include <vector>

#include "player.h"
#include "workflow.h"

using namespace std;

class Game
{
public:
    Game();
    ~Game();

    Player* getPlayer(int i) { return this->players[i]; }
    Workflow* getWorkflow() { return this->workflow; }

    void initBoard(Player*);
    void launchGame();

private:
    int level_number;
    vector<Player*> players;
    Workflow* workflow;

};

#endif // GAME_H
