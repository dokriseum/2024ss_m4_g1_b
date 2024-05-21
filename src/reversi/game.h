//
// Created by bakir on 17.05.2024.
//

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class OthelloGame {
private:
    vector<vector<char>> board;
    char currentPlayer;
    char player1Piece;
    char player2Piece;

public:
    OthelloGame();
    void displayBoard();
    void switchPlayer();
    bool isValidMove(int row, int col);
    void makeMove(int row, int col);
    bool isBoardFull();
    bool isGameOver();
    void play();
};

#endif // GAME_H




