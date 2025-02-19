#include "game.h"
#include "ai.h"

int main() {
    Game game;
    AI ai;
    char player = 'X';

    while (!game.game_over()) {
        game.print_board();

        if (player == 'X') {
            int row, col;
            cout << "Enter row and column (0-2): ";
            cin >> row >> col;

            if (!game.make_move(row, col, player)) {
                cout << "Invalid move.Try again!" << endl;
                continue;
            }
        }
        else {
            pair<int, int> move = ai.best_move(game);
            game.make_move(move.first, move.second, player);
        }

        if (player == 'X') player = 'O';
        else player = 'X';
    }
    cout << endl;
    game.print_board();
    char winner = game.check_winner();
    if (winner == 'X' || winner == 'O') cout << "Winner: " << winner << "!" << endl;
    else cout << "It's a draw!" << endl;

    cout << "Do you want to play again? (Y/N)" << endl;
    char k;
    cin >> k;
    if (k == 'Y') main();
    else return 0;
}
