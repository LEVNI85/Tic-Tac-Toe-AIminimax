#ifndef GAME_H
#define GAME_H
using namespace std;
#include <iostream>
#include <vector>

class Game {
public:
    Game();
    void print_board();
    bool make_move(int row, int col, char player);
    bool game_over();
    char check_winner();

    vector<vector<char>> board;
};

#endif
