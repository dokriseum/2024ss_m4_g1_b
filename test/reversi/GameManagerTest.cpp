#include <gtest/gtest.h>
#include "GameManager.h"

TEST(GameManagerTest, SwitchPlayer) {
    GameManager game;
    game.switchPlayer();
    EXPECT_EQ(game.getCurrentPlayer(), 'W');
}

TEST(GameManagerTest, IsGameOver) {
    GameManager game;
    EXPECT_FALSE(game.isGameOver());
    // Fill the board with pieces to simulate game over condition
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            game.getBoard().setPiece(i, j, 'B');
        }
    }
    EXPECT_TRUE(game.isGameOver());
}
