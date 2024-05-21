

#ifndef INC_2024SS_M4_G1_B_FILEMANAGER_H
#define INC_2024SS_M4_G1_B_FILEMANAGER_H


#include <fstream>
#include <vector>
#include <string>

class Persistence {
private:
    std::string saveFilePath = "reversi_save.txt";
    std::string statsFilePath = "reversi_stats.txt";

public:
    void saveGame(const Board& board) {
        std::ofstream saveFile(saveFilePath);
        if (saveFile.is_open()) {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    saveFile << board.getStoneAt(i, j) << " ";
                }
                saveFile << std::endl;
            }
            saveFile.close();
            std::cout << "Game saved to " << saveFilePath << std::endl;
        } else {
            std::cerr << "Unable to open file for saving." << std::endl;
        }
    }

    void loadGame(Board& board) {
        std::ifstream loadFile(saveFilePath);
        if (loadFile.is_open()) {
            char stone;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    loadFile >> stone;
                    board.setStoneAt(i, j, stone);
                }
            }
            loadFile.close();
            std::cout << "Game loaded from " << saveFilePath << std::endl;
        } else {
            std::cerr << "Unable to open file for loading." << std::endl;
        }
    }

    void logStatistics(int blackWins, int whiteWins, int draws) {
        std::ofstream statsFile(statsFilePath, std::ofstream::app);
        if (statsFile.is_open()) {
            statsFile << "Black Wins: " << blackWins << ", White Wins: " << whiteWins << ", Draws: " << draws << std::endl;
            statsFile.close();
            std::cout << "Statistics updated." << std::endl;
        } else {
            std::cerr << "Unable to open file for statistics." << std::endl;
        }
    }



#endif //INC_2024SS_M4_G1_B_FILEMANAGER_H
