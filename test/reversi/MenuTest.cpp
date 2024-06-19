#include "MenuTest.h"
#include "Menu.h"
#include <gtest/gtest.h>

// Test the display function (manual check required)
TEST(MenuTest, Display) {
Menu menu;
menu.display();
SUCCEED(); // Display function output is manually checked
}