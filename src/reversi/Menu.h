/**
 * @file Menu.h
 * @brief Definition of the Menu class that displays and runs the main menu for Reversi.
 *
 * This file contains the declaration of the Menu class, which is responsible for displaying the
 * menu and handling user interactions to start, load, and exit the game.
 */

#pragma once

#include "GameManager.h"

/**
 * @class Menu
 * @brief Displays and runs the main menu for the game.
 *
 * The Menu class presents the main menu to the user, allowing them to start a new game, load an existing game,
 * or exit the program. It also provides a test mode to run the game without user interaction.
 */
class Menu {
public:
    /**
     * @brief Displays the main menu options.
     */
    void display() const;

    /**
     * @brief Runs the main menu loop, allowing the user to make selections.
     */
    void run();

    /**
     * @brief Runs the main menu loop in test mode, bypassing user input.
     */
    void runTests();
};
