//
// Created by bakir on 17.05.2024.
//

#ifndef OTHELLOGAME_H
#define OTHELLOGAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

/**
 * @class OthelloGame
 * @brief Manages the game logic for Othello.
 *
 * This class encapsulates all functionalities for running an Othello game,
 * including board management, player switching, move validation, and gameplay flow.
 */
class OthelloGame {
private:
    vector<vector<char>> board; ///< 2D board array holding player pieces.
    char currentPlayer;         ///< Tracks the current player, '1' or '2'.
    char player1Piece;          ///< Character representing Player 1's pieces.
    char player2Piece;          ///< Character representing Player 2's pieces.

public:
    /**
     * @brief Constructs a new Othello Game object and initializes the board.
     *
     * Sets up an 8x8 board with the initial four pieces placed in the center.
     * Sets the current player to Player 1.
     */
    OthelloGame();

    /**
     * @brief Displays the current state of the board.
     *
     * Outputs the board to standard output, with row and column labels.
     */
    void displayBoard();

    /**
     * @brief Switches the active player.
     *
     * Changes the currentPlayer from Player 1 to Player 2 or vice versa.
     */
    void switchPlayer();

    /**
     * @brief Determines if a move is valid.
     *
     * Checks if placing a piece at the specified row and column is valid according to Othello rules.
     * @param row The row index where the piece is to be placed.
     * @param col The column index where the piece is to be placed.
     * @return true if the move is valid, false otherwise.
     */
    bool isValidMove(int row, int col);

    /**
     * @brief Executes a move.
     *
     * Places a piece at the specified row and column, flips opponent's pieces accordingly, and switches the player.
     * @param row The row index where the piece is to be placed.
     * @param col The column index where the piece is to be placed.
     */
    void makeMove(int row, int col);

    /**
     * @brief Checks if the board is completely filled with pieces.
     *
     * @return true if there are no empty spaces left on the board, false otherwise.
     */
    bool isBoardFull();

    /**
     * @brief Determines if the game is over.
     *
     * The game is over either when the board is full or when no valid moves are available for either player.
     * @return true if the game is over, false otherwise.
     */
    bool isGameOver();

    /**
     * @brief Starts and manages the game loop.
     *
     * Continuously prompts the current player to make a move until the game is over.
     */
    void play();
};

#endif // OTHELLOGAME_H
