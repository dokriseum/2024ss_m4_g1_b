#include "BoardTest.h"
#include "Board.h"
#include <gtest/gtest.h>

// Test the initialization of the board
TEST(BoardTest, Initialization) {
Board board;
EXPECT_EQ(board.getPiece(3, 3), 'W');
EXPECT_EQ(board.getPiece(3, 4), 'B');
EXPECT_EQ(board.getPiece(4, 3), 'B');
EXPECT_EQ(board.getPiece(4, 4), 'W');
}

// Test the display function (manual check required)
TEST(BoardTest, Display) {
Board board;
board.display();
SUCCEED(); // Display function output is manually checked
}

// Test if the board is full
TEST(BoardTest, IsFull) {
Board board;
EXPECT_FALSE(board.isFull());
for (int i = 0; i < 8; ++i) {
for (int j = 0; j < 8; ++j) {
board.setPiece(i, j, 'B');
}
}
EXPECT_TRUE(board.isFull());
}

// Test valid move
TEST(BoardTest, IsValidMove) {
Board board;
EXPECT_TRUE(board.isValidMove(2, 3, 'B', 'W'));
EXPECT_FALSE(board.isValidMove(0, 0, 'B', 'W'));
}

// Test make move
TEST(BoardTest, MakeMove) {
Board board;
board.makeMove(2, 3, 'B', 'W');
EXPECT_EQ(board.getPiece(3, 3), 'B');
}

// Test count pieces
TEST(BoardTest, CountPieces) {
Board board;
EXPECT_EQ(board.countPieces('B'), 2);
EXPECT_EQ(board.countPieces('W'), 2);
}
