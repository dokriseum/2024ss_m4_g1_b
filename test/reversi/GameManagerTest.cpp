//
// Created by Dustin on 03.06.24.
//

#include "GameManagerTest.h"
#include "GameManager.h"
#include <gtest/gtest.h>

// Test the initialization of the GameManager
TEST(GameManagerTest, Initialization) {
GameManager game;
EXPECT_EQ(game.getWinner(), 'T'); // Initially, it should be a tie
}

// Test the switch player functionality
TEST(GameManagerTest, SwitchPlayer) {
GameManager game;
game.switchPlayer();
game.printCurrentPlayer();
SUCCEED(); // Just for demonstration
}

// Test if the game is over
TEST(GameManagerTest, IsGameOver) {
GameManager game;
EXPECT_FALSE(game.isGameOver());
for (int i = 0; i < 8; ++i) {
for (int j = 0; j < 8; ++j) {
game.getBoard().setPiece(i, j, 'B');
}
}
EXPECT_TRUE(game.isGameOver());
}
