#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(SIZE, vector<char>(SIZE, ' ')), currentPlayer('X') {}

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << " " << board[i][j] << " ";
                if (j < SIZE - 1) cout << "|";
            }
            cout << "\n";
            if (i < SIZE - 1) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < SIZE; i++) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
            return true;
        }
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void playGame() {
        while (true) {
            printBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

