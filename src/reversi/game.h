#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

/**
 * @class OthelloGame
 * @brief Manages the game logic for Othello.
 *
 * This class encapsulates all functionalities required to run an Othello game,
 * including board management, player switching, move validation, and the game flow control.
 */
class OthelloGame {
private:
    vector<vector<char>> board; ///< 2D vector representing the Othello game board.
    char currentPlayer;         ///< Character representing the current player (either '1' or '2').
    char player1Piece;          ///< Character representing Player 1's game pieces.
    char player2Piece;          ///< Character representing Player 2's game pieces.

public:
    /**
     * @brief Constructor that initializes the game board and sets the starting player.
     */
    OthelloGame();

    /**
     * @brief Displays the current state of the game board to the standard output.
     */
    void displayBoard();

    /**
     * @brief Switches the current player after a move is made.
     */
    void switchPlayer();

    /**
     * @brief Checks whether a move at a specified location is valid.
     *
     * @param row The row index where the piece is to be placed.
     * @param col The column index where the piece is to be placed.
     * @return true If the move is valid.
     * @return false If the move is invalid.
     */
    bool isValidMove(int row, int col);

    /**
     * @brief Places a piece on the board at the specified location if the move is valid and flips the opponent's pieces.
     *
     * @param row The row index where the piece is to be placed.
     * @param col The column index where the piece is to be placed.
     */
    void makeMove(int row, int col);

    /**
     * @brief Checks if the board is fully occupied with no empty spaces.
     *
     * @return true If there are no empty spaces left on the board.
     * @return false If there is at least one empty space on the board.
     */
    bool isBoardFull();

    /**
     * @brief Determines if the game is over, either when the board is full or no valid moves are possible.
     *
     * @return true If the game is over.
     * @return false If the game is not over and moves are still possible.
     */
    bool isGameOver();

    /**
     * @brief Runs the main game loop, processing player input and managing game state until the game is over.
     */
    void play();
};

#endif // GAME_H