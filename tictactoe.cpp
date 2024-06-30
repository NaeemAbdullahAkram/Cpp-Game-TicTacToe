#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char current_player;

public:
    TicTacToe() {
        // Initialize the board with empty spaces
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        current_player = 'X';
    }

    void print_game_board() const {
        cout << "-------------" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "| ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << " | ";
            }
            cout << endl;
            cout << "-------------" << endl;
        }
    }

    bool make_move(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;  // Invalid move
        }
        board[row][col] = current_player;
        current_player = (current_player == 'X') ? 'O' : 'X';  // Switch player
        return true;
    }

    bool check_win() const {
        // Check rows
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }

        // Check columns
        for (int j = 0; j < 3; ++j) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }

        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }

        return false;
    }

    bool is_board_full() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    char get_current_player() const {
        return current_player;
    }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "Tic-Tac-Toe" << endl;

    while (!game.check_win() && !game.is_board_full()) {
        game.print_game_board();

        cout << "Player " << game.get_current_player() << ", enter your move (row and column): ";
        cin >> row >> col;

        if (!game.make_move(row, col)) {
            cout << "Invalid move. " << endl;
        }
    }

    game.print_game_board();

    if (game.check_win()) {
        cout << "Player " << game.get_current_player() << " has won!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}