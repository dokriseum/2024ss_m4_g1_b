/**
 * @file Board.h
 * @brief Defines the Board class for a Reversi game.
 *
 * This file contains the declarations of the Board class, which manages the game board,
 * including piece placement, move validation, and displaying the board.
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * @class Board
 * @brief Manages the game board for Reversi, including piece placement and move validation.
 *
 * This class encapsulates the game board, providing functionalities to initialise the board,
 * display its current state, check for fullness, validate and make moves, and count pieces of each player.
 */
class Board {
private:
    vector<vector<char> > board; ///< 2D vector representing the game board.

public:
    /**
     * @brief Constructs a new Board and initialises it with the starting position of pieces.
     */
    Board();

    /**
     * @brief Displays the current state of the board to the console.
     *
     * Shows the board with row and column labels, using '.' to represent empty spaces.
     */
    void display() const;

    /**
     * @brief Checks if the board is fully occupied with pieces.
     *
     * @return true if the board is full, false otherwise.
     */
    bool isFull() const;

    /**
     * @brief Validates if a move by the current player at the specified location is legal.
     *
     * @param row The row index of the move.
     * @param col The column index of the move.
     * @param currentPlayer The character representing the current player's pieces.
     * @param opponentPiece The character representing the opponent's pieces.
     * @return true if the move is valid, false otherwise.
     */
    bool isValidMove(int row, int col, char currentPlayer, char opponentPiece) const;

    /**
     * @brief Executes a move at the specified location, flipping opponent's pieces as necessary.
     *
     * @param row The row index where the piece is placed.
     * @param col The column index where the piece is placed.
     * @param currentPlayer The character representing the current player's pieces.
     * @param opponentPiece The character representing the opponent's pieces.
     */
    void makeMove(int row, int col, char currentPlayer, char opponentPiece);

    /**
     * @brief Gets the piece at the specified board location.
     *
     * @param row The row index to check.
     * @param col The column index to check.
     * @return char The character at the specified location.
     */
    char getPiece(int row, int col) const;

    /**
     * @brief Sets a piece at the specified board location.
     *
     * @param row The row index to set the piece.
     * @param col The column index to set the piece.
     * @param piece The character representing the piece to set.
     */
    void setPiece(int row, int col, char piece);

    /**
     * @brief Counts the number of pieces of a specific type on the board.
     *
     * @param piece The character representing the type of piece to count.
     * @return int The count of pieces of the specified type.
     */
    int countPieces(char piece) const;
};

#endif // BOARD_H
