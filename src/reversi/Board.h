#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

using namespace std;

class Board {
private:
    vector<vector<char> > board; // Korrigierte Syntax

public:
    Board();
    void display() const;
    bool isFull() const;
    bool isValidMove(int row, int col, char currentPlayer, char opponentPiece) const;
    void makeMove(int row, int col, char currentPlayer, char opponentPiece);
    char getPiece(int row, int col) const;
    void setPiece(int row, int col, char piece);
    int countPieces(char piece) const;
};

#endif // BOARD_H
