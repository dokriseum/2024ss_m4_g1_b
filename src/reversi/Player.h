#pragma once

#include "Board.h"
#include <string>

class Player {
public:
    Player(char piece);
    virtual void makeMove(Board& board) = 0;
    char getPiece() const;

protected:
    char piece;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(char piece);
    void makeMove(Board& board) override;
};

class ComputerPlayer : public Player {
public:
    ComputerPlayer(char piece);
    void makeMove(Board& board) override;
};
