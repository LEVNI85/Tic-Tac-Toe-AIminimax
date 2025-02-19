#include "ai.h"

int AI::minimax(Game& game, bool is_max) {
    char winner = game.check_winner();

    if (winner == 'X') return -1; //Person wins
    if (winner == 'O') return 1;  //AI wins
    if (game.game_over()) return 0;  // Draw

    int best_score;

    if (is_max) best_score = -1000;
    else best_score = 1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.board[i][j] == ' ') {
                if (is_max) game.board[i][j] = 'O';
                else game.board[i][j] = 'X';

                int score = minimax(game, !is_max);
                game.board[i][j] = ' ';

                if (is_max) best_score = max(best_score, score);
                else best_score = min(best_score, score);
            }
        }
    }
    return best_score;
}

pair<int, int> AI::best_move(Game& game) {
    int best_score = -1000;
    pair<int, int> move = { -1,-1 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game.board[i][j] == ' ') {
                game.board[i][j] = 'O';
                int score = minimax(game, false);
                game.board[i][j] = ' ';

                if (score > best_score) {
                    best_score = score;
                    move = { i,j };
                }
            }
        }
    }
    return move;
}
