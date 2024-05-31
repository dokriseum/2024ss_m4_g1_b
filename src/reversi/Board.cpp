#include "Board.h"

Board::Board() {
    board = std::vector<std::vector<char> >(8, std::vector<char>(8, ' '));
    board[3][3] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';
    board[4][4] = 'W';
}

void Board::display() const {
    std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << " | ";
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == ' ') {
                std::cout << '.' << " | "; // Leere Felder mit Punkten anzeigen
            } else {
                std::cout << board[i][j] << " | ";
            }
        }
        std::cout << std::endl << "  +---+---+---+---+---+---+---+---+" << std::endl;
    }
    std::cout << "    A   B   C   D   E   F   G   H  " << std::endl;
}

bool Board::isFull() const {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool Board::isValidMove(int row, int col, char currentPlayer, char opponentPiece) const {
    if (row < 0 || row >= 8 || col < 0 || col >= 8 || board[row][col] != ' ') {
        return false;
    }

    bool valid = false;
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
                valid = true;
            }
        }
    }
    return valid;
}

void Board::makeMove(int row, int col, char currentPlayer, char opponentPiece) {
    board[row][col] = currentPlayer;

    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int r = row + dr, c = col + dc;
            std::vector<std::pair<int, int> > positionsToFlip;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opponentPiece) {
                positionsToFlip.emplace_back(r, c);
                r += dr;
                c += dc;
            }
            if (!positionsToFlip.empty() && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == currentPlayer) {
                for (const auto& pos : positionsToFlip) {
                    board[pos.first][pos.second] = currentPlayer;
                }
            }
        }
    }
}

char Board::getPiece(int row, int col) const {
    return board[row][col];
}

void Board::setPiece(int row, int col, char piece) {
    board[row][col] = piece;
}

int Board::countPieces(char piece) const {
    int count = 0;
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == piece) {
                count++;
            }
        }
    }
    return count;
}
