#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';
const char EMPTY_SLOT = '.';

// Initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY_SLOT;
        }
    }
}

// Print the game board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Check if a move is valid
bool isValidMove(const vector<vector<char>>& board, int col) {
    return col >= 0 && col < COLS && board[0][col] == EMPTY_SLOT;
}

// Drop a disc into the selected column
bool dropDisc(vector<vector<char>>& board, int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == EMPTY_SLOT) {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

// Check for a win (horizontally, vertically, or diagonally)
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check horizontal
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }
    // Check vertical
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }
    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
            }
        }
    }
    return false;
}

// Check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (int j = 0; j < COLS; j++) {
        if (board[0][j] == EMPTY_SLOT) {
            return false;
        }
    }
    return true;
}

// Computer makes a random move
int getComputerMove(const vector<vector<char>>& board) {
    int col;
    do {
        col = rand() % COLS;
    } while (!isValidMove(board, col));
    return col;
}

// Main game loop
void playGame(bool vsComputer) {
    vector<vector<char>> board(ROWS, vector<char>(COLS, EMPTY_SLOT));
    char currentPlayer = PLAYER_ONE;
    bool gameWon = false;

    while (!gameWon && !isBoardFull(board)) {
        printBoard(board);
        int col;

        if (currentPlayer == PLAYER_ONE || !vsComputer) {
            // Human player turn
            cout << "Player " << currentPlayer << ", enter column (0-" << COLS - 1 << ") to drop your disc: ";
            cin >> col;

            while (!isValidMove(board, col)) {
                cout << "Invalid move! Try again: ";
                cin >> col;
            }
        } else {
            // Computer turn
            col = getComputerMove(board);
            cout << "Computer drops disc in column " << col << endl;
        }

        dropDisc(board, col, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            gameWon = true;
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else {
            currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
        }
    }

    if (!gameWon) {
        printBoard(board);
        cout << "It's a draw!" << endl;
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    int mode;
    cout << "Choose game mode: 1 for Human vs Human, 2 for Human vs Computer: ";
    cin >> mode;

    if (mode == 1) {
        playGame(false); // Human vs Human
    } else if (mode == 2) {
        playGame(true); // Human vs Computer
    } else {
        cout << "Invalid mode selected!" << endl;
    }

    return 0;
}

