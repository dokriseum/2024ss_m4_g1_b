/**
 * @file GameManager.h
 * @brief Definition of the GameManager class that manages the gameplay for Reversi.
 *
 * This file contains the declaration of the GameManager class, which is responsible for starting,
 * saving, loading, and managing the Reversi game.
 */

#pragma once

#include "Board.h"
#include "Player.h"
#include <fstream>
#include <string>

/**
 * @class GameManager
 * @brief Manages the game control and flow for Reversi.
 *
 * The GameManager class controls the game flow, interacts with players,
 * manages the game board, and maintains the game state.
 */
class GameManager {
public:
    /**
     * @brief Constructor that handles game initialisation.
     *
     * Initialises the game, sets the players, and the current player's piece.
     */
    GameManager();

    /**
     * @brief Destructor to clean up dynamically allocated memory.
     */
    ~GameManager();

    /**
     * @brief Starts and runs the main game loop.
     *
     * Manages turns, displays the board, checks game over conditions,
     * and declares the winner.
     */
    void play();

    /**
     * @brief Saves the current game state to a file.
     *
     * @param filename The name of the file to save the game state.
     */
    void saveGame(const std::string& filename);

    /**
     * @brief Loads the game state from a file.
     *
     * @param filename The name of the file from which to load the game state.
     */
    void loadGame(const std::string& filename);

    /**
     * @brief Determines the winner of the game based on the piece counts.
     *
     * @return The character representing the winner ('B' or 'W') or 'T' for a tie.
     */
    char getWinner() const;

    /**
     * @brief Prints which player's turn it is.
     */
    void printCurrentPlayer() const;

private:
    Board board; ///< The game board representing the current state of the game.
    Player* player; ///< Pointer to the human player.
    Player* computer; ///< Pointer to the computer player.
    char currentPlayer; ///< Character representing the current player ('B' or 'W').
    char playerPiece; ///< Character representing the human player's piece ('B' or 'W').
    char cpuPiece; ///< Character representing the computer player's piece ('B' or 'W').

    /**
     * @brief Switches the current player.
     */
    void switchPlayer();

    /**
     * @brief Checks if the game is over.
     *
     * The game is over if the board is full or no valid moves are possible.
     * @return true if the game is over, otherwise false.
     */
    bool isGameOver() const;

    /**
     * @brief Allows the human player to choose their piece colour.
     *
     * The computer player automatically gets the other colour.
     */
    void chooseColour();
};
