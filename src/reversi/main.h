/**
 * @file Menu.h
 * @brief Defines the Menu class for displaying and running the game menu.
 *
 * This file contains the declarations of the Menu class, which manages the
 * display and interaction of the game menu for the Reversi game.
 */

#pragma once

#include "GameManager.h"

/**
 * @class Menu
 * @brief Manages the game menu display and user interaction.
 *
 * This class provides functionalities to display the game menu options and
 * handle user input to start a new game, load an existing game, or exit the application.
 */
class Menu {
public:
    /**
     * @brief Displays the main menu options to the user.
     *
     * This function outputs the main options available in the game menu to the console,
     * including starting a new game, loading a game, and exiting the application.
     */
    void display() const;

    /**
     * @brief Runs the main interaction loop for the menu.
     *
     * This function continuously displays the menu options, accepts user input, and
     * reacts to the input by either starting a new game, loading an existing game,
     * or exiting the programme. Invalid inputs will prompt the user to try again.
     */
    void run();
};
