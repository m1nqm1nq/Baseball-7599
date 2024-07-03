#include <stdexcept>

using namespace std;

#include "pch.h"
#include "../Baseball/Baseball.cpp"

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmatched)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, ThrowExceptionWhenInvalidChar)
{
    Baseball game;
    EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}