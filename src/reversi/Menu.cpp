#include "Menu.h"

void Menu::display() const {
    cout << "1. Play Game Against Computer" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Exit" << endl;
}

void Menu::run() {
    GameManager game;
    int choice;

    while (true) {
        display();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            game.play();
            break;
        case 2:
        {
            string filename;
            cout << "Enter the filename to load the game: ";
            cin >> filename;
            game.loadGame(filename);
            game.play();
        }
        break;
        case 3:
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
