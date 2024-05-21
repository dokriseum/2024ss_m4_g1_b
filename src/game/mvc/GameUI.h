

#ifndef INC_2024SS_M4_G1_B_GAMEUI_H
#define INC_2024SS_M4_G1_B_GAMEUI_H


#include <iostream>

class GameUI {
public:
    void displayBoard(const Board& board) const {
        std::cout << "  ";
        for (int i = 0; i < 8; ++i) {
            std::cout << i << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < 8; ++i) {
            std::cout << i << " ";
            for (int j = 0; j < 8; ++j) {
                std::cout << board.getStoneAt(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

    void promptMove(char playerColor, int& x, int& y) {
        std::cout << "Player " << playerColor << ", enter your move (row col): ";
        std::cin >> x >> y;
    }

    void displayError(const std::string& message) {
        std::cout << "Error: " << message << std::endl;
    }

    void showEndGameResults(int blackScore, int whiteScore) {
        std::cout << "Game over!" << std::endl;
        std::cout << "Score - Black: " << blackScore << ", White: " << whiteScore << std::endl;
        if (blackScore > whiteScore) {
            std::cout << "Black wins!" << std::endl;
        } else if (whiteScore > blackScore) {
            std::cout << "White wins!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }
    }

    void updateBoardDisplay() {
        std::cout << "Board updated." << std::endl;
    }

    void promptNextMove() {
        std::cout << "Next player, make your move." << std::endl;
    }
};



#endif //INC_2024SS_M4_G1_B_GAMEUI_H
