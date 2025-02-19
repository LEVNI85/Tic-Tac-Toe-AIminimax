#include "game.h"
#include <algorithm>

Game::Game() {
    board = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
}

void Game::print_board() {
    cout << "  0 1 2 " << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|";
            else cout << endl;
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-" << endl;
    }
}

bool Game::make_move(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Game::game_over() {
    return check_winner() != ' ' || none_of(board.begin(), board.end(),
        [](vector<char>& row) { return find(row.begin(), row.end(), ' ') != row.end(); });
}

char Game::check_winner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i];
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    return ' ';
}
