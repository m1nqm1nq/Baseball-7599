#include <stdexcept>

using namespace std;

#include "pch.h"
#include "../Baseball/Baseball.cpp"

class BaseballTestFixture : public testing::Test
{
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber)
    {
        try
        {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e)
        {
            // PASS
        }
    }
};

TEST_F(BaseballTestFixture, ThrowExceptionWhenInvalidCase)
{
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("121");
}

TEST_F(BaseballTestFixture, ReturnSolvedREsultIfMatchedNumber)
{
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(result.strikes, 3);
    EXPECT_EQ(result.balls, 0);
}