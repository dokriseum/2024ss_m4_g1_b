#include "GameManager.h"
#include <iostream>
#include <string>
#include <fstream>

GameManager* gameManager = nullptr; // Define the global gameManager instance

GameManager::GameManager() {
    gameManager = this; // Set the global instance to this
    currentPlayer = 'B';
    playerPiece = 'B';
    cpuPiece = 'W';
    player = new HumanPlayer(playerPiece);
    computer = new ComputerPlayer(cpuPiece);
}

void GameManager::switchPlayer() {
    currentPlayer = (currentPlayer == playerPiece) ? cpuPiece : playerPiece;
}

bool GameManager::isGameOver() const {
    if (!board.isFull()) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board.isValidMove(i, j, currentPlayer, currentPlayer == playerPiece ? cpuPiece : playerPiece)) {
                    return false;
                }
            }
        }
    }
    return true;
}

char GameManager::getWinner() const {
    int playerCount = board.countPieces(playerPiece);
    int cpuCount = board.countPieces(cpuPiece);
    if (playerCount > cpuCount) {
        return playerPiece;
    }
    else if (cpuCount > playerCount) {
        return cpuPiece;
    }
    else {
        return 'T'; // T for tie
    }
}

void GameManager::saveGame(const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                outFile << board.getPiece(i, j);
            }
            outFile << std::endl;
        }
        outFile << currentPlayer << std::endl;
        outFile << playerPiece << std::endl;
        outFile << cpuPiece << std::endl;
        outFile.close();
        std::cout << "Game state saved to " << filename << std::endl;
    }
    else {
        std::cout << "Unable to open file for saving." << std::endl;
    }
}

void GameManager::loadGame(const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;
        for (int i = 0; i < 8; ++i) {
            if (std::getline(inFile, line) && line.length() == 8) {
                for (int j = 0; j < 8; ++j) {
                    board.setPiece(i, j, line[j]);
                }
            }
            else {
                std::cout << "File format error in board data." << std::endl;
                inFile.close();
                return;
            }
        }
        if (std::getline(inFile, line) && line.length() == 1) {
            currentPlayer = line[0];
        }
        else {
            std::cout << "File format error in current player data." << std::endl;
            inFile.close();
            return;
        }
        if (std::getline(inFile, line) && line.length() == 1) {
            playerPiece = line[0];
        }
        else {
            std::cout << "File format error in player piece data." << std::endl;
            inFile.close();
            return;
        }
        if (std::getline(inFile, line) && line.length() == 1) {
            cpuPiece = line[0];
        }
        else {
            std::cout << "File format error in CPU piece data." << std::endl;
            inFile.close();
            return;
        }
        inFile.close();
        std::cout << "Game loaded from " << filename << std::endl;
    }
    else {
        std::cout << "Unable to open file for loading." << std::endl;
    }
}

void GameManager::chooseColor() {
    char choice;
    std::cout << "Choose your color (B for Black, W for White): ";
    std::cin >> choice;
    if (toupper(choice) == 'B') {
        playerPiece = 'B';
        cpuPiece = 'W';
        currentPlayer = playerPiece;
    }
    else {
        playerPiece = 'W';
        cpuPiece = 'B';
        currentPlayer = cpuPiece;
    }
    delete player;
    delete computer;
    player = new HumanPlayer(playerPiece);
    computer = new ComputerPlayer(cpuPiece);
}

void GameManager::printCurrentPlayer() const {
    if (currentPlayer == playerPiece) {
        std::cout << "It's your turn." << std::endl;
    }
    else {
        std::cout << "Computer's turn." << std::endl;
    }
}

void GameManager::play() {
    chooseColor();
    board.display();
    while (!isGameOver()) {
        printCurrentPlayer();  // Print whose turn it is
        if (currentPlayer == playerPiece) {
            player->makeMove(board);
        }
        else {
            computer->makeMove(board);
        }
        board.display();
        switchPlayer();
    }
    char winner = getWinner();
    if (winner == playerPiece) {
        std::cout << "You win!" << std::endl;
    }
    else if (winner == cpuPiece) {
        std::cout << "Computer wins!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }
}
