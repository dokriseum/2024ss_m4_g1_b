

#ifndef INC_2024SS_M4_G1_B_BOARD_H
#define INC_2024SS_M4_G1_B_BOARD_H


#include <vector>

class Board {
private:
    char grid[8][8];

public:
    Board() {
        // Initialize the board with empty spaces and the initial four stones
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                grid[i][j] = '.';
            }
        }
        grid[3][3] = grid[4][4] = 'W';
        grid[3][4] = grid[4][3] = 'B';
    }

    bool isFull() const {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (grid[i][j] == '.') return false;
            }
        }
        return true;
    }

    bool hasValidMoves(char playerColor) const {
        // Logic to determine if there are any valid moves left for the player
        return true; // Placeholder
    }

    bool isValidMove(int x, int y, char playerColor) {
        // Implement rules to check for valid moves
        return true; // Placeholder
    }

    void placeStone(int x, int y, char playerColor) {
        grid[x][y] = playerColor;
        // Additional logic to flip opponent's stones
    }

    int calculateScore(char playerColor) {
        int score = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (grid[i][j] == playerColor) score++;
            }
        }
        return score;
    }
};



#endif //INC_2024SS_M4_G1_B_BOARD_H
