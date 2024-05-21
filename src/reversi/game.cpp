//
// Created by bakir on 17.05.2024.
//
#include "game.h"

OthelloGame::OthelloGame() {
    board = vector<vector<char>>(8, vector<char>(8, ' '));
    board[3][3] = '1';
    board[3][4] = '2';
    board[4][3] = '2';
    board[4][4] = '1';
    currentPlayer = '1';
    player1Piece = '1';
    player2Piece = '2';
}

void OthelloGame::displayBoard() {
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
    }
    cout << "    A   B   C   D   E   F   G   H  " << endl;
}

void OthelloGame::switchPlayer() {
    currentPlayer = (currentPlayer == player1Piece) ? player2Piece : player1Piece;
}

bool OthelloGame::isValidMove(int row, int col) {
    if (row < 0 || row >= 8 || col < 0 || col >= 8 || board[row][col] != ' ') {
        return false;
    }
    char opponentPiece = (currentPlayer == player1Piece) ? player2Piece : player1Piece;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr, c = col + dc;
            bool hasOpponentPieceInBetween = false;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opponentPiece) {
                hasOpponentPieceInBetween = true;
                r += dr;
                c += dc;
            }
            if (hasOpponentPieceInBetween && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == currentPlayer) {
                return true;
            }
        }
    }
    return false;
}

void OthelloGame::makeMove(int row, int col) {
    if (!isValidMove(row, col)) {
        cout << "Invalid move! Please enter a valid move." << endl;
        return;
    }
    board[row][col] = currentPlayer;
    char opponentPiece = (currentPlayer == player1Piece) ? player2Piece : player1Piece;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr, c = col + dc;
            vector<pair<int, int>> positionsToFlip;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opponentPiece) {
                positionsToFlip.emplace_back(r, c);
                r += dr;
                c += dc;
            }
            if (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == currentPlayer) {
                for (const auto& pos : positionsToFlip) {
                    board[pos.first][pos.second] = currentPlayer;
                }
            }
        }
    }
    switchPlayer();
}

bool OthelloGame::isBoardFull() {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool OthelloGame::isGameOver() {
    if (!isBoardFull()) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (isValidMove(i, j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void OthelloGame::play() {
    cout << "Welcome to Othello Game!" << endl;
    displayBoard();
    while (!isGameOver()) {
        cout << "Current player: " << currentPlayer << endl;
        cout << "Enter your move (e.g., A1): ";
        string move;
        cin >> move;
        if (move.length() != 2 || !isalpha(move[0]) || !isdigit(move[1])) {
            cout << "Invalid move! Please enter a move in the format A1." << endl;
            continue;
        }
        int row = move[1] - '1';
        int col = toupper(move[0]) - 'A';
        makeMove(row, col);
        displayBoard();
    }
    cout << "Game over!" << endl;
}

