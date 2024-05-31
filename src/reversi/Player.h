/**
 * @file Player.h
 * @brief Defines the Player base class and its derived classes HumanPlayer and ComputerPlayer.
 *
 * This file contains the declarations and implementations of the Player,
 * HumanPlayer, and ComputerPlayer classes. These classes handle player
 * interactions, moves, and game logic execution based on player type.
 */

#pragma once

#include "Board.h"
#include <string>

/**
 * @class Player
 * @brief Abstract base class representing a player in the game.
 *
 * This class provides the interface and common functionalities for players in the game.
 */
class Player {
public:
    /**
     * @brief Constructs a Player object with a given piece.
     * @param piece Character representing the player's piece.
     */
    Player(char piece);

    /**
     * @brief Pure virtual function to make a move on the board.
     * @param board Reference to the Board object where the move will be made.
     */
    virtual void makeMove(Board& board) = 0;

    /**
     * @brief Gets the piece type of the player.
     * @return Character representing the player's piece.
     */
    char getPiece() const;

protected:
    char piece; ///< Character representing the player's piece type ('B' or 'W').
};

/**
 * @class HumanPlayer
 * @brief Represents a human player in the game.
 *
 * This class extends Player and implements interactive move making via the console.
 */
class HumanPlayer : public Player {
public:
    /**
     * @brief Constructs a HumanPlayer object with a given piece.
     * @param piece Character representing the human player's piece.
     */
    HumanPlayer(char piece);

    /**
     * @brief Implements making a move for a human player.
     * Allows saving the game, quitting, or making a valid move on the board.
     * @param board Reference to the Board object where the move will be made.
     */
    void makeMove(Board& board) override;
};

/**
 * @class ComputerPlayer
 * @brief Represents a computer-controlled player.
 *
 * This class extends Player and implements automated move making based on simple logic.
 */
class ComputerPlayer : public Player {
public:
    /**
     * @brief Constructs a ComputerPlayer object with a given piece.
     * @param piece Character representing the computer player's piece.
     */
    ComputerPlayer(char piece);

    /**
     * @brief Implements making a move for a computer player.
     * Finds the first valid move and executes it.
     * @param board Reference to the Board object where the move will be made.
     */
    void makeMove(Board& board) override;
};
