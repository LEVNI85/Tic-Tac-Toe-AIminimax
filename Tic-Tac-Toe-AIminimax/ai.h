#ifndef AI_H
#define AI_H
using namespace std;
#include "game.h"

class AI {
public:
    pair<int, int> best_move(Game& game);

private:
    int minimax(Game& game, bool isMaximizing);
};

#endif
