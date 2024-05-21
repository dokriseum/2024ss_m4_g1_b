

#ifndef INC_2024SS_M4_G1_B_GAME_H
#define INC_2024SS_M4_G1_B_GAME_H


#include <iostream>
#include "Board.h"
#include "Player.h"
#include "GameUI.h"
#include "Persistence.h"

class Game {
private:
    Board board;
    Player* players[2]; // Array to hold two types of players: Human and AI
    GameUI ui;
    FileManager fileManager;
    int currentPlayerIndex;

public:
    Game() {
        // Initializing players might depend on user choice or saved game state
        players[0] = new HumanPlayer('B'); // Black player
        players[1] = new AIPlayer('W'); // White player
        currentPlayerIndex = 0; // Black starts first
    }

    ~Game() {
        delete players[0];
        delete players[1];
    }

    void start() {
        while (!board.isFull() && board.hasValidMoves(players[currentPlayerIndex]->getColor())) {
            ui.displayBoard(board);
            int x, y;
            do {
                ui.promptMove(players[currentPlayerIndex]->getColor(), x, y);
            } while (!board.isValidMove(x, y, players[currentPlayerIndex]->getColor()));

            board.placeStone(x, y, players[currentPlayerIndex]->getColor());
            currentPlayerIndex = (currentPlayerIndex + 1) % 2; // Switch player
            ui.updateBoardDisplay();
        }

        ui.showEndGameResults(board.calculateScore('B'), board.calculateScore('W'));
    }
};



#endif //INC_2024SS_M4_G1_B_GAME_H
