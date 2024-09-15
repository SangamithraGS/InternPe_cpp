#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3];  // 3x3 Tic Tac Toe board
char currentPlayer;  // 'X' or 'O'
bool isPlayingWithComputer;  // True if playing against the computer

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to switch player after each turn
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to get the player's move
void getPlayerMove() {
    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column: 1-3): ";
        cin >> row >> col;
        row--; col--;  // Adjusting for 0-based index

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

// Function to get the computer's move
void getComputerMove() {
    int row, col;
    srand(time(0));  // Seed for random number generator

    while (true) {
        row = rand() % 3;
        col = rand() % 3;

        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            cout << "Computer played at (" << row + 1 << ", " << col + 1 << ")\n";
            break;
        }
    }
}

// Function to check if the game is over
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
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

// Function to check if the board is full
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Main game function
void playGame() {
    initializeBoard();
    currentPlayer = 'X';  // X starts first
    bool gameOver = false;

    while (!gameOver) {
        displayBoard();

        if (currentPlayer == 'O' && isPlayingWithComputer) {
            getComputerMove();
        } else {
            getPlayerMove();
        }

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
}

// Main function
int main() {
    char choice;

    cout << "Do you want to play against the computer? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        isPlayingWithComputer = true;
    } else {
        isPlayingWithComputer = false;
    }

    playGame();

    return 0;
}
