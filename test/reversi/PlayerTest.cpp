#include "PlayerTest.h"
#include "Player.h"
#include <gtest/gtest.h>

// Test the HumanPlayer initialization
TEST(PlayerTest, HumanPlayerInitialization) {
HumanPlayer player('B');
EXPECT_EQ(player.getPiece(), 'B');
}

// Test the ComputerPlayer initialization
TEST(PlayerTest, ComputerPlayerInitialization) {
ComputerPlayer player('W');
EXPECT_EQ(player.getPiece(), 'W');
}