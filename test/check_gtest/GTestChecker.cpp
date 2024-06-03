//
// Created by Dustin on 03.06.24.
//

#include "GTestChecker.h"
#include <gtest/gtest.h>

// Ein einfacher Testfall
TEST(SampleTest, AssertionTrue) {
EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
