#pragma once

#include "Board.h"
#include "Player.h"
#include <fstream>
#include <string>

class GameManager {
public:
    GameManager();
    void play();
    void saveGame(const std::string& filename);
    void loadGame(const std::string& filename);
    char getWinner() const;
    void printCurrentPlayer() const;

private:
    Board board;
    Player* player;
    Player* computer;
    char currentPlayer;
    char playerPiece;
    char cpuPiece;

    void switchPlayer();
    bool isGameOver() const;
    void chooseColor();
};
