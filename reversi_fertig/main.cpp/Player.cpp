#include "Player.h"
#include "GameManager.h"
#include <iostream>
#include <cctype>

extern GameManager* gameManager; // Forward declaration of gameManager instance

Player::Player(char piece) : piece(piece) {}

char Player::getPiece() const {
    return piece;
}

HumanPlayer::HumanPlayer(char piece) : Player(piece) {}

void HumanPlayer::makeMove(Board& board) {
    std::string move;
    while (true) {
        std::cout << "Your turn. Enter your move (e.g., A1 or 's' to save the game, 'q' to quit): ";
        std::cin >> move;
        if (move == "s") {
            std::string filename;
            std::cout << "Enter the filename to save the game: ";
            std::cin >> filename;
            gameManager->saveGame(filename); // Use gameManager to save the game
            std::cout << "Game state saved to " << filename << std::endl;
            continue; // Ask for the next move after saving
        }
        else if (move == "q") {
            std::cout << "Returning to main menu..." << std::endl;
            exit(0); // Exit the game
        }
        else if (move.length() == 2 && isalpha(move[0]) && isdigit(move[1])) {
            int row = move[1] - '1';
            int col = toupper(move[0]) - 'A';
            if (board.isValidMove(row, col, piece, piece == 'B' ? 'W' : 'B')) {
                board.makeMove(row, col, piece, piece == 'B' ? 'W' : 'B');
                break;
            }
        }
        std::cout << "Invalid move! Please enter a valid move." << std::endl;
    }
}

ComputerPlayer::ComputerPlayer(char piece) : Player(piece) {}

void ComputerPlayer::makeMove(Board& board) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.isValidMove(i, j, piece, piece == 'B' ? 'W' : 'B')) {
                board.makeMove(i, j, piece, piece == 'B' ? 'W' : 'B');
                return;
            }
        }
    }
}
