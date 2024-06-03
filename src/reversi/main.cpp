#include "Menu.h"
#include <iostream>

/**
 * @brief Entry point for the Reversi game application.
 *
 * This function initializes the menu and runs it. If a test flag is provided, it runs the menu in test mode.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return int Exit status.
 */
int main(int argc, char* argv[]) {
    Menu menu;
    if (argc > 1 && std::string(argv[1]) == "--test") {
        menu.runTests();
    } else {
        menu.run();
    }
    return 0;
}
