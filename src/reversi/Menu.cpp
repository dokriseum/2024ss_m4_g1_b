#include "Menu.h"
#include <iostream>
#include <string>

void Menu::display() const {
    std::cout << "1. Play Game Against Computer" << std::endl;
    std::cout << "2. Load Game" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void Menu::run() {
    GameManager game;
    int choice;

    while (true) {
        display();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                game.play();
                break;
            case 2:
            {
                std::string filename;
                std::cout << "Enter the filename to load the game: ";
                std::cin >> filename;
                game.loadGame(filename);
                game.play();
            }
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void Menu::runTests() {
    GameManager game;
    game.play();  // Directly start the game in test mode
}
